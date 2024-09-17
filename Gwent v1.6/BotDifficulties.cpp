/******************************************************************
*   Authors:    Gage Jones, Mason Dye
*   Date:       Sunday, August 1st, 2021
*   Version:    1.6
*   Title:      BotDifficulties.cpp
*   Purpose:    Holds the functions that control the bot's 
*               difficulty in the VS BOT mode
******************************************************************/

#include "Gwent.h"


/***************************
*    EASY BOT DIFFICULTY   *
***************************/
void Player::easyBotAddRoll()
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
                    cout << "They seem elated about their roll, and then roll their D8?...\n";
                }
                else
                {
                    botRollD6();
                    cout << "They seem satisfied with their roll, and then roll their D6\n";
                }
            }
            else
            {
                botRollD4();
                cout << "Their face sinks as they see their roll, and then... They roll their D4...\n";
            }

            break;
        
        // Going medium:
        case 6:
            if (!d6)
            {
                if (!d4)
                {
                    botRollD8();
                    cout << "They seem very happy about their roll, and then roll their D8?...\n";
                }
                else
                {
                    botRollD4();
                    cout << "Their face sinks as they see their roll, and then... They roll their D4...\n";
                }
            }
            else
            {
                botRollD6();
                cout << "They seem satisfied with their roll, and then roll their D6\n";
            }

            break;

        // Going high:
        case 8:
            if (!d8)
            {
                if (!d6)
                {
                    botRollD4();
                    cout << "Their face sinks as they see their roll, and then... They roll their D4...\n";
                }
                else
                {
                    botRollD6();
                    cout << "They seem satisfied with their roll, and then roll their D6\n";
                }
            }
            else
            {
                botRollD8();
                cout << "They seem very happy about their roll, and then roll their D8?...\n";
            }

            break;
    }
}

/***************************
*    MEDIUM BOT DIFFICULTY   *
***************************/
void Player::medBotAddRoll()
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
                    cout << "Their face is mildly perturbed as they roll their D8\n";
                }
                else
                {
                    botRollD6();
                    cout << "Their face seems to say what they rolled was alright, as they roll their D6\n";
                }
            }
            else
            {
                botRollD4();
                cout << "Their face seems to suggest mild confidence, as they roll their D4\n";
            }
            break;
        
        // Going medium:
        case 6:
            if (!d6)
            {
                if (!d4)
                {
                    botRollD8();
                    cout << "Their face is mildly perturbed as they roll their D8\n";
                }
                else
                {
                    botRollD4();
                    cout << "Their face seems to suggest mild confidence, as they roll their D4\n";
                }
            }
            else
            {
                botRollD6();
                cout << "Their face seems to say what they rolled was alright, as they roll their D6\n";
            }

            break;

        // Going high:
        case 8:
            if (!d8)
            {
                if (!d6)
                {
                    botRollD4();
                    cout << "Their face seems to suggest mild confidence, as they roll their D4\n";
                }
                else
                {
                    botRollD6();
                    cout << "Their face seems to say what they rolled was alright, as they roll their D6\n";
                }
            }
            else
            {
                botRollD8();
                cout << "Their face is mildly perturbed as they roll their D8\n";
            }
            break;
    }
}

/***************************
*    HARD BOT DIFFICULTY   *
***************************/
void Player::hardBotAddRoll()
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
                    cout << "A dark shadow casts over their face, they seem slightly disappointed with their roll as they roll their D8\n";
                }
                else
                {
                    rBotRollD6();
                    cout << "Their poker face is unchanging as they roll their D6\n";
                }
            }
            else
            {
                rBotRollD4();
                cout << "Their poker face slightly breaks as they confidently roll their D4\n";
            }
                
            break;
        
        // Going medium:
        case 6:
            if (!d6)
            {
                if (!d4)
                {
                    rBotRollD8();
                    cout << "A dark shadow casts over their face, they seem slightly disappointed with their roll as they roll their D8\n";
                }
                else
                {
                    rBotRollD4();
                    cout << "Their poker face slightly breaks as they confidently roll their D4\n";
                }
            }
            else
            {
                rBotRollD6();
                cout << "Their poker face is unchanging as they roll their D6\n";
            }

            break;

        // Going high:
        case 8:
            if (!d8)
            {
                if (!d6)
                {
                    rBotRollD4();
                    cout << "Their poker face slightly breaks as they confidently roll their D4\n";
                }
                else
                {
                    rBotRollD6();
                    cout << "Their poker face is unchanging as they roll their D6\n";
                }
            }
            else
            {
                rBotRollD8();
                cout << "A dark shadow casts over their face, they seem disappointed with their roll as they roll their D8\n";
            }

            break;
    }
}


/***************************
*    LUNATIC BOT DIFFICULTY   *
***************************/
void Player::lunaticBotAddRoll()
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
                    cout << "They slightly grimace, there is a hint of disappointment on their stoic face as they roll their D8\n";
                }
                else
                {
                    cBotRollD6();
                    cout << "Their stone cold poker face is unmmoving as they roll their D6\n";
                }
            }
            else
            {
                cBotRollD4();
                cout << "They roll their D4 with a slight smirk\n";
            }
                
            break;
        
        // Going medium:
        case 6:
            if (!d6)
            {
                if (!d4)
                {
                    cBotRollD8();
                    cout << "They slightly grimace, there is a hint of disappointment on their stoic face as they roll their D8\n";
                }
                else
                {
                    cBotRollD4();
                    cout << "They roll their D4 with a slight smirk\n";
                }
            }
            else
            {
                cBotRollD6();
                cout << "Their stone cold poker face is unmmoving as they roll their D6\n";
            }

            break;

        // Going high:
        case 8:
            if (!d8)
            {
                if (!d6)
                {
                    cBotRollD4();
                    cout << "They roll their D4 with a slight smirk\n";
                }
                else
                {
                    cBotRollD6();
                    cout << "Their stone cold poker face is unmmoving as they roll their D6\n";
                }
            }
            else
            {
                cBotRollD8();
                cout << "They slightly grimace, there is a hint of disappointment on their stoic face as they roll their D8\n";
            }

            break;
    }
}