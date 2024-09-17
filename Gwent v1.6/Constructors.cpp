/******************************************************************
*   Authors:    Gage Jones, Mason Dye
*   Date:       Sunday, August 1st, 2021
*   Version:    1.6
*   Title:      Constructors.cpp
*   Purpose:    Holds the constructors for the classes, because it 
*               wouldn't work otherwise
******************************************************************/

#include "Gwent.h"

// Player constructor:
Player::Player()
{
    d12 = 0;
    dieType = 0;
    dieNum = 0;
    finalScore = 0;
    
    //NEW CODE
    deception = 0;
    perception = 0;
    //NEW CODE

    d4 = true;
    d6 = true;
    d8 = true;
}

// Round constructor:
RoundScore::RoundScore()
{
    player1;
    player2;
}

// Game constructor:
GameScore::GameScore()
{
    winCountP1 = 0;
    winCountP2 = 0;
    lossCountP1 = 0;
    lossCountP2 = 0;
    r1Winner = 0;
    r2Winner = 0;
    r3Winner = 0;
    gameWinner = 0;
}