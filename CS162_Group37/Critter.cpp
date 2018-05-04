/********************************************************************* 
** Author: CS162 Team 37
** Date: 5/13/2018
** Group Project: Predator-Prey Game
** Description: Implementation file for the Critter class
*********************************************************************/ 
// Critter.cpp


#include <iostream>
#include <string>

#include "critter.hpp"

// Declare specific using statements to avoid namespace pollution

using std::cout;
using std::cin;
using std::endl;


// constructor
Critter::Critter(int day, int initSpecies, int xPos, int yPos)
{
    setDayBirth(day);
    setSpecies(initSpecies);
    setXPos(initXPos);
    setYPos(initYPos);
}

// destructor
virtual Critter::~Critter() {}

// getters
int Critter::getDayBirth()
{
    return dayBirth;
}

int Critter::getSpecies()
{
    return species;
}

int Critter::getDayLastBred()
{
    return dayLastBred;
}


// setters
void Critter::setDayLastBred(int newDayLastBred)
{
    dayLastBred = newDayLastBred;
}
	
void Critter::setSpecies(int initSpecies)
{
    species = initSpecies;
}

void Critter::setDayBirth(int initDayBirth)
{
    dayBirth = initDayBirth;
}

void Critter::setXPos(int initXPos)
{
    xPos = initXPos;
}

void Critter::setYPos(int initYPos)
{
    yPos = initYPos;
}