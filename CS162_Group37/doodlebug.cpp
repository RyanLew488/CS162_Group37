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

void Doodlebug::breed(int currentDay, int * passCoords, int currentRow, int currentCol)
{
	setDayBirth(currentDay);
	setXPos(passCoords[0]);
	setYPos(passCoords[1]);
	setDayLastBred(0);
	setSpecies(1);
	setBreedingPeriod(1);
	setLastAte(0);
}

void Doodlebug::setLastAte(int lastAte)
{
	this->lastAte = lastAte;
}

int Doodlebug::getLastAte()
{
	return lastAte;
}

Doodlebug::Doodlebug(int xPos, int yPos, bool ate, bool breedable)
{

}

void Doodlebug::move(int* passCoords, int currentRow, intcurrentCol)
{
	//stub function remove after implemented
	std::cout << "Doodlebug moving" << std::endl;
	setDayLastBred(getDayLastBred() + 1);
	
}

void Doodlebug::turn()
{

}
