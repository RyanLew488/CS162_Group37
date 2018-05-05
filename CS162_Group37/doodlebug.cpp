#include "Doodlebug.hpp"

Doodlebug::Doodlebug() 
{

}

Doodlebug::Doodlebug(int xPos, int yPos, bool ate, bool breedable)
{
}

void Doodlebug::move()
{
	switch (dir)
	{
	case 0: //Up
		if (yPos == 0)
		{
			yPos = boardHeight;
		}
		else
		{
			yPos--;
		}
		break;

	case 1: //Right
		if (xPos == boardWidth)
		{
			xPos = 0;
		}
		else
		{
			xPos++
		}
		break;

	case 2: //Down
		if (yPos == boardHeight)
		{
			yPos = 0;
		}
		else
		{
			yPos--;
		}
		break;

	case 3: //Left
		if (xPos == 0)
		{
			xPos = boardWidth;
		}
		else
		{
			xPos--;
		}
		break;
	}
}

void Doodlebug::turn()
{

}
