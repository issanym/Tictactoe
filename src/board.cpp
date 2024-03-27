#include "board.h"
#include <iomanip>
#include <iostream>

using namespace std;

board::board()
{
    ;
}

void board::getBoard()
{

    cout << "0---------0---------0---------0\n"
         << "| " << setw(10) << " | " << setw(10) << " | " << setw(10) << " |\n"
         << "| "<< setw(7) << playerPos[0]<<" | " << setw(7) << playerPos[1]<<" | " << setw(7)<<playerPos[2]<<" |\n"
         << "| " << setw(10) << " | " << setw(10) << " | " << setw(10) << " |\n"
         << "0---------0---------0---------0\n"
         << "| " << setw(10) << " | " << setw(10) << " | " << setw(10) << " |\n"
         << "| "<< setw(7) << playerPos[3]<<" | " << setw(7) << playerPos[4]<<" | " << setw(7)<<playerPos[5]<<" |\n"
         << "| " << setw(10) << " | " << setw(10) << " | " << setw(10) << " |\n"
         << "0---------0---------0---------0\n"
         << "| " << setw(10) << " | " << setw(10) << " | " << setw(10) << " |\n"
         << "| "<< setw(7) << playerPos[6]<<" | " << setw(7) << playerPos[7]<<" | " << setw(7)<<playerPos[8]<<" |\n"
         << "| " << setw(10) << " | " << setw(10) << " | " << setw(10) << " |\n"
         << "0---------0---------0---------0\n";
}

bool board::setPosition(int pos, char label)
{
    if(playerPos[pos-1]=='X' || playerPos[pos-1]=='O') // Check if the entered position is free
    {
        playable=true; // see this TRUE as !TRUE, it's this way for logic reason that I do not remember
    }
    else
    {
        playerPos[pos-1]= label; // positions stored in an array but let's assume the plyer dont understand the array positioning
        playable=false;
    }

    return playable;
}

int board::getWinner()
{
    int control = 0;

    // Define the winning combinations
    int winningCombinations[8][3] =
    {
        {0, 1, 2}, // top row
        {3, 4, 5}, // middle row
        {6, 7, 8}, // bottom row
        {0, 3, 6}, // left column
        {1, 4, 7}, // middle column
        {2, 5, 8}, // right column
        {0, 4, 8}, // diagonal (top-left to bottom-right)
        {2, 4, 6}  // diagonal (top-right to bottom-left)
    };

    // Iterate through each winning combination
    for (int i = 0; i < 8; ++i)
    {
        int pos1 = winningCombinations[i][0];
        int pos2 = winningCombinations[i][1];
        int pos3 = winningCombinations[i][2];

        // Check if all three positions in the winning combination have the same value
        if (playerPos[pos1] != ' ' && playerPos[pos1] == playerPos[pos2] && playerPos[pos2] == playerPos[pos3])
        {
            cout << "Player " << playerPos[pos1] << " Won!" << endl;
            control = 13;
            break; // Exit the loop since we found a winner
        }
    }

    /*
     * add a tie case where you check if every boxes are occupied
     * but none of them checks the above cases
    */
    return control;
}
