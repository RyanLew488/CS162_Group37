/********************************************************************* 
** Author: CS162 Team 37
** Date: 5/13/2018
** Group Project: Predator-Prey Game
** Description: Implementation file for the Critter class
*********************************************************************/ 
// Critter.cpp


#include <iostream>
#include <string>

#include "critter.hpp"

// Declare specific using statements to avoid namespace pollution

using std::cout;
using std::cin;
using std::endl;


// constructor
Critter::Critter(int day, int initSpecies, int xPos, int yPos)
{
    setDayBirth(day);
    setSpecies(initSpecies);
    setXPos(initXPos);
    setYPos(initYPos);
}

// destructor
virtual Critter::~Critter() {}

// getters
int Critter::getDayBirth()
{
    return dayBirth;
}

int Critter::getSpecies()
{
    return species;
}

int Critter::getDayLastBred()
{
    return dayLastBred;
}


// setters
void Critter::setDayLastBred(int newDayLastBred)
{
    dayLastBred = newDayLastBred;
}
	
void Critter::setSpecies(int initSpecies)
{
    species = initSpecies;
}

void Critter::setDayBirth(int initDayBirth)
{
    dayBirth = initDayBirth;
}

void Critter::setXPos(int initXPos)
{
    xPos = initXPos;
}

void Critter::setYPos(int initYPos)
{
    yPos = initYPos;
}



int * Critter::convertDirToRowCol(int dir)
{
    int * arr = nullptr;
    if (dir == 0)
    {
        // up
        arr = {1,0};
        return arr;
    }
    else if (dir == 1)
    {
        //down
        arr = {-1,0};
        return arr;
    }
    else if (dir == 2)
    {
        arr = {0,-1};
    }
    else if (dir == 3)
    {
        arr = {0,1};
        return arr;
    }
    throw string ("Dir should not be between 0-3, inclusively.");
}

Critter** Critter::getAvailability()
{
    {
        Critter*    up = nullptr,
                    down = nullptr,
                    left = nullptr,
                    right = nullptr,
        
        Critter **arr = {up, down, left, right};

        if (row == 0)
        [
            up = new Critter();
        ]
        else
        {
            up = board[row+1][col];
        }

        // 20x20 size of board to begin with, this can be altered
        if (row == 19)
        {
            down = new Critter();
        }
        else 
        {
            down = board[row-1][col];
        }

        if (col == 0)
        {
            left = new Critter();
        }
        else
        {
            left = board[row[col-1]];
        }

        if (col == 19)
        {
            right = new Critter();
        }
        else
        {
            right = board[row[col+1]];
        }

        return arr;
    }

    // either critter or nullptr being returned
}