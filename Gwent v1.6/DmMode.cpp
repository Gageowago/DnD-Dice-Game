/******************************************************************
*   Authors:    Gage Jones, Mason Dye
*   Date:       Sunday, August 1st, 2021
*   Version:    1.6
*   Title:      DmMode.cpp
*   Purpose:    Holds the entire code for the DM mode
******************************************************************/

#include "Gwent.h"

void GameScore::dmMode()
{
    char answer;

    cout << "\n\nWould you like to do Player vs Player or vs an NPC? (1 or 2)\n\n";
    cin >> answer;

    // Validates user's choice:
    while(answer != '1' && answer != '2')
    {
        cout << "Invalid Input, please input either 1 or 2\n";
        cin >> answer;
    }

    // If user chooses vs Player:
    if (answer == '1')
    {
        cout << "PVP CUSTOMIZATION MENU:\n\n"
            << " _______________________________________________________________________________ \n"
            << "| What would you like to customize?\n                                           |\n"
            << "| (1) If cheating is possible?\n                                                |\n"
            << "| (2) Set DCs for player deceive check or make them contest each other normally?|\n"
            << "| (3) Play!                                                                     |\n"
            << "| (4) Return to Menu                                                            |\n"
            << "|_______________________________________________________________________________|\n"
            << "Input 1-4\n";
        cin  >> answer;
        cout << "\n";

        switch (answer)
        {
            case '1':
                break;
            case '2':
                break;
            case '3':
                break;
            default:
        }
    }
    
    else if (answer == '2')
    {
        cout << "VS BOT CUSTOMIZATION MENU:\n\n"
            << " _______________________________________________________________________________ \n"
            << "| What would you like to customize?                                             |\n"
            << "| (1) Bot Difficulty                                                            |\n"
            << "| (2) Bot Cheats?                                                               |\n"
            << "| (3) Rigged Dice Rolls?                                                        |\n"
            << "| (4) Set DCs                                                                   |\n"
            << "| (5) How good the bot's perception is to player cheating                       |\n"
            << "| (6) The NPC's Name                                                            |\n"
            << "| (7) Play!                                                                     |\n"
            << "| (8) Return to Menu                                                            |\n"
            << "|_______________________________________________________________________________|\n"
            << "Input 1-8\n";
        cin  >> answer;
        cout << "\n";

        switch (answer)
        {
            case '1':
                break;
            case '2':
                break;
            case '3':
                break;
            case '4':
                break;
            case '5':
                break;
            case '6':
                break;
            case '7':
                break;
            default:
        }
    }
}