/********************************************************************* 
** Author: CS162 Team 37
** Date: 5/13/2018
** Group Project: Predator-Prey Game
** Description: Header file to define the interface of the Critter class
*********************************************************************/ 
// Critter.hpp

#ifndef CRITTER_HPP
#define CRITTER_HPP

#include <iostream>
#include <string>

#include board.hpp

// Declare specific using statements to avoid namespace pollution

using std::cout;
using std::cin;
using std::endl;

enum Direction {UP, RIGHT, DOWN, LEFT};

class Critter
{
private: 

    int dayBirth;
    int dayLastBred;
    int species;
    int xPos, yPos;

protected:
    // setters
    void setSpecies(int initSpecies);
    void setDayBirth(int initDayBirth);

public:

    // constructor
    Critter(int day, int initSpecies, int xPos, int yPos);

    // destructor
    virtual ~Critter() {};

    // getters
    int getDayBirth();
    int getSpecies();
    int getDayLastBred();


	// setters
    void setDayLastBred(int newDayLastBred);
    void setXPos(int initXPos);
    void setYPos(int initYPos);

    // class methods

    Critter** getAvailability();
    int * convertDirToRowCol(int dir);

    // virtual functions defined in the derived classes of Ant and Doodlebug
    virtual void move(int* arrBoard, int currentRow, int currentCol) = 0;
    virtual void breed() = 0;
	
};
#endif
