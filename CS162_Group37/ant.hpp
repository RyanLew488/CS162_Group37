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
    private:


    public:
        // REPLACED -- BELOW
        // // MODIFIED TO MATCH Critter CONSTRUCTOR (int, int, int)
        // // Ant(int day, int xPos, int yPos): Critter(day,0,xPos,yPos,0){};
        // // Ant(int day, int initSpecies, int xPos, int yPos): Critter(day,0,xPos,yPos,0){};
        // Ant(int day, int xPos, int yPos): Critter(day,0,0){};
        // Ant(int day, int initSpecies, int xPos, int yPos): Critter(day,0,0){};

        // ADDED - ptr to board, board size rows, board size cols
        // REMOVED - xPos, yPos
        Ant(Critter*** boardState, int boardSizeRow, int boardSizeCol, int currentDay);

        // REMOVED - don't match Critter method signatures
        // void move(Critter *** boardState ,int currentDay, int* newCoords, int currentRow, int currentCol);
        // void breed(Critter *** boardState ,int currentDay, int* newCoords, int currentRow, int currentCol);

        // REMOVED - move and breed have slightly different logic
        //      plus getSquareState takes over some of what getAvailable was doing
        // void getAvailiable(int* results);

        // ADDED - to assist getAvailable
        int getSquareState(const Critter** critterHolder, int inRow, int inCol);

        // ADDED TO MATCH virtual void Critter::move
        void move(int, int*, int, int);
        
        // ADDED TO MATCH virtual void Critter:breed
        void breed(int, int*, int, int);
};
#endif