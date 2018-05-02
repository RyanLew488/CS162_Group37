/*********************************************************************
** Program name: main.cpp
** Assignment: Demo for Menu and Validation
** Author: David Coons
** Date: May 1, 2018
** 
** What does it do: 
** Demonstrates functionality and use of Menu class and validation 
** functions.
** 
** HOW TO RUN
** You can use the provided makefile functions to compile and run
** this program:
**
** make - compiles project and creates executable
** make debug - compiles, creates executable, and runs program using
**      Valgrind etc
** make quickrun - like debug, but without Valgrind
** make zip - will zip all files in directory with the specified 
**      file extension (see makefile for details)
** make clean - deletes *.o and the executable
**
*********************************************************************/

#include <iostream>
#include <string>
#include "menu.hpp"
#include "validation.hpp"


int main()
{
    // Creating a menu
    // Constructor takes menu title as parameter
    Menu mainMenu("***SELECT A CHOICE FROM MAIN MENU***");
    // Each menu option will appear in the order they are added
    // Begins at 1
    mainMenu.add("Quit");
    mainMenu.add("Option 2");
    mainMenu.add("Go to second menu");

    // Demonstrating use of a secondary menu
    Menu secondMenu("***SELECT AN OPTION - SECOND MENU***");
    secondMenu.add("Option 1");
    secondMenu.add("Option 2");
    secondMenu.add("Option 3");


    std::cout << "\n\n\n\n=====MENU DEMO BEGIN=====\n\n" << std::endl;
    

    int flagExit = 0;

    // Loop until quit from main menu
    while (!flagExit)
    {
        // Menu::run() returns an int (the option 1-x that the user chose)
        switch (mainMenu.run())
        {
            case 1:
                flagExit = 1;
                break;
            case 2:
                std::cout << "You chose main menu opt 2" << std::endl;
                break;
            case 3:
                std::cout << "You chose main menu opt 3" << std::endl;
                std::cout << "Second menu choice: " << secondMenu.run() << std::endl;
                break;
        }

        std::cout << std::endl;
    }

    std::cout << "\n\n=====MENU DEMO END=====\n\n\n\n" << std::endl;


    std::cout << "\n\n\n\n=====VALIDATION DEMO BEGIN=====\n\n" << std::endl;

    // Menu to assist with validation demo
    Menu validationMenu("***DATA TYPES FOR VALIDATION***");
    validationMenu.add("Quit");
    validationMenu.add("Integer - no range");
    validationMenu.add("Integer - range");
    validationMenu.add("Double - no range");
    validationMenu.add("Double - range");
    validationMenu.add("String - no length");
    validationMenu.add("String - length");

    // Variables to hold the user's input
    int userInt;
    double userDouble;
    std::string userString;

    // Use the variables below to specify a range (inclusive)
    // If no range specified for int/dbl, validation functions default to global max/min
    //      values for the specific data type
    // If no range specified for String, min = 1 and max = max_size() of provided
    //      string variable
    int intMin = -5;
    int intMax = 10;
    double dblMin = 2.3;
    double dblMax = 27.534;
    int strMin = 5;
    int strMax = 15;



    // Flag to indicate whether valid input was given
    // 0 - not good
    // 1 - good
    int flagValid;

    flagExit = 0;
    while (!flagExit)
    {
        switch (validationMenu.run())
        {
            case 1:
                flagExit = 1;
                break;
            case 2:
                // Loop until valid int provided
                do
                {
                    std::cout << "Enter an int (no range): ";
                    flagValid = getValidInput(&userInt);
                } while(!flagValid);

                std::cout << "***Valid entry: " << userInt << std::endl;

                break;
            case 3:
                do
                {
                    std::cout << "Enter an int (range): ";
                    flagValid = getValidInput(&userInt, intMin, intMax);
                } while(!flagValid);

                std::cout << "***Valid entry: " << userInt << std::endl;

                break;
            case 4:
                // Slightly simplified by not using flagValid
                do
                {
                    std::cout << "Enter a double (no range): ";
                } while(!getValidInput(&userDouble));

                std::cout << "***Valid entry: " << userDouble << std::endl;
                
                break;
            case 5:
                do
                {
                    std::cout << "Enter a double (range): ";
                } while(!getValidInput(&userDouble, dblMin, dblMax));

                std::cout << "***Valid entry: " << userDouble << std::endl;

                break;
            case 6:
                do
                {
                    std::cout << "Enter a string (no length range): ";
                } while(!getValidInput(&userString));

                std::cout << "***Valid entry: " << userString << std::endl;

                break;
            case 7:
                do
                {
                    std::cout << "Enter a string (length range): ";
                } while(!getValidInput(&userString, strMin, strMax));

                std::cout << "***Valid entry: " << userString << std::endl;

                break;
        }

        std::cout << "\n\n\n" << std::endl;
    }

    std::cout << "\n\n\n\n=====VALIDATION DEMO END=====\n\n" << std::endl;

    return 0;
}