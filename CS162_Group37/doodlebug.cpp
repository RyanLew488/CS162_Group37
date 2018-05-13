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
	int breedRow;
	int breedCol;
	bool checkUp = 0;
	bool checkRight = 0;
	bool checkDown = 0;
	bool checkLeft = 0;
	bool checkedAllDirections = 0;
	bool breedingSuccessful = 0;
	int flagSquareIsInBounds;
	
	const Critter *tempCritter;

	while (!breedingSuccessful && !checkedAllDirections)
	{

		breedRow = currentRow;
		breedCol = currentCol;
		int direction = rand() % 4;
		switch (direction)
		{
		case 0:
			checkUp = 1;
			breedRow = currentRow - 1;
			break;
		case 1:
			checkRight = 1;
			breedCol = currentCol + 1;
			break;
		case 2:
			checkDown = 1;
			breedRow = currentRow + 1;
			break;
		case 3:
			checkLeft = 1;
			breedCol = currentCol - 1;
			break;
		}


		flagSquareIsInBounds = getSquareState(&tempCritter, breedRow, breedCol);
		
		if (flagSquareIsInBounds && tempCritter == NULL)
		{
			breedingSuccessful = 1;
		}
		checkedAllDirections = checkUp && checkRight && checkDown && checkLeft;
	}
	

	if (breedingSuccessful)
	{
		setDayLastBred(currentDay);
		passCoords[0] = breedRow;
		passCoords[1] = breedCol;
	}
	else
	{
		passCoords[0] = currentRow;
		passCoords[1] = currentCol;
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
	}


 //No ant was found, moving to random selection.
    // setDayLastMove(currentDay);

    // int newRow = currentRow;
    // int newCol = currentCol;

    // Generate a direction to move
    // 0 - up; 1 - right; 2 - down; 3 - left;
    int direction = rand() % 4;

    switch (direction)
    {
        case 0:
            newRow = currentRow - 1;
            break;
        case 1:
            newCol = currentCol + 1;
            break;
        case 2:
            newRow = currentRow + 1;
            break;
        case 3:
            newCol = currentCol - 1;
            break;
    }

    const Critter* tempCritter;

    int flagValidSquare = getSquareState(&tempCritter, newRow, newCol);

    // If square is out of bounds or occupied, then don't move
    if (!flagValidSquare || tempCritter != NULL)
    {
        newRow = currentRow;
        newCol = currentCol;
    }

    // Tell board where Ant wants to move (or not move)
    newCoords[0] = newRow;
    newCoords[1] = newCol;


}

int Doodlebug::getSquareState(const Critter** critterHolder, int inRow, int inCol)
{
	// If coords valid (inside board)
	bool rowValid = (inRow >= 0) && (inRow < getBoardSizeRows());
	bool colValid = (inCol >= 0) && (inCol < getBoardSizeCols());

	if (rowValid && colValid)
	{
		// Pass along the address to the Critter at (inRow, inCol)
		*critterHolder = pointerToBoardState[inRow][inCol];

		// Communicate that coords were valid
		return 1;
	}
	else
	{
		// Communicate that coords were invalid
		// (outside of board bounds)
		return 0;
	}
}
