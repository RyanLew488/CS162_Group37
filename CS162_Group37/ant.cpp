/*******************************************************************************
 ** Ant Class
 **     This is the implementation file for the ant class and contains all the 
 **     member variables and member functions for ant.
 ******************************************************************************/
#include "ant.hpp"

Ant::Ant(int xPos, int yPos, int birth, Critter***Board)
{
    setXpos(xPos);
    setYpos(yPos);
    setDayBirth(0);
    boardPtr = Board;
}


void Ant::breed()
{
    // if age is greater than 3
    if (getDayBirth() >= 3)
    {
        // generate random number to breed
        int randBreed = rand() % 4;
        // will need a bool to validate if breeding is successful
        // also need a loop to loop through until breed is successful 
        int breedSuccess = false;

        switch(randBreed)
        {
            case 0:
            {
                // UP
                // if y + 1 == NULL ptr
                // new ant
                // if breedSuccess then breedSuccess = true;
                // break;
            }
            case 1:
            {
                // RIGHT
                // if x + 1 == NULL ptr
                // new ant at x + 1
                // if breedSuccess then breedSuccess = true;
                // break;
            }
            case 2:
            {
                // DOWN
                // if y - 1 == NULL ptr
                // new ant at y - 1
                // if breedSuccess then breedSuccess = true;
                // break;
            }
            case 3:
            {
                // LEFT
                // if x - 1 == NULL ptr
                // new ant at x - 1
                // if breedSuccess then breedSuccess = true;
                // break;
            }
        }

    }
}


void Ant::move()
{
    // generate random number to move ant
    // srandtime somewhere
    int antMove = rand() % 4;
    bool moveSuccess = false;

    // need to loop through until moveSuccess = true

    switch(antMove)
    {
        case 0:
        {
            // UP
            if (boardPtr[getY() + 1][getX()] == nullptr)
            {
                // set Y and X at new location
                // moveSuccess = true;
                // break
            }
        }
        case 1:
        {
            if (boardPtr[getY()][getX() + 1] == nullptr)
            {
                // set Y and X at new location
                // moveSuccess = true;
                // break
            }
        }
        case 2:
        {
            if (boardPtr[getY() + 1][getX()] == nullptr)
            {
                // set Y and X at new location
                // moveSuccess = true;
                // break
            }
        }
        case 3:
        {
            if (boardPtr[getY()][getX() - 1] == nullptr)
            {
                // set Y and X at new location
                // moveSuccess = true;
                // break
            }
        }
    }
}

