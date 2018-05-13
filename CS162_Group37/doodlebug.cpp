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

Doodlebug::Doodlebug(Critter*** boardState, int boardSizeRow, int boardSizeCol, int currentDay) : 
								Critter (currentDay, 1, 8,boardSizeRow, boardSizeCol, boardState)
{
	setLastAte(currentDay);
	setDayLastBred(currentDay);
	starvePeriod = 3;
}

//test comment
void Doodlebug::breed(int currentDay, int * passCoords, int currentRow, int currentCol)
{
	if (currentDay - getDayLastBred() >= 8)
	{
		setDayLastBred(currentDay);
	}
}

void Doodlebug::setLastAte(int lastAte)
{
	this->lastAte = lastAte;
}

int Doodlebug::getStarvePeriod()
{
	return starvePeriod;
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
			if ((currentRow - 1) >= 0 && pointerToBoardState[currentRow - 1][currentCol] != NULL)
			{
				if (pointerToBoardState[currentRow - 1][currentCol]->getSpecies() == 0)
				{
					newRow = currentRow - 1;
					noAnt = false;
					setLastAte(currentDay);
					i = 4; //exit for loop
				}
			}
			break;
		case 1:
			if ((currentCol + 1) < getBoardSizeCols() && pointerToBoardState[currentRow][currentCol + 1] != NULL)
			{
				if (pointerToBoardState[currentRow][currentCol + 1]->getSpecies() == 0)
				{
					newCol = currentCol + 1;
					noAnt = false;
					setLastAte(currentDay);
					i = 4; //exit for loop
				}
			}
			break;
		case 2:
			if ((currentRow + 1) < getBoardSizeRows() && pointerToBoardState[currentRow + 1][currentCol] != NULL)
			{
				if (pointerToBoardState[currentRow + 1][currentCol]->getSpecies() == 0)
				{
					newRow = currentRow + 1;
					noAnt = false;
					setLastAte(currentDay);
					i = 4; //exit for loop
				}
			}
			break;
		case 3:
			if ((currentCol - 1) >= 0 && pointerToBoardState[currentRow][currentCol - 1] != NULL)
			{
				if (pointerToBoardState[currentRow][currentCol - 1]->getSpecies() == 0)
				{
					newCol = currentCol - 1;
					noAnt = false;
					setLastAte(currentDay);
					i = 4; //exit for loop
				}
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
					if ((currentRow - 1) >= 0 && pointerToBoardState[currentRow - 1][currentCol] == nullptr)
					{
						newRow = currentRow - 1;
						noAnt = false;
						allDirectionsChecked = true;
					}
					break;

				case 1:
					eastChecked = true;
					if ((currentCol + 1) < getBoardSizeRows() && pointerToBoardState[currentRow][currentCol + 1] == nullptr )
					{
						newCol = currentCol + 1;
						noAnt = false;
						allDirectionsChecked = true;
					}
					break;

				case 2:
					southChecked = true;
					if ((currentRow + 1) < getBoardSizeCols() && pointerToBoardState[currentRow + 1][currentCol] == nullptr )
					{
						newRow = currentRow + 1;
						noAnt = false;
						allDirectionsChecked = true;
					}
					break;

				case 3:
					westChecked = true;
					if ((currentCol - 1) >= 0 && pointerToBoardState[currentRow][currentCol - 1] == nullptr )
					{
						newCol = currentCol - 1;
						noAnt = false;
						allDirectionsChecked = true;
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
}
