/******************************************************************
*   Authors:    Gage Jones, Mason Dye
*   Date:       Sunday, August 1st, 2021
*   Version:    1.6
*   Title:      DisplayDice.cpp
*   Purpose:    Holds the displayDice function, which displays
*               ASCII art of the available dice to the user.
******************************************************************/

// Include header:
#include "Gwent.h"

/******************************************************************
*   Name:       displayDice()
*   Purpose:    Displays the options for additional dice usage.
*   Input:      Boolean variables for d4, d6, and d8 dice.
*   Output:     ASCII art of dice to be used.
******************************************************************/
void Player::displayDice()
{
    // If no dice has been previously used:
    if (d4 && d6 && d8)
    {
        cout << "What die would you like to roll in addition?\n"
             << "(Type 4, 6, or 8)\n";
        cout << "  /\\    ___    /\\\n"
             << " /4 \\  | 6 |  |8 |\n"
             << "/____\\ |___|   \\/\n";
    }

    // If only d8 has been used:
    else if (d4 && d6 && !d8)
    {
        cout << "What die would you like to roll in addition?\n"
             << "(Type 4 or 6)\n";
        cout << "  /\\    ___\n"
             << " /4 \\  | 6 |\n"
             << "/____\\ |___|\n";
    }

    // If only d6 has been used:
    else if (d4 && !d6 && d8)
    {
        cout << "What die would you like to roll in addition?\n"
             << "(Type 4 or 8)\n";
        cout << "  /\\     /\\\n"
             << " /4 \\   |8 |\n"
             << "/____\\   \\/\n";
    }

    // If only d4 has been used:
    else if (!d4 && d6 && d8)
    {
        cout << "What die would you like to roll in addition?\n"
             << "(Type 6 or 8)\n";
        cout << " ___    /\\\n"
             << "| 6 |  |8 |\n"
             << "|___|   \\/\n";
    }

    // If both d6 and d8 have been used:
    else if (d4 && !d6 && !d8)
    {
        cout << "Ready to roll your last die?\n"
             << "(Type 4)\n";
        cout << "  /\\\n"
             << " /4 \\\n"
             << "/____\\\n";
    }
    
    // If d4 and d8 have been used:
    else if (!d4 && d6 && !d8)
    {
        cout << "Ready to roll your last die?\n"
             << "(Type 6)\n";
        cout << " ___\n"
             << "| 6 |\n"
             << "|___|\n";
    }
    
    // If d4 and d6 have been used:
    else if (!d4 && !d6 && d8)
    {
        cout << "Ready to roll your last die?\n"
             << "(Type 8)\n";
        cout << " /\\\n"
             << "|8 |\n"
             << " \\/\n";
    }

    // If something goes wrong and an error occurs:
    else
    {
          cout << "Error, something went wrong, fix it dumbass,\n"
               << "or tell Gage to fix it if one of you DnD players got this error.\n";
          elipAnim();
          pressAnyKeyToContinue();
    }
}