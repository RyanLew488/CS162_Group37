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
        Ant(int day, int xPos, int yPos): Critter(day,0,xPos,yPos){};
        Ant(int day, int initSpecies, int xPos, int yPos): Critter(day,0,xPos,yPos){};
        void breed(int, int*, int, int);
        // Rand move if there are no Critters in adjacent cells
        void move(int*, int, int);
        void getDayLastBred();
       
};
#endif