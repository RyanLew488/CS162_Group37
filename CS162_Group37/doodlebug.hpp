#pragma once
#include "critter.hpp"

class Doodlebug : public Critter 
{
private:
	int lastAte;

public:
	Doodlebug();
	Doodlebug(int day, int xPos, int yPos);
	void move(int*, int, int);
	void turn(int*, int, int);
	void breed(int currentDay, int* passCoords, int currentRow, int currentCol);
	void setLastAte(int lastAte);
	int getLastAte();
};
