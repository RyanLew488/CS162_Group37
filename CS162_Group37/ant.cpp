/*******************************************************************************
 ** Ant Class
 **     This is the implementation file for the ant class and contains all the 
 **     member variables and member functions for ant.
 ******************************************************************************/
#include "ant.hpp"
#include "board.hpp"
#include <random>


Ant::Ant(int row, int col, Critter***board)
{
    this->board = board;
    // setting y position will be determined in Critter
    setR(row);
    // setting x position will be determined in Critter
    setC(col);
    steps = 0;
}

void Ant::breed()
{
    /*
        #1: need to see if ant has taken 3 steps before it can breed
            ant needs to look up, right, down, left
        #2: look at ants position and adjacent cells to see if there's space for baby
        #3: must see which ones are valid breeding spaces
        #4: must check to see if ant hits wall
        #5: looks up, right, down, left which one = nullptr

    */

   if (steps >=3)
   {
       // If ant has progressed 3 steps, it can breed
       // ant needs to confirm it's location and look at it's surrounding
       // function checks ants surrounding to make sure there's no Critter and
       // puts a critter there if it's out of board bound
        Critter ** arr = getAvailability();

        // for loop to set counter which tells us which sides are empty
        int count = 0;
        for (int i = 0; i < 4; i++)
        {
            if (arr[i] == nullptr)
            {
                count++;
            }
        }

        // with count for nullptrs we need to generate values to breed
        // https://stackoverflow.com/questions/19665818/generate-random-numbers-using-c11-random-library
        Critter** breeding = nullptr;
        if (count > 0)
        {
            std::random_device rd;
            std::mt19937 mt(rd());
            // generate random number 0 - whatever minus one
            std::uniform_real_distribution<int> dir(0,count-1);

            breeding = {
                board[row+1][col], //up
                board[row-1][col], //down
                board[row][col-1], //left
                board[row][col+1]; //right , corresponds to array from top
            };
        
       
            int temp = 0;
            for (int i = 0; i < 4; i++)
            {
                if (arr[i] == nullptr)
                {
                    temp++;
                    if (temp == dir)
                    {
                        int r = row + convertDirToRowCol(i)[0];
                        int c = col + convertDirToRowCol(i)[0];
                        breeding[i] = new Ant(r,c, this->board);
                        break;
                }
            }
            }
        }
        steps = 0;
   }      
}

void Ant::move()
{
    // check if there's something there, if not move

    Critter** arr = getAvailability();

    // get count of how many sides are open
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        if (arr[i] == nullptr)
        {
            count++;
        }
    }

    if (count >0)
    {
        board[row][col] = nullptr;

         std::random_device rd;
         std::mt19937 mt(rd());
         std::uniform_real_distribution<int> dir(0,count-1); 

         Critter * moving = {
         board[row+1][col], //up
         board[row-1][col], //down
         board[row][col-1], //left
         board[row][col+1] }; //right, correspoding to arr, from the top

         int temp = 0;
         for (int i = 0; i < 4; i++)
         {
             if (arr[i] == nullptr)
             {
                 temp++;
                 if(temp == count)
                 {
                    int r = convertDirToRowCol(i)[0];
                    int c = convertDirToRowCol(i)[1];
                    this-> row = r;
                    this-> col = c;
                    step++;
          
                    moving[i] = board[row][col];
					board[row][col] = nullptr
                    break;
                 }
             }
         }

    }



}

int * convertDirToRowCol(int dir)
{
    int * arr = nullptr;
    if (dir == 0)
    {
        // up
        arr = {1,0};
        return arr;
    }
    else if (dir == 1)
    {
        //down
        arr = {-1,0};
        return arr;
    }
    else if (dir == 2)
    {
        arr = {0,-1};
    }
    else if (dir == 3)
    {
        arr = {0,1};
        return arr;
    }
    throw string ("Dir should not be between 0-3, inclusively.");
}

Critter** Ant::getAvailability()
{
    {
        Critter*    up = nullptr,
                    down = nullptr,
                    left = nullptr,
                    right = nullptr,
        
        Critter **arr = {up, down, left, right};

        if (row == 0)
        [
            up = new Critter();
        ]
        else
        {
            up = board[row+1][col];
        }

        // 20x20 size of board to begin with, this can be altered
        if (row == 19)
        {
            down = new Critter();
        }
        else 
        {
            down = board[row-1][col];
        }

        if (col == 0)
        {
            left = new Critter();
        }
        else
        {
            left = board[row[col-1]];
        }

        if (col == 19)
        {
            right = new Critter();
        }
        else
        {
            right = board[row[col+1]];
        }

        return arr;
    }

    // either critter or nullptr being returned
}

void Ant::tick()
{
    move();
    breed();
}


