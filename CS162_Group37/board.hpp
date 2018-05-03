/*********************************************************************
** Program name: board.hpp
** Assignment: Group Project
** Author: David Coons - group 37
** Date: May 1, 2018
** 
** What this class does: 
** Coordinates are all (row, col) -- easier printing
** 
** Dependencies:
** 
**
*********************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

#include "critter.hpp"

class Board
{
private:
    // Data members
    // Limits for board size
    const int MAX_ROW = 30;
    const int MAX_COL = 30;

    // Constants use in game logic
    const int ANT_BREEDING_PERIOD = 3;
    const int DB_BREEDING_PERIOD = 8;

    const int DB_STARVE_PERIOD = 3;

    // Constant to define what char to print if blank square
    const char CHAR_EMPTY = ' ';

    // ******NEEDS TO BE DEFINED BY TEAM*********
    // Needs to match what is returned by int Critter::getSpecies()
    const int ANT_ID = 0;
    const int DB_ID = 1;

    // Chosen size of board
    int sizeRow;
    int sizeCol;

    // For keeping track of game time
    int dayCounter;

    // 2D dynamic array of pointers to critter objects
    Critter*** boardState;

    // Methods
    // Initialization helper - (#ants, #dbs)
    void setInitLocs(int, int);

    // Prints the state of the board
    // ========USES CRITTER::PRINT()==========
    void printBoard();

    // Setters - NO VALIDATION
    void setSizeRow(int inRow)
    {
        sizeRow = inRow;
    }

    void setSizeCol(int inCol)
    {
        sizeCol = inCol;
    }

    void setDayCounter(int inDay)
    {
        dayCounter = inDay;
    }

    // Getters
    int getSizeRow()
    {
        return sizeRow;
    }

    int getSizeCol()
    {
        return sizeCol;
    } 

    int getDayCounter()
    {
        return dayCounter;
    }

    // Game control
    // Increments current day by 1
    void incDay()
    {
        setDayCounter(getDayCounter() + 1);
    }
    void moveCritters(int); //moves ants or dbs based on int parameter
    void breedCritters(int);    // breeds ants/dbs based on int parameter
    void starveDoodlebugs();

    // Helps moveCritters
    void moveTo(Critter*, int, int, int, int);

    // Helps breedCritters
    void addCritter(int, int, int);

protected:
    // Data members

    // Methods

public:
    // Data members

    // Methods
    // Constructor
    // (board size row, board size col, #ants, #dbs)
    Board(int, int, int, int);

    ~Board();

    // Method for running the prey-predator game
    // All game logic and control contained inside runGame()
    void runGame();

    // Get the Critter* at a square (row, col)
    // returns an int to indicate success
    //      0 - given coords invalid (outside board)
    //      1 - given coords valid (inside board)
    int getSquareState(Critter**, int, int);

};

#endif