/*******************************************************************************
** Doodlebug Class
**     Header file for the Doodlebug Class contains some setter and getter functions
******************************************************************************/
#pragma once
#include "critter.hpp"

class Doodlebug : public Critter 
{
private:
	int lastAte;
	int starvePeriod;
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
	Doodlebug(Critter*** boardState, int boardSizeRow, int boardSizeCol, int currentDay);
	void move(int currentDay, int* newCoords, int currentRow, int currentCol);
	void breed(int currentDay, int* newCoords, int currentRow, int currentCol);
	void setLastAte(int lastAte);
	int getStarvePeriod();
	int getLastAte();
	int getSquareState(const Critter ** critterHolder, int inRow, int inCol);
};
