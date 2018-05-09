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

// COMMENTED OUT FOR COMPILATION, NO MATCHING PROTOTYPE IN HPP
// Doodlebug::Doodlebug(int xPos, int yPos, bool ate, bool breedable)
// {

// }

void Doodlebug::move(int* passCoords, int currentRow, int currentCol)
{
	bool validMove = false;
	int direction = 0; // 0:N 1:E 2:S 3:W 
	direction = rand() % 4;
	if (validMove)
	{
		switch (direction)
		{
		case 0: //North
			break;
		case 1: //East
			break;
		case 2: //South
			break;
		case 3: //West
			break;
		}
	}
	else
	{
		return;
	}
}

