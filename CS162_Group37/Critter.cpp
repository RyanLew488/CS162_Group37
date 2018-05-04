/********************************************************************* 
** Author: CS162 Team 37
** Date: 5/13/2018
** Group Project: Predator-Prey Game
** Description: Implementation file for the Critter class
*********************************************************************/ 
// Critter.cpp


#include <iostream>
#include <string>

#include "Critter.hpp"

// Declare specific using statements to avoid namespace pollution

using std::cout;
using std::cin;
using std::endl;


// constructor
Critter::Critter(int day, int initSpecies, int xPos, int yPos)
{
    set_dayBirth(day);
    set_species(initSpecies);
    set_xPos(initXPos);
    set_yPos(initYPos);
}

// destructor
virtual Critter::~Critter() {}

// getters
int Critter::get_dayBirth()
{
    return dayBirth;
}

int Critter::get_species()
{
    return species;
}

int Critter::get_dayLastBred()
{
    return dayLastBred;
}


// setters
void Critter::set_dayLastBred(int newDayLastBred)
{
    dayLastBred = newDayLastBred;
}
	
void Critter::set_species(int initSpecies)
{
    species = initSpecies;
}

void Critter::set_dayBirth(int initDayBirth)
{
    dayBirth = initDayBirth;
}

void Critter::set_xPos(int initXPos)
{
    xPos = initXPos;
}

void Critter::set_yPos(int initYPos)
{
    yPos = initYPos;
}
