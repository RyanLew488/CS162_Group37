/*********************************************************************
** Program name: board.cpp
** Assignment: Group Project
** Author: David Coons - group 37
** Date: May 1, 2018
** 
** What this class does: 
** Coordinates are all (row, col)
** 
** Dependencies:
** board.hpp
** critter.hpp
**
*********************************************************************/

#include "board.hpp"
#include "critter.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

// *****======PUBLIC=====*****

// Constructor sets board size and initial number of ants & dbs
Board::Board(int inRow, int inCol, int numAnts, int numDoodlebugs)
{
    // seed rand

}

// Destructor deletes memory at pointers before
// deleting boardState
Board::~Board()
{
    //
}

// Used to run the predator-prey game
void Board::runGame()
{
    // Menu to determine user-defined game parameters
        // #days
        // #ants
        // #dbs
        // board size

    // Loop until dayCounter == #days (might want to use >= to be safe)
        // Order of events not finalized
        // moveCritters(ANT_ID);
        // moveCritters(DB_ID);
        // breedAnts();
        // breedDoodlebugs();
        // starveDoodlebugs();

        // Print "End day __"
        // printBoard();

        // incDay();
}

// Get the Critter* at a square (row, col)
// returns an int to indicate success
//      0 - given coords invalid (outside board)
//      1 - given coords valid (inside board)
int Board::getSquareState(Critter** critterHolder, int inRow, int inCol)
{
    // If coords valid (inside board)
        // *critterHolder = boardState[inRow][inCol];
        // return 1;
    // else
        // return 0;
}


// *****======PRIVATE=====*****

// Initializes the locations of all ants and doodlebugs
// **ASSUMES** numAnts + numDoodlebugs < sizeRow * sizeCol
void Board::setInitLocs(int numAnts, int numDoodlebugs)
{
    // loop for numAnts times
        // loop until Ant is successfully placed
            // get rand generated (row, col)
            // If square is empty
                // boardState[row][col] = new Ant...

    // loop for numDoodlebugs times
        // loop until Doodlebug is successfully placed
            // get rand generated (row, col)
            // If square is empty
                // boardState[row][col] = new Doodlebug...  
}

// Print the current board state to the terminal
void Board::printBoard()
{
    // Critter* tempCritter;
        // could use a flag to check if out of bounds, but
        // decided not to use (assumes below loops will never try
        // to access outside of the board)

    // Print horizontal border
    // Iterate through rows
        // Iterate through cols
            // Print vertical border

            // Point tempCritter to the object at (row, col)
            // getSquareState(&tempCritter, row, col);

            // if tempCritter is null
                // print CHAR_EMPTY
            // else
                // Critter::print() prints char to std::cout
                // tempCritter->print();
        
            // Print vertical border
    
    // Print horizontal border
}

// Move all ants OR dbs on the board (see Board::ANT_ID/Board::DB_ID)
// 
// Critter::move(int* passCoords, int currentRow, int currentCol) will modify passCoords array
//     according to critter's internal move logic
//     passCoords MUST be inside of board
// passCoords[0] = newRow
// passCoords[1] = newCol
void Board::moveCritters(int speciesID)
{
    // Critter* tempCritter;
        // could use a flag to check if out of bounds, but
        // decided not to use (assumes below loops will never try
        // to access outside of the board)

    // Coords will be {row, col}
    // int newCoords [2];

    // Iterate through rows
        // Iterate through cols
            // Point tempCritter to the object at (oldRow, oldCol)
            // getSquareState(&tempCritter, oldRow, oldCol);

            // if tempCritter->getSpecies() == speciesID
                // get new coordinates of object
                // tempCritter->move(newCoords, oldRow, oldCol);


                // Check that new coords != old coords
                // if newCoords[0] != oldRow && newCoords[1] != oldCol
                    // moveTo(tempCritter, oldRow, oldCol, newCoords[0], newCoords[1]);
}


// Moves a Critter to a new square, *replacing* whatever was there before.
// Old coords will change to pointing to NULL
void Board::moveTo(Critter* movingCritter, int oldRow, int oldCol, int newRow, int newCol)
{
    // Critter* deadCritter;    // Critter occupying (newRow, newCol)
    // getSquareState(&deadCritter, newRow, newCol);

    // get rid of any critter at the new coords
    // if deadCritter != NULL
        // delete deadCritter;  // Delete object's memory
    
    // Point the new coords to the moving critter
    // boardState[newRow][newCol] = movingCritter;

    // Point the old coords to NULL
    // boardState[oldRow][oldCol] = NULL;
}


// Breed eligible critters
// Assumes only 2 possible species
// Critter::breed(int* passCoords, int currentRow, int currentCol) acts analagous to Critter::move...
//      will modify passCoords with (row, col) coords of new critter
void Board::breedCritters(int speciesID)
{
    // Critter* tempCritter;
        // could use a flag to check if out of bounds, but
        // decided not to use (assumes below loops will never try
        // to access outside of the board)

    // int breedingPeriod;

    // if speciesID == ANT_ID
        // breedingPeriod = ANT_BREEDING_PERIOD;
    // else
        // breedingPeriod = DB_BREEDING_PERIOD;

    // int newCoords [2];

    // Iterate through rows
        // Iterate through cols
            // Point tempCritter to the object at (row, col)
            // getSquareState(&tempCritter, row, col);

            // if tempCritter->getSpecies() == speciesID
                // check if eligible to breed
                // if (tempCritter->getLastBreed() - getDayCounter() >= breedingPeriod)
                    // tempCritter->breed(newCoords, row, col);

                    // Check that new coords != old coords
                    // if newCoords[0] != row && newCoords[1] != col
                        // addCritter(speciesID, newCoords[0], newCoords[1]);
}


// Assumes only 2 possible species
void Board::addCritter(int speciesID, int row, int col)
{
    // if speciesID == ANT_ID
        // boardState[row][col] = new Ant...
    // else
        // boardState[row][col] = new DB...
}

// Starve eligible doodlebugs
void Board::starveDoodlebugs()
{
    // Critter* tempCritter;
        // could use a flag to check if out of bounds, but
        // decided not to use (assumes below loops will never try
        // to access outside of the board)

    // Iterate through rows
        // Iterate through cols
            // Point tempCritter to the object at (row, col)
            // getSquareState(&tempCritter, row, col);

            // if tempCritter->getSpecies() == DB_ID
                // check if eligible to starve
                // if (tempCritter->getLastEat() - getDayCounter() >= DB_STARVE_PERIOD)
                    // delete tempCritter;
                    // boardState[row][col] = NULL;                    
}

