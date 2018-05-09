/********************************************************************* 
** Author: CS162 Team 37
** Date: 5/13/2018
** Group Project: Predator-Prey Game
** Description: Implementation file for the Critter class
*********************************************************************/ 
// critter.cpp


#include <iostream>
#include <string>

#include "critter.hpp"

// Declare specific using statements to avoid namespace pollution

using std::cout;
using std::cin;
using std::endl;


// constructor
Critter::Critter(int day, int initSpecies,int initbreedingPeriod)
{
    setDayBirth(day);
    setSpecies(initSpecies);
    setCritterChar(initSpecies);        // ADDED SO ALL CRITTERS WILL HAVE A CHAR TO PRINT
    setBreedingPeriod(initSpecies);
    setDayLastBred(day);
}

// 'virtual' OUTSIDE CLASS DECLARATION.
// destructor
// virtual Critter::~Critter() {}

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

int Critter::getBreedingPeriod()
{
    return breedingPeriod;
}

char Critter::getCritterChar()
{
    return critterChar;
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

void Critter::setBreedingPeriod(int species)
{
    // const int ANT_ID = 0;
    // const int DB_ID = 1;
    if (species == 0)
    {
        breedingPeriod = 3;
    }
    else
    {
        breedingPeriod = 8;
    }
}

// ADDED "Critter::"
void Critter::setCritterChar(int species)
{
    // const int ANT_ID = 0;
    // const int DB_ID = 1;
    if (species == 0)
    {
        critterChar = char(79);
    }
    else
    {
        critterChar = char(88);
    }
}

void Critter::print()
{
    cout << getCritterChar();
}