/*******************************************************************************
 ** Ant Class
 **     This is the implementation file for the ant class and contains all the 
 **     member variables and member functions for ant.
 ******************************************************************************/
#include "ant.hpp"
//#include "critter.hpp"
#include <random>


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
    return dayLastBred;
}