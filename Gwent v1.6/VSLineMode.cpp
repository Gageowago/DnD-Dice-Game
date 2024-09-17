/******************************************************************
*   Authors:    Gage Jones, Mason Dye
*   Date:       Sunday, August 1st, 2021
*   Version:    1.6
*   Title:      VSLineMode.cpp
*   Purpose:    Holds the entire code for the VS "online" player mode
******************************************************************/

#include "Gwent.h"

void GameScore::vsLine()
{
    char answerChar;
    // Confirms user's decision:
    cout << "Play vs out-of-system player, Are you sure? (Y/N)\n\n";
    cin >> answerChar;

    // Validates user's choice:
    while(answerChar != 'Y' && answerChar != 'y' && answerChar != 'N' && answerChar != 'n')
    {
        cout << "Invalid Input, please input either Y or N\n";
        cin >> answerChar;
    }

    // If user confirms:
    if (answerChar == 'Y' || answerChar == 'y')
    {
        // Displays Round 1:
        cout << "---------------------\n";
        cout << "Round One! Roll!\n";
        cout << "---------------------\n";

        pressAnyKeyToContinue();

        // Player's turn:
        round1.player1.rollD12(); 
        round1.player1.addRoll(); 

        // Runs deception check for Player:
        deceiveCheck();

        // Does win-validation for Player:
        winValidation(); 
        
        // Displays Round 2:
        cout << "---------------------\n";
        cout << "Round Two! Roll!\n";
        cout << "---------------------\n";

        pressAnyKeyToContinue();

        // Reuses player's last round: (for continuity's sake)
        round2.setPlayer1(round1.getPlayer1());

        // Player's turn:
        round2.player1.rollD12();
        round2.player1.addRoll();

        // Does win-validation for Player:
        winValidation();
        
        // If the game hasn't been decided, goes to Round 3:
        if (gameWinner == 0)
        {
            // Displays Round 3:
            cout << "---------------------\n";
            cout << "Round Three! Roll!\n";
            cout << "---------------------\n";

            pressAnyKeyToContinue();
            
            // Reuses player's last round: (for continuity's sake)
            round3.setPlayer1(round2.getPlayer1());

            // Player's turn:
            round3.player1.rollD12();
            round3.player1.addRoll();

            // Does win-validation for Player:
            winValidation();
        }
    }
}