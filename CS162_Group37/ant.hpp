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
        // ADDED THESE BECAUSE THEY WERE REMOVED FROM CRITTER
        // WRITTEN IN TERMS OF ROW/COL WHERE POSSIBLE TO MINIMIZE CONFUSION

        int colPos;
        int rowPos;

        void setColPos(int inCol)
        {
            colPos = inCol;
        }

        void setRowPos(int inRow)
        {
            rowPos = inRow;
        }

        int getColPos()
        {
            return colPos;
        }

        int getRowPos()
        {
            return rowPos;
        }

        int getXPos()
        {
            return getColPos();
        }

        int getYPos()
        {
            return getRowPos();
        }

    public:
        // MODIFIED TO MATCH Critter CONSTRUCTOR (int, int, int)
        // Ant(int day, int xPos, int yPos): Critter(day,0,xPos,yPos,0){};
        // Ant(int day, int initSpecies, int xPos, int yPos): Critter(day,0,xPos,yPos,0){};
        Ant(int day, int xPos, int yPos): Critter(day,0,0){};
        Ant(int day, int initSpecies, int xPos, int yPos): Critter(day,0,0){};

        void move(Critter *** boardState ,int currentDay, int* newCoords, int currentRow, int currentCol);
        void breed(Critter *** boardState ,int currentDay, int* newCoords, int currentRow, int currentCol);
        int * getAvailiable(Critter *** boardState, int currentRow, int currentCol);

        // ADDED TO MATCH virtual void Critter::move
        void move(int, int*, int, int){};
        
        // ADDED TO MATCH virtual void Critter:breed
        void breed(int, int*, int, int){};
};
#endif