#pragma once
#include "Critter.hpp"

class Doodlebug : public Critter 
{
private:
	int age;
	bool ate;
	bool breedable;

public:
	Doodlebug();
	Doodlebug(int xPos, int yPos, bool ate, bool breedable);
	void move();
	void turn();
};