/*******************************************************************************
 ** Ant Class
 **     This is the implementation file for the ant class and contains all the 
 **     member variables and member functions for ant.
 ******************************************************************************/
#include "ant.hpp"
#include "Critter.hpp"
#include <random>


Ant::Ant(int row, int col, Critter***board)
{
    this->board = board;
    // setting y position will be determined in Critter
    setR(row);
    // setting x position will be determined in Critter
    setC(col);
    steps = 0;
}

void Ant::breed(int currentDay, int* passCoords, int currentRow, int currentCol)
{
     setDayBirth(currentDay);
     setXPos(passCoords[0]);
     setYPos(passCoords[1]);
     setDayLastBred(0);
}

void Ant::move(int* passCoords, int currentRow, int currentCol)
{
    //passCoords = [row,col]
    setXPos(passCoords[0]);
    setYPos(passCoords[1]);
    setDayLastBred(getDayLastBred()+1);
}

void Ant::getDayLastBred()
{
    return steps;
}



void Ant::tick()
{
    move();
    breed();
}