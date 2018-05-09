/*******************************************************************************
 ** Ant Class
 **     This is the implementation file for the ant class and contains all the 
 **     member variables and member functions for ant.
 ******************************************************************************/
#include "ant.hpp"
#include "critter.hpp"
#include <random>
#include <vector>


void Ant::breed(Critter *** boardState ,int currentDay, int* newCoords, int currentRow, int currentCol)
{
    if ((currentDay - getDayLastBred()) >= 3)
    {
        setDayLastBred(currentDay);
        newCoords = getAvailiable(boardState, currentRow, currentCol);
    }
}

void Ant::move(Critter *** boardState ,int currentDay, int* newCoords, int currentRow, int currentCol)
{
    newCoords = getAvailiable(boardState, currentRow, currentCol);
}

int * Ant::getAvailiable(Critter *** boardState, int currentRow, int currentCol)
{
    int * results = new int[2];
    results[0] = this->getXPos();
    results[1] = this->getYPos();

    //first we check how many of the 4 direction are available
    int count = 0;
    std::vector <Critter*> v;
    if(currentRow != 19 && boardState[currentRow+1][currentCol])
    {
        count++;
        v.push_back(boardState[currentRow+1][currentCol]);
    }
    if(currentRow != 0 && boardState[currentRow-1][currentCol])
    {
        count++;
        v.push_back(boardState[currentRow-1][currentCol]);
    }
    if(currentCol != 19 && boardState[currentRow][currentCol+1])
    {
        count++;
        v.push_back(boardState[currentRow][currentCol+1]);

    }
    if(currentCol != 0 && boardState[currentRow][currentCol-1])
    {
        count++;
        v.push_back(boardState[currentRow][currentCol-1]);
    }

    if (count > 0)
    {
        std::random_device rd;
        std::mt19937 e{rd()}; // or std::default_random_engine e{rd()};
        std::uniform_int_distribution<int> dir{0, count-1};

        int direction = dir(e);
        int x = v.at(direction)->getXPos();
        int y = v.at(direction)->getYPos();
        results[0] = x;
        results[1] = y;
    }

    return results;
}