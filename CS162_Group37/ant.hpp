/*******************************************************************************
 ** Ant Class
 **     This is the header file for the ant class and contains all the
 **     declarations for ant.cpp
 ******************************************************************************/
#ifndef ANT_HPP
#define ANT_HPP
#include "critter.hpp"


class Ant : public Critter 
{
    public:
        Ant(int day, int xPos, int yPos): Critter(day,0,xPos,yPos,0){};
        Ant(int day, int initSpecies, int xPos, int yPos): Critter(day,0,xPos,yPos,0){};

        void move(Critter *** boardState ,int currentDay, int* newCoords, int currentRow, int currentCol);
        void breed(Critter *** boardState ,int currentDay, int* newCoords, int currentRow, int currentCol);
        int * getAvailiable(Critter *** boardState, int currentRow, int currentCol);

        // ADDED TO MATCH virtual void Critter::move
        void move(int, int*, int, int){};
        
        // ADDED TO MATCH virtual void Critter:breed
        void breed(int, int*, int, int){};
};
#endif