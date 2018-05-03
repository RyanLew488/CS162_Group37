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
Critter(int day, int initSpecies)
{
    set_dayBirth(int day);
    set_species(initSpecies);
};

// destructor
virtual ~Critter() {};

// getters
int get_dayBirth()
{
    return dayBirth;
}

int get_species()
{
    return species;
}

int get_dayLastBred()
{
    return dayLastBred;
}


// setters
void set_dayLastBred(int newDayLastBred)
{
    dayLastBred = newDayLastBred;
}
	
void set_species(int initSpecies)
{
    species = initSpecies;
}

void set_dayBirth(int initDayBirth);
{
    dayBirth = initDayBirth;
}


