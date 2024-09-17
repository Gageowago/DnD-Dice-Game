/******************************************************************
*   Authors:    Gage Jones, Mason Dye
*   Date:       Sunday, August 1st, 2021
*   Version:    1.6
*   Title:      BotRDiceFunctions.cpp
*   Purpose:    Holds the functions for bots rolling rigged dice
******************************************************************/

#include "Gwent.h"

void Player::rBotRollD12()
{
    // "Rolls the die", sets d12 roll to random number 6-12:
    d12 = (rand() %7) + 6;

    // Displays roll to user:
    cout << "DEBUG MODE: Bot rolled a " << d12 << "!\n";
}

void Player::rBotRollD8()
{
    dieType = 8;
    dieNum = (rand() %4) + 5;
    cout << "DEBUG MODE: Bot rolled a " << dieNum << "!\n";
    cout << "DEBUG MODE: In total, bot rolled a " << d12 + dieNum << "!\n";
    d8 = false;
    finalScore = d12 + dieNum;
}

void Player::rBotRollD6()
{
    dieType = 6;
    dieNum = (rand() %3) + 4;
    cout << "DEBUG MODE: Bot rolled a " << dieNum << "!\n";
    cout << "DEBUG MODE: In total, bot rolled a " << d12 + dieNum << "!\n";
    d6 = false;
    finalScore = d12 + dieNum;
}

void Player::rBotRollD4()
{
    dieType = 4;
    dieNum = (rand() % 2) + 3;
    cout << "DEBUG MODE: Bot rolled a " << dieNum << "!\n";
    cout << "DEBUG MODE: In total, bot rolled a " << d12 + dieNum << "!\n";
    d4 = false;
    finalScore = d12 + dieNum;
}
