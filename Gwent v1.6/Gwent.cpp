/******************************************************************
*   Authors:    Gage Jones, Mason Dye
*   Date:       Sunday, August 1st, 2021
*   Version:    1.6
*   Title:      Gwent
*   Purpose:    Plays Gwent, a mini-game from Witcher to be used in
*               a quest of Dungeons and Dragons!
******************************************************************/

#include "Gwent.h"

int main() // 
{
    // Initialization:
    bool repeatGame = true;
    char answerChar;
    string answerString;
    GameScore game;

    // Setting the random seed to time-based:
    srand(time(0));

    // Main do-while loop:
    do
    {
        // Display the Main Menu:
        displayMainMenu(answerChar);

        // Switches based on what the user enters:
        switch(answerChar)
        {
            case '1':
                game.vsBot();
                break;
            
            // Code for Local 2-Player Match:
            case '2':
                game.vsLocal();
                break;
            
            // Code for "Online" Player vs. Player:
            case '3':
                game.vsLine();
                break;

            // Case for DM-Mode:
            case '4':
                cout << "Yeah... this is gonna take a while... Come back later!\n";
                break;

            case '5':
                game.quickMode();
                break;

            // Prints the instructions of the game:
            case '6':
                printInstruct();
                break;

            // Exits the program:
            case '7':
                cout << "Thanks for playing!\n"
                     << "Press any key to quit...\n";
                getch();
                
                // Ends Program:
                return 0;
                break;
        }
        
        // Resets game:
        game.reset();
    }
    while (repeatGame);

    // End of Program:
    return 0;
}
