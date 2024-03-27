#ifndef BOARD_H
#define BOARD_H


class board
{
private:
    //int positions[9];
    char playerPos[9]={' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' '}; // the actual board. should be called board not player position
    bool playable = true;
public:
    board();
    void getBoard();
    bool setPosition(int, char);
    int getWinner();
};

#endif // BOARD_H
