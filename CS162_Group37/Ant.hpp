/*******************************************************************************
 ** Ant Class
 **     This is the header file for the ant class and contains all the
 **     declarations for ant.cpp
 ******************************************************************************/
#ifndef ANT_HPP
#define ANT_HPP

enum Direction {UP, RIGHT, DOWN, LEFT};

class Ant : public Critter 
{
    private:
        Critter*** boardPtr = nullptr;

    public:
        Ant(int, int, int, Critter***board);
        virtual void move();
        virtual void breed();
};

#endif