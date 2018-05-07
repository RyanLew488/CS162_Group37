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
        void breed(int, int*, int, int);
        // Rand move if there are no Critters in adjacent cells
        void move(int*, int, int);
        void getDayLastBred();
       
};
#endif