#include <iostream>
#include <random>
#include "board.h"
#include "player.h"

using namespace std;

int main()
{
    //cout << "Hello World! " << endl;

    board a;
    player Fplayer('X'), sPlayer('O');
    a.getBoard();
    int game=0;

    for(int i=0;i<5;i++) // 5 = number of turns for player X
    {
        bool permission= true; // permission to play

        do
        {
            cout << "Enter position player X: ";
            int posi;
            cin >> posi;
            permission = a.setPosition(posi, Fplayer.getLabel());
        }while(permission);

        a.getBoard();

        if(a.getWinner()>i) // check for the winner
            i=13;

        for(int j=i; j==i && j<4; j++) // 4 = number of turns for player O. j always == to i to allow one turn per playr
        {
            bool permission = true;

            do
            {
                cout << "Enter position player O: ";
                int pos2;
                cin >> pos2;
                permission = a.setPosition(pos2, sPlayer.getLabel());
            }while(permission);

            a.getBoard();

            if(a.getWinner()>j)
                i=13;
        }
        game++;
    }
    if(game==4)
        cout <<"TIE mate! next time" << endl;


    return 0;
}
