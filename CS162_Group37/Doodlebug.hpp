#pragma once

class Doodlebug : public Critter 
{
private:
	int dir;
	int age;
	bool ate;
	bool breedable;

public:
	Doodlebug();
	void move();
	void turn();
};