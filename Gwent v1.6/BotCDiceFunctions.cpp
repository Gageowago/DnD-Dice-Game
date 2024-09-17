/******************************************************************
*   Authors:    Gage Jones, Mason Dye
*   Date:       Sunday, August 1st, 2021
*   Version:    1.6
*   Title:      BotCDiceFunctions.cpp
*   Purpose:    Holds the functions for bots rolling cheating dice
                essentially making them always roll max on rolls
******************************************************************/

#include "Gwent.h"


void Player::cBotRollD8()
{
    dieType = 8;
    dieNum = (rand() %4) + 5 + ((rand() %8) + 1);
    if(dieNum > 8)
        dieNum = 8;
    cout << "DEBUG MODE: Bot rolled a " << dieNum << "!\n";
    cout << "DEBUG MODE: In total, bot rolled a " << d12 + dieNum << "!\n";
    d8 = false;
    finalScore = d12 + dieNum;
}

void Player::cBotRollD6()
{
    dieType = 6;
    dieNum = (rand() %3) + 4 + ((rand() %6) + 1);
    if(dieNum > 6)
        dieNum = 6;
    cout << "DEBUG MODE: Bot rolled a " << dieNum << "!\n";
    cout << "DEBUG MODE: In total, bot rolled a " << d12 + dieNum << "!\n";
    d6 = false;
    finalScore = d12 + dieNum;
}

void Player::cBotRollD4()
{
    dieType = 4;
    dieNum = (rand() %2) + 3 + ((rand() %4) + 1);
    if(dieNum > 4)
        dieNum = 4;
    cout << "DEBUG MODE: Bot rolled a " << dieNum << "!\n";
    cout << "DEBUG MODE: In total, bot rolled a " << d12 + dieNum << "!\n";
    d4 = false;
    finalScore = d12 + dieNum;
}
