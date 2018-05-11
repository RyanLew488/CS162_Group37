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
// NEEDS TO BE COMPLETED
Doodlebug::Doodlebug(int day, int xPos, int yPos)
{
}

//test comment
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

int Doodlebug::getLastAte()
{
	return lastAte;
}


void Doodlebug::move(int currentDay, int* newCoords, int currentRow, int currentCol)
{ 
	setDayLastMove(currentDay);
	int newRow = currentRow;
	int newCol = currentCol;
	bool noAnt = true;


	for (int i = 0; i < 4; i++) //find ant;
	{
		switch (i)
		{
		case 0:
			if (pointerToBoardState[currentRow -1][currentCol]->getSpecies() == 0);
			{
				newRow = currentRow - 1;
				noAnt = false;
				setLastAte = currentDay;
				i = 4; //exit for loop
			}
			break;
		case 1:
			if (pointerToBoardState[currentRow][currentCol + 1]->getSpecies() == 0);
			{
				newCol = currentCol + 1;
				noAnt = false;
				setLastAte = currentDay;
				i = 4; //exit for loop
			}
			break;
		case 2:
			if (pointerToBoardState[currentRow + 1][currentCol]->getSpecies() == 0);
			{
				newRow = currentCol + 1;
				noAnt = false;
				setLastAte = currentDay;
				i = 4; //exit for loop
			}
			break;
		case 3:
		if (pointerToBoardState[currentRow][currentCol - 1]->getSpecies() == 0);
			{
				newCol = currentCol - 1;
				noAnt = false;
				setLastAte = currentDay;
				i = 4; //exit for loop
			}
			break;
		}
		bool northChecked = false;
		bool eastChecked = false;
		bool southChecked = false;
		bool westChecked = false;
	while (noAnt) //No ant was found, moving to random selection.
	{
		bool allDirectionsChecked = false;
		while (!allDirectionsChecked)
		{
			int direction = rand() % 4;
			switch (direction)
			{
			case 0:
				northChecked = true;
				if (pointerToBoardState[currentCol - 1][currentRow] == nullptr)
				{
					newCol = currentCol - 1;
				}
				break;
			case 1:
				eastChecked = true;
				if (pointerToBoardState[currentCol][currentRow + 1] == nullptr)
				{
					newRow = currentRow + 1;
				}
				break;
			case 2:
				southChecked = true;
				if (pointerToBoardState[currentCol + 1][currentRow] == nullptr)
				{
					newCol = currentCol + 1;
				}
				
				break;
			case 3:
				westChecked = true;
				if (pointerToBoardState[currentCol][currentRow - 1] == nullptr)
				{
					newRow = currentCol = 1;
				}
				break;
			}
			if (northChecked && eastChecked && southChecked && westChecked)
			{
				allDirectionsChecked = true;
			}
		}
		noAnt = false;
	}
	newCoords[0] = newRow;
	newCoords[1] = newCol;
}
