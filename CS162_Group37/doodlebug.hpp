#pragma once
#include "critter.hpp"

class Doodlebug : public Critter 
{
private:
	int lastAte;

	// ADDED THESE BECAUSE THEY WERE REMOVED FROM CRITTER
	// WRITTEN IN TERMS OF ROW/COL WHERE POSSIBLE TO MINIMIZE CONFUSION

	int colPos;
	int rowPos;

	void setColPos(int inCol)
	{
		colPos = inCol;
	}

	void setRowPos(int inRow)
	{
		rowPos = inRow;
	}

	void setXPos(int inX)
	{
		setColPos(inX);
	}

	void setYPos(int inY)
	{
		setRowPos(inY);
	}

	int getColPos()
	{
		return colPos;
	}

	int getRowPos()
	{
		return rowPos;
	}

	int getXPos()
	{
		return getColPos();
	}

	int getYPos()
	{
		return getRowPos();
	}

public:
	Doodlebug();
	Doodlebug(int day, int xPos, int yPos);
	Doodlebug(Critter*** boardState, int boardSizeRow, int boardSizeCol, int currentDay);
	void move(int currentDay, int* newCoords, int currentRow, int currentCol);
	void breed(int currentDay, int* newCoords, int currentRow, int currentCol);
	void setLastAte(int lastAte);
	int getLastAte();
};
