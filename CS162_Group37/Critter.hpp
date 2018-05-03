/********************************************************************* 
** Author: CS162 Team 37
** Date: 5/13/2018
** Group Project: Predator-Prey Game
** Description: Header file to define the interface of the Critter class
*********************************************************************/ 
// Critter.hpp

#ifndef CRITTER_HPP
#define CRITTER_HPP

#include <iostream>
#include <string>

// Declare specific using statements to avoid namespace pollution

using std::cout;
using std::cin;
using std::endl;

enum Direction {UP, RIGHT, DOWN, LEFT};

class Critter
{
private: 

    int dayBirth;
    int dayLastBred;
    int species;

protected:

    // setters
    void set_species(int initSpecies);
    void set_dayBirth(int initDayBirth);

public:

	// constructor
	Critter(int day);

    // destructor
    virtual ~Critter();

    // getters
	int get_dayBirth();
	int get_species();
	int get_dayLastBred();


	// setters
    void set_dayLastBred(int newDayLastBred);

    // class methods
    // virtual functions defined in the derived classes of Ant and Doodlebug
    virtual void move() = 0;
    virtual void breed() = 0;
	
};
#endif
