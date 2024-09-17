/******************************************************************
*   Authors:    Gage Jones, Mason Dye
*   Date:       Sunday, August 1st, 2021
*   Version:    1.6
*   Title:      QuickBotDifficulties.cpp
*   Purpose:    Holds the functions that control the bot's 
*               difficulty in the Quick Mode
******************************************************************/

#include "Gwent.h"


/***************************
*    EASY BOT DIFFICULTY   *
***************************/
void Player::qEasyBotAddRoll()
{
    // Keeps track of which die to roll:
    int choice;

    // If d12 is >= 8, then it will go high.
    // Otherwise, it will go low:
    if (d12 >= 8)
        choice = 8;
    else if (d12 >= 5 && d12 < 8)
        choice = 6;
    else
        choice = 4;

    // Switches between going high and going low:
    switch (choice)
    {
        // Going low:
        case 4:
            if (!d4)
            {
                if (!d6)
                {
                    botRollD8();
                }
                else
                {
                    botRollD6();
                }
            }
            else
            {
                botRollD4();
            }

            break;
        
        // Going medium:
        case 6:
            if (!d6)
            {
                if (!d4)
                {
                    botRollD8();
                }
                else
                {
                    botRollD4();
                }
            }
            else
            {
                botRollD6();
            }

            break;

        // Going high:
        case 8:
            if (!d8)
            {
                if (!d6)
                {
                    botRollD4();
                }
                else
                {
                    botRollD6();
                }
            }
            else
            {
                botRollD8();
            }

            break;
    }
}

/***************************
*    MEDIUM BOT DIFFICULTY   *
***************************/
void Player::qMedBotAddRoll()
{
    // Keeps track of which die to roll:
    int choice;

    // If d12 is >= 8, then it will go low.
    // Otherwise, it will go higher:
    if (d12 >= 8)
        choice = 4;
    else if (d12 >= 5 && d12 < 8)
        choice = 6;
    else
        choice = 8;

    // Switches between going high and going low:
    switch (choice)
    {
        // Going low:
        case 4:
            if (!d4)
            {
                if (!d6)
                {
                    botRollD8();
                }
                else
                {
                    botRollD6();
                }
            }
            else
            {
                botRollD4();
            }
            break;
        
        // Going medium:
        case 6:
            if (!d6)
            {
                if (!d4)
                {
                    botRollD8();
                }
                else
                {
                    botRollD4();
                }
            }
            else
            {
                botRollD6();
            }

            break;

        // Going high:
        case 8:
            if (!d8)
            {
                if (!d6)
                {
                    botRollD4();
                }
                else
                {
                    botRollD6();
                }
            }
            else
            {
                botRollD8();
            }
            break;
    }
}

/***************************
*    HARD BOT DIFFICULTY   *
***************************/
void Player::qHardBotAddRoll()
{
    // Keeps track of which die to roll:
    int choice;

    // If d12 is >= 8, then it will go medium.
    //It will go low if it rolls low, to fake out the player
    // Otherwise, it will go high:
    if (d12 >= 8)
        choice = 6;
    else if (d12 <= 5)
        choice = 4;
    else
        choice = 8;

    // Switches between going high and going low:
    switch (choice)
    {
        // Going low:
        case 4:
            if (!d4)
            {
                if (!d6)
                {
                    rBotRollD8();
                }
                else
                {
                    rBotRollD6();
                }
            }
            else
            {
                rBotRollD4();
            }
                
            break;
        
        // Going medium:
        case 6:
            if (!d6)
            {
                if (!d4)
                {
                    rBotRollD8();
                }
                else
                {
                    rBotRollD4();
                }
            }
            else
            {
                rBotRollD6();
            }

            break;

        // Going high:
        case 8:
            if (!d8)
            {
                if (!d6)
                {
                    rBotRollD4();
                }
                else
                {
                    rBotRollD6();
                }
            }
            else
            {
                rBotRollD8();
            }

            break;
    }
}


/***************************
*    LUNATIC BOT DIFFICULTY   *
***************************/
void Player::qLunaticBotAddRoll()
{
    // Keeps track of which die to roll:
    int choice;

    // If d12 is >= 8, then it will go medium.
    //It will go low if it rolls low, to fake out the player
    // Otherwise, it will go high:
    if (d12 >= 8)
        choice = 6;
    else if (d12 <= 5)
        choice = 4;
    else
        choice = 8;

    // Switches between going high and going low:
    switch (choice)
    {
        // Going low:
        case 4:
            if (!d4)
            {
                if (!d6)
                {
                    cBotRollD8();
                }
                else
                {
                    cBotRollD6();
                }
            }
            else
            {
                cBotRollD4();
            }
                
            break;
        
        // Going medium:
        case 6:
            if (!d6)
            {
                if (!d4)
                {
                    cBotRollD8();
                }
                else
                {
                    cBotRollD4();
                }
            }
            else
            {
                cBotRollD6();
            }

            break;

        // Going high:
        case 8:
            if (!d8)
            {
                if (!d6)
                {
                    cBotRollD4();
                }
                else
                {
                    cBotRollD6();
                }
            }
            else
            {
                cBotRollD8();
            }

            break;
    }
}