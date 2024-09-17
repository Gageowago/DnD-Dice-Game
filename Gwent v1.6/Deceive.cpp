/******************************************************************
*   Authors:    Gage Jones, Mason Dye
*   Date:       Sunday, August 1st, 2021
*   Version:    1.6
*   Title:      Deceive.cpp
*   Purpose:    Holds the deceiveCheck function, which makes the 
*               player roll a deception check and returns flavor text
******************************************************************/

#include "Gwent.h"

/*
CHECKS FOR PLAYER'S DECEPTION LEVEL
*/
void deceiveCheck()
{
    int decept, modifier, vantage;
    char answer;

    cout << "(Please make a deception check, this will be your value for the rest of the game):\n\n";
    cout << "\nRoll a deception check to see how good your poker face is!\n";

    pressAnyKeyToContinue();
    
    decept = (rand() % 20) + 1;

    cout << "Do you have advantage or disadvantage? (Y/N)\n";
    cin >> answer;

    while(answer != 'Y' && answer != 'N' && answer != 'y' && answer != 'n')
    {
        cout << "Invalid Input! Please enter either Y or N!\n";
        cin >> answer;
        cout << "\n";
    }

    if(answer == 'Y' || answer == 'y')
    {
        cout << "Is it advantage or disadvantage?\n"
             << "(A or D)\n";
        cin >> answer;

        while(answer != 'A' && answer != 'a' && answer != 'D' && answer != 'D')
        {
            cout << "Invalid Input! Please enter either A or D!\n";
            cin >> answer;
            cout << "\n";
        }

        if(answer == 'A' || answer == 'a')
        {
            vantage = (rand() % 20) + 1;

            if(vantage > decept)
            {
                decept = vantage;
            }
            else
                decept = decept;
        }
        if(answer == 'D' || answer == 'D')
        {
            vantage = (rand() % 20) + 1;

            if(vantage < decept)
            {
                decept = vantage;
            }
            else
                decept = decept;
        }
    }

    cout << "\nYou rolled a " << decept << "!\n"
         << " What is your deception modifier?\n";
    cin >> modifier;

    cout << "You rolled a " << decept << " plus " << modifier << " !\n" 
         << "In total that's " << decept + modifier << "!\n";

    decept = decept + modifier;

    if (decept <= 1)
    {
        cout << "You fumble your finger placement and drop all of your cards, your opponent sees your dice rolls\n";
    }

    else if (decept <= 5)
    {
        cout << "You are quite obvious about what you have, tell your opponent what you have with a margin of error of 1\n"
             << "(So if you have a 5 overall, say you have a number from 2-8)\n";
    }
    
    else if (decept <= 9)
    {
        cout << "You hide it rather well, but the enemy gets a decent idea of what you have.\n"
             << "Tell your opponent what you have with a margin of error of 3.\n"
             << "(So if you have a 5 overall, say you have a number from 4-6)\n";
    }

    else if (decept <= 14)
    {
        cout << "You hide your rolls behind a poker face, and the enemy is able to discern that you have a number between 1 and 20\n";
    }

    else if (decept <= 19)
    {
        cout << "Your poker face is so well done that the enemy is unable to make out your facial features at this point\n";
    }

    else if (decept >= 20)
    {
        cout << "You have mastered the art of sitting so incredibly still, that you are invisible to the naked eye\n";
    }
}