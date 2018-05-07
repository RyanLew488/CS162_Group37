#include "Doodlebug.hpp"
#include <iostream>

Doodlebug::Doodlebug() 
{
	setDayBirth(0);
	setSpecies(1);
	setXPos(0);
	setYPos(0);
	setBreedingPeriod(8);
	setDayLastBred(0);

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
	std::cout << "Doodlebug moving" << std::endl
	
}

void Doodlebug::turn()
{

}
