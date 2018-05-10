#include "doodlebug.hpp"


Doodlebug::Doodlebug() 
{
	/*
	setDayBirth(0);
	setSpecies(1);
	setXPos(0);
	setYPos(0);
	setBreedingPeriod(8);
	setDayLastBred(0);
	*/

}

// COMMENTED OUT FOR COMPILATION, NO MATCHING PROTOTYPE IN HPP
// Doodlebug::Doodlebug(int xPos, int yPos, bool ate, bool breedable)
// {

// }
// ADDED SO THAT BOARD CAN FIND/USE CONSTRUCTOR
Doodlebug::Doodlebug(int day, int xPos, int yPos): Critter(day,1,0)
{
	//
}

void Doodlebug::breed(int currentDay, int * passCoords, int currentRow, int currentCol)
{
	if (currentDay - getDayLastBred() >= 8) 
	{
		setDayLastBred() = currentDay;
	}
}

void Doodlebug::setLastAte(int lastAte)
{
	this->lastAte = lastAte;
}

int * Doodlebug::getAvailableMove(Critter *** boardState, int currentRow, int currentCol)
{
	int * results = new int[2];
	results[0] = this->getXPos();
	results[1] = this->getXPos();

	return results;
}

int Doodlebug::getLastAte()
{
	return lastAte;
}


void Doodlebug::move(int currentDay, int* passCoords, int currentRow, int currentCol)
{
	
}

