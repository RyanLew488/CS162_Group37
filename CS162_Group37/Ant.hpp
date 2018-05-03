/*******************************************************************************
 ** Ant Class
 **     This is the header file for the ant class and contains all the
 **     declarations for ant.cpp
 ******************************************************************************/
#ifndef ANT_HPP
#define ANT_HPP
#include "board.hpp"
#include "critter.hpp"



class Ant : public Critter 
{
    private:
        // ant's x pos
        // ant's y pos
        int x = 0,
            y = 0,
        // increment steps to breed
        steps = 0;

        // pointer to the board
        Critter*** board = nullptr;

    public:
        // Default constructor takes in xPos and yPos of ant
        // Default constructor take in board
        Ant(int, int, Critter***board);
        // Rand breed if steps >= 3
        void breed();
        // Rand move if there are no Critters in adjacent cells
        void move();
        // tick increments steps
        void tick();

        // returns a pointer to a critter
        Critter** getAvailability();
        int * convertDirToRowCol(int);
       
};

#endif