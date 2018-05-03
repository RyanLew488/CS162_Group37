/*******************************************************************************
 ** Ant Class
 **     This is the header file for the ant class and contains all the
 **     declarations for ant.cpp
 ******************************************************************************/
#ifndef ANT_HPP
#define ANT_HPP
#include "board.hpp"
#include "critter.hpp"

enum Direction {UP, RIGHT, DOWN, LEFT};

class Ant : public Critter 
{
    private:
        int x = 0,
            y = 0,
        steps = 0;
    
        Critter*** board = nullptr;

    public:
        Ant(int, int, int, Critter***board);
        
        void breed();
        void move();
        // every tick of game
        // board goes through each block and age all critters
        void tick();
};

#endif