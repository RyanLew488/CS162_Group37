/*********************************************************************
** Program name: board.cpp
** Assignment: Group Project
** Author: David Coons - group 37
** Date: May 1, 2018
** 
** What this class does: 
** Coordinates are all (row, col)
**
** Graph below:
** # is at (1, 2)
** * is at (2, 6)
**
**     0 1 2 3 4 5 6 ...
**   - - - - - - - - -
** 0 | 
** 1 |     #
** 2 |             *
** 3 | 
** 4 |           
** 5 |
** 6 |  
**
** 
** Dependencies:
** board.hpp
** critter.hpp
**
*********************************************************************/

#include "board.hpp"
#include "critter.hpp"
#include "doodlebug.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

// *****======PUBLIC=====*****

// Constructor
Board::Board()
{
    // seed rand
    std::srand(std::time(nullptr));
}

// Destructor
Board::~Board()
{
    deleteBoardState();
}

// Used to run the predator-prey game
void Board::runGame()
{
    std::cout << "*****=====GROUP 37 - PREDATOR/PREY PROJECT - W/ EXTRA CREDIT=====*****" << std::endl;

    Menu mainMenu("***PLAY GAME - MAIN MENU***");
    mainMenu.add("Quit");
    mainMenu.add("Play new game");

    int flagQuit1 = 0;

    while (!flagQuit1)
    {
        switch (mainMenu.run)
        {
            case 1:
                flagQuit1 = 1;
                break;
            case 2:
                newGame();
                break;
        }
    }

    // To "extend" the current game
    Menu extendGameMenu("***CONTINUE GAME?***");
    extendGameMenu.add("Quit");
    extendGameMenu.add("Extend current game");

    int flagQuit2 = 0;

    while (!flagQuit1 && !flagQuit2)
    {
        switch (extendGameMenu.run)
        {
            case 1:
                flagQuit2 = 1;
                break;
            case 2:
                extendedGame();
                break;
        }
    }
}



// *****======PRIVATE=====*****

// Handles user input for parameters related to setting
// up the game for the first time
void Board::newGame()
{
    // #days
    do
    {
        std::cout << "\n# days to run game: ";
    } while (!getValidInput(&dayLimit, 0, MAX_DAYS));


    // Board size
    do
    {
        std::cout << "\n# of rows: ";
    } while (!getValidInput(&sizeRow, 1, MAX_ROW));

    do
    {
        std::cout << "\n# of cols: ";
    } while (!getValidInput(&sizeCol, 1, MAX_COL));

    // make board
    makeBoardState();


    // #ants
    int numAnts;

    // # ants can't exceed # squares on board
    int maxAnts = rows * cols;
    do
    {
        std::cout << "\n# of Ants to start: ";
    } while (!getValidInput(&numAnts, 0, maxAnts));
    
    // #dbs
    int numDoodlebugs;

    // # DBs can't exceed # of remaining open squares
    int maxDoodlebugs = rows * cols - numAnts;
    do
    {
        std::cout << "\n# of Doodlebugs to start: ";
    } while (!getValidInput(&numDoodlebugs, 0, maxDoodlebugs));

    // Place ants and dbs on board
    setInitLocs(numAnts, numDoodlebugs);

    // Run a normal game
    runNormalGame();
}


// Handles user input for parameters related to extending the current
// game
void Board::extendedGame()
{
    int numMoreDays;

    // #days
    do
    {
        std::cout << "\n# MORE days to run game: ";
    } while (!getValidInput(&numMoreDays, 0, MAX_DAYS - getDayCounter()));

    dayLimit += numMoreDays;

    runNormalGame();
}


// Executes the game
void Board::runNormalGame()
{
    // Loop until dayCounter >= num days set by user
    while (getDayCounter() <= dayLimit)
    {
        // Order of events not finalized
        moveCritters(ANT_ID);
        moveCritters(DB_ID);
        breedCritters(ANT_ID);
        breedCritters(DB_ID);
        starveDoodlebugs();

        std::cout << "*****Board state at end of day " << getDayCounter()
            << "*****" << std::endl;
        printBoard();

        incDay();
    }

}

// Get the address of the Critter at a square (row, col)
// returns an int to indicate success
//      0 - given coords invalid (outside board)
//      1 - given coords valid (inside board)
int Board::getSquareState(Critter** critterHolder, int inRow, int inCol)
{
    // If coords valid (inside board)
    bool rowValid = (inRow >= 0) && (inRow < getSizeRow());
    bool colValid = (inCol >= 0) && (inCol < getSizeCol());

    if (rowValid && colValid)
    {
        // Pass along the address to the Critter at (inRow, inCol)
        *critterHolder = boardState[inRow][inCol];
        
        // Communicate that coords were valid
        return 1;
    }
    else
    {
        // Communicate that coords were invalid
        // (outside of board bounds)
        return 0;
    }
}


// Deletes boardState by deleting all objects' memory, and then deleting
// the array
void Board::deleteBoardState()
{
    Critter* tempCritter;

    // Iterate through rows
    for (int row = 0; row < getSizeRow(); row++)
    {
        // Iterate through cols, deleting all objects in the row
        for (int col = 0; col < getSizeCol(); col++)
        {
            // Point tempCritter to the object at (row, col)
            getSquareState(&tempCritter, row, col);

            delete tempCritter;
            boardState[row][col] = NULL;
        }

        // Delete the row array
        delete[] boardState[row];
        boardState[row] = NULL;
    }

    // Delete the board array
    delete[] boardState;
    boardState = NULL;
}

// Creates the board array, using current sizes for row and col
void Board::makeBoardState()
{
    rows = getSizeRow();
    cols = getSizeCol();

    // Make board state with right dimensions
    boardState = new Critter**[rows];
    for (int i = 0; i < rows; i++)
    {
        boardState[i] = new Critter*[cols];
    }

    // Initialize critter pointers to NULL
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            boardState[i][j] = NULL;
        }
    }
}


// Initializes the locations of all ants and doodlebugs
// **ASSUMES** numAnts + numDoodlebugs < sizeRow * sizeCol
void Board::setInitLocs(int numAnts, int numDoodlebugs)
{
    placeRandLocCritters(ANT_ID, numAnts);
    placeRandLocCritters(DB_ID, numDoodlebugs);
}

// Helps setInitLocs function
void Board::placeRandLocCritters(int speciesID, int numCritters)
{
    int currentDay = getDayCounter();
    int flagSuccess = 0;
    int spawnRow;
    int spawnCol;
    Critter* tempCritter;

    // loop for numCritters times
    for (int i = 0; i < numCritters; i++)
    {
        // loop until Ant is successfully placed
        while (!flagSuccess)
        {
            // get rand generated (row, col)
            spawnRow = rand() % getSizeRow();
            spawnCol = rand() % getSizeCol();

            getSquareState(&tempCritter, spawnRow, spawnCol);

            // If square is empty
            if (tempCritter == NULL)
            {
                addCritter(speciesID, spawnRow, spawnCol);
                flagSuccess = 1;
            }
        }
        
        flagSuccess = 0;
    }
}

// Print the current board state to the terminal
void Board::printBoard()
{
    Critter* tempCritter;
        // could use a flag to check if out of bounds, but
        // decided not to use (assumes below loops will never try
        // to access outside of the board)

    // Print horizontal border
    for (int x = 0; x < getSizeCol(); j++)
    {
        std::cout << '-';
    }

    std::cout << std::endl;

    // Iterate through rows
    for (int i = 0; i < getSizeRow(); i++)
    {
        // Iterate through cols
        for (int j = 0; j < getSizeCol(); j++)
        {
            // Print vertical border
            std::cout << '|';

            // Point tempCritter to the object at (row, col)
            getSquareState(&tempCritter, i, j);

            // if tempCritter is null
            if (tempCritter == NULL)
            {
                // print char for an empty square
                std::cout << CHAR_EMPTY;
            }
            else
            {
                // Critter::print() prints char to std::cout
                tempCritter->print();
            }

            // Print vertical border
            std::cout << '|' << std::endl;
        }
    }
    
    // Print horizontal border
    for (int x = 0; x < getSizeCol(); j++)
    {
        std::cout << "-";
    }

    std::cout << std::endl;
}

// Move all ants OR dbs on the board (see Board::ANT_ID/Board::DB_ID)
// 
// Critter::move(int* passCoords, int currentRow, int currentCol) will 
//     modify passCoords array
//     according to critter's internal move logic
//     passCoords MUST be inside of board
// passCoords[0] = newRow
// passCoords[1] = newCol
void Board::moveCritters(int speciesID)
{
    Critter* tempCritter;
        // could use a flag to check if out of bounds, but
        // decided not to use (assumes below loops will never try
        // to access outside of the board)

    // Coords will be {row, col}
    int newCoords [2];

    // Iterate through rows
    for (int oldRow = 0; oldRow < getSizeRow(); oldRow++)
    {
        // Iterate through cols
        for (int oldCol = 0; oldCol < getSizeCol(); oldCol++)
        {
            // Point tempCritter to the object at (oldRow, oldCol)
            getSquareState(&tempCritter, oldRow, oldCol);

            // if tempCritter->getSpecies() == speciesID
            if (tempCritter->getSpecies() == speciesID)
            {
                // get new coordinates of object
                // Gives the Critter newCoords to pass back desired new coords
                // Also gives Critter its current location on the board
                //
                // Ant will ignore getDayCounter, but DB will use it to keep
                // track of the last time it ate
                tempCritter->move(getDayCounter(), newCoords, oldRow, oldCol);

                // Check that new coords != old coords
                if (newCoords[0] != oldRow && newCoords[1] != oldCol)
                {
                    moveTo(tempCritter, oldRow, oldCol, newCoords[0], newCoords[1]);
                }
            }
        }
    }
}


// Moves a Critter to a new square, *replacing* whatever was there before.
// Old coords will change to pointing to NULL
void Board::moveTo(Critter* movingCritter, int oldRow, int oldCol, int newRow, int newCol)
{
    Critter* deadCritter;    // Critter occupying (newRow, newCol)
    
    // Make deadCritter point to the Critter on the square where movingCritter will be
    getSquareState(&deadCritter, newRow, newCol);

    // get rid of any critter at the new coords
    if (deadCritter != NULL)
    {
        delete deadCritter;  // Delete memory holding Critter
    }

    // Point the new coords to the moving critter
    boardState[newRow][newCol] = movingCritter;

    // Point the old coords to NULL
    boardState[oldRow][oldCol] = NULL;
}


// Breed eligible critters
// Assumes only 2 possible species
// Critter::breed(int currentDay, int* passCoords, int currentRow, int currentCol) acts 
//      analagous to Critter::move...
//      will modify passCoords with (row, col) coords of new critter
//
// breedCritters depends on Critter having:
// getSpecies()
// getLastBreed()
// getBreedingPeriod()
// breed(...)
void Board::breedCritters(int speciesID)
{
    Critter* tempCritter;
        // could use a flag to check if out of bounds, but
        // decided not to use (assumes below loops will never try
        // to access outside of the board)

    int breedingPeriod;
    int currentDay = getDayCounter();

    // For use by Critter to communicate the desired row, col of offspring
    int offspringCoords [2];

    // Iterate through rows
    for (int row = 0; row < getSizeRow(); row++)
    {
        // Iterate through cols
        for (int col = 0; col < getSizeCol(); col++)
        {
            // Point tempCritter to the object at (row, col)
            getSquareState(&tempCritter, row, col);

            if (tempCritter->getSpecies() == speciesID)
            {
                // check if eligible to breed
                if (currentDay - tempCritter->getLastBreed() >= tempCritter->getBreedingPeriod())
                {
                    // currentDay can be used by Critter to keep track of when
                    // it last gave birth
                    tempCritter->breed(currentDay, offspringCoords, row, col);
                }

                // Check that new coords != old coords
                if (offspringCoords[0] != oldRow && offspringCoords[1] != oldCol)
                {
                    addCritter(speciesID, offspringCoords[0], offspringCoords[1]);
                }
            }
        }
    }
}


// Assumes only 2 possible species
// Also assumes that new Critters are ONLY added to empty squares
void Board::addCritter(int speciesID, int row, int col)
{
    if (speciesID == ANT_ID)
    {
        // boardState[row][col] = new Ant...
    }
    else
    {
        // boardState[row][col] = new DB...
    }
}

// Starve eligible doodlebugs
void Board::starveDoodlebugs()
{
    Critter* tempCritter;
        // could use a flag to check if out of bounds, but
        // decided not to use (assumes below loops will never try
        // to access outside of the board)

    // Iterate through rows
    for (int row = 0; row < getSizeRow(); row++)
    {
        // Iterate through cols
        for (int col = 0; col < getSizeCol(); col++)
        {
            // Point tempCritter to the object at (row, col)
            getSquareState(&tempCritter, row, col);

            if (tempCritter->getSpecies() == DB_ID)
            {
                // check if eligible to breed
                if (currentDay - tempCritter->getLastAte() >= tempCritter->getStarvePeriod())
                {
                    delete tempCritter;
                    boardState[row][col] = NULL;
                }
            }
        }
    }                   
}

