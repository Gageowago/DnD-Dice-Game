/******************************************************************
*   Authors:    Gage Jones, Mason Dye
*   Date:       Sunday, August 1st, 2021
*   Version:    1.6
*   Title:      VSLocalMode.cpp
*   Purpose:    Holds the entire code for the VS local player mode
******************************************************************/

#include "Gwent.h"

void GameScore::vsLocal()
{
    char answerChar;
    // Confirms user's decision:
    cout << "Play vs local player, Are you sure? (Y/N)\n\n";
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

        cout << "-------------------------------------- PLAYER 1'S TURN --------------------------------------\n";
        cout << "------------------------------- PLAYER 2 LOOK AWAY FROM THE SCREEN -------------------------------\n";
        round1.player1.rollD12(); 
        round1.player1.addRoll(); 

        // Runs deception check for Player 1:
        round1.pvp1DeceptionCheck();

        cout << "-------------------------------------- PLAYER 2'S TURN --------------------------------------\n";
        cout << "------------------------------- PLAYER 1 LOOK AWAY FROM THE SCREEN -------------------------------\n";
        
        // Runs perception check for Player 2:
        round1.pvp2PerceptionCheck();

        round1.player2.rollD12();
        round1.player2.addRoll();

        // Does win-validation for the Players:
        pvpWinValidation(); 
        
        // Displays Round 2:
        cout << "---------------------\n";
        cout << "Round Two! Roll!\n";
        cout << "---------------------\n";

        pressAnyKeyToContinue();

        // Reuses players' last round: (for continuity's sake)
        round2.setPlayer1(round1.getPlayer1());
        round2.setPlayer2(round1.getPlayer2());

        cout << "-------------------------------------- PLAYER 2'S TURN --------------------------------------\n";
        cout << "------------------------------- PLAYER 1 LOOK AWAY FROM THE SCREEN -------------------------------\n";
        round2.player2.rollD12(); 
        round2.player2.addRoll(); 

        // Runs deception check for Player 2:
        round2.pvp2DeceptionCheck();

        cout << "-------------------------------------- PLAYER 1'S TURN --------------------------------------\n";
        cout << "------------------------------- PLAYER 2 LOOK AWAY FROM THE SCREEN -------------------------------\n";
        
        // Runs perception check for Player 1:
        round2.pvp1PerceptionCheck();

        round1.player2.rollD12();
        round1.player2.addRoll();

        // Does win-validation for the Players:
        pvpWinValidation(); 
        
        // If the game hasn't been decided, goes to Round 3:
        if (gameWinner == 0)
        {
            // Displays Round 3:
            cout << "---------------------\n";
            cout << "Round Three! Roll!\n";
            cout << "---------------------\n";
            
            pressAnyKeyToContinue();

            // Reuses players' last round: (for continuity's sake)
            round3.setPlayer1(round2.getPlayer1());
            round3.setPlayer2(round2.getPlayer2());

            cout << "-------------------------------------- PLAYER 1'S TURN --------------------------------------\n";
            cout << "------------------------------- PLAYER 2 LOOK AWAY FROM THE SCREEN -------------------------------\n";
            round3.player1.rollD12(); 
            round3.player1.addRoll(); 

            // Runs deception check for Player 1:
            round3.pvp1DeceptionCheck();

            cout << "-------------------------------------- PLAYER 2'S TURN --------------------------------------\n";
            cout << "------------------------------- PLAYER 1 LOOK AWAY FROM THE SCREEN -------------------------------\n";
            
            // Runs perception check for Player 2:
            round3.pvp2PerceptionCheck();

            round3.player2.rollD12();
            round3.player2.addRoll();

            // Does win-validation for the Players:
            pvpWinValidation(); 
        }
    }
}