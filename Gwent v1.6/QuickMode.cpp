/******************************************************************
*   Authors:    Gage Jones, Mason Dye
*   Date:       Sunday, August 1st, 2021
*   Version:    1.6
*   Title:      QuickMode.cpp
*   Purpose:    Holds the entire code for the Quickmode
******************************************************************/

#include "Gwent.h"

// Displays bot-difficulty level and gets user input:
void GameScore::quickMode()
{
    char answerChar;

    cout << "Welcome to Quick Mode!\n"
         << "This mode allows you to quickly get a game's results!\n";

    cout << "What Bot Difficulty would you like to face:\n\n"
         << " _________________________________________ \n"
         << "|               (1) Easy                  |\n"
         << "|               (2) Medium                |\n"
         << "|               (3) Hard                  |\n"
         << "|               (4) LUNATIC               |\n"
         << "|               (5) Go Back               |\n"
         << "|_________________________________________|\n"
         << "Input 1-5\n";
    cin  >> answerChar;
    cout << "\n";

    // Validates user's input:
    while(answerChar != '1' && answerChar != '2' && answerChar != '3' && answerChar != '4' && answerChar != '5')
    {
    cout << "Invalid Input! Please input a number 1-5!\n";
    cin >> answerChar;
    cout << "\n";
    }

    // Switches between bot difficulties: (Easy, Medium, Hard, or Go Back)
    switch(answerChar)
    {
    // Code for Easy Bot:
    case '1':
    {
        // Confirms user's decision:
        cout << "Run a VS Easy Bot? (Y/N)\n\n";
        cin >> answerChar;

        // User input validation:
        while(answerChar != 'Y' && answerChar != 'y' && answerChar != 'N' && answerChar != 'n')
        {
            cout << "Invalid Input, please input either Y or N\n";
            cin >> answerChar;
        }

        // If they confirm they want to fight the easy bot:
        if(answerChar == 'Y' || answerChar == 'y')
        {
            // Display Round 1:
            cout << "---------------------\n";
            cout << "Processing Round One!\n";
            cout << "---------------------\n";

            elipAnim();
            
            // Bot's turn first:
            round1.player2.botRollD12();
            round1.player2.qEasyBotAddRoll();

            // Player's turn, then displays results of the round:
            round1.player1.botRollD12(); 
            round1.player1.qEasyBotAddRoll(); 

            autoWinValidation();
            
            // Displays Round 2:
            cout << "---------------------\n";
            cout << "Processing Round Two!\n";
            cout << "---------------------\n";

            elipAnim();

            // Sets Round 2's players to Round 1's: (for continuity's sake)
            round2.setPlayer1(round1.getPlayer1());
            round2.setPlayer2(round1.getPlayer2());

            // Player 1 aka user goes first:
            round2.player1.botRollD12();
            round2.player1.qEasyBotAddRoll();

            // Bot goes second, then displays results of the round:
            round2.player2.botRollD12();
            round2.player2.qEasyBotAddRoll();

            autoWinValidation();
            
            // If the game hasn't been decided yet, move on to Round 3:
            if (gameWinner == 0)
            {
                // Displays Round 3:
                cout << "---------------------\n";
                cout << "Processing Round Three!\n";
                cout << "---------------------\n";

                elipAnim();

                // Reuses previous players: (for continuity's sake)
                round3.setPlayer1(round2.getPlayer1());
                round3.setPlayer2(round2.getPlayer2());

                // Bot goes first:
                round3.player2.botRollD12();
                round3.player2.qEasyBotAddRoll();

                // Player's turn, then displays the results of the round:
                round3.player1.botRollD12();
                round3.player1.qEasyBotAddRoll();
                
                autoWinValidation();
            }
        }
        break;
    }

    // Code for Medium Bot:
    case '2':
    {
        // Confirms user's decision:
        cout << "Run a VS Medium Bot? (Y/N)\n\n";
        cin >> answerChar;

        // User choice validation:
        while(answerChar != 'Y' && answerChar != 'y' && answerChar != 'N' && answerChar != 'n')
        {
            cout << "Invalid Input, please input either Y or N\n";
            cin >> answerChar;
        }

        // If the user wants to continue with Medium Bot:
        if(answerChar == 'Y' || answerChar == 'y')
        {
            // Displays Round 1:
            cout << "---------------------\n";
            cout << "Processing Round One!\n";
            cout << "---------------------\n";

            elipAnim();

            // Bot goes first:
            round1.player2.botRollD12();
            round1.player2.qMedBotAddRoll();

            // Player's turn, then displays results of the round:
            round1.player1.botRollD12(); 
            round1.player1.qMedBotAddRoll(); 
            
            autoWinValidation();
            
            // Displays Round
            cout << "---------------------\n";
            cout << "Processing Round Two!\n";
            cout << "---------------------\n";

            elipAnim();

            // Reuses Players from Round 1: (for continuity's sake)
            round2.setPlayer1(round1.getPlayer1());
            round2.setPlayer2(round1.getPlayer2());
            
            // Player goes first:
            round2.player1.botRollD12();
            round2.player1.qMedBotAddRoll();
            
            // Bot's turn, then displays results of the round:
            round2.player2.botRollD12();
            round2.player2.qMedBotAddRoll();
            
            autoWinValidation();
            
            // If the Game Hasn't Been Decided, Goes to Round 3:
            if (gameWinner == 0)
            {
                // Displays Round 3:
                cout << "---------------------\n";
                cout << "Processing Round Three!\n";
                cout << "---------------------\n";

                elipAnim();

                // Reuses players from Round 2: (for continuity's sake)
                round3.setPlayer1(round2.getPlayer1());
                round3.setPlayer2(round2.getPlayer2());
                
                // Bot goes first:
                round3.player2.botRollD12();
                round3.player2.qMedBotAddRoll();
                
                // Player's turn, then displays results of Round 3:
                round3.player1.botRollD12();
                round3.player1.qMedBotAddRoll();
                
                autoWinValidation();
            }
        }
        break;
    }

    // Code for Hard Bot:
    case '3':
    {
        // Confirms user's decision to fight Hard Bot:
        cout << "Run a VS Hard Bot? (Y/N)\n\n";
        cin >> answerChar;

        // Validates user's choice:
        while(answerChar != 'Y' && answerChar != 'y' && answerChar != 'N' && answerChar != 'n')
        {
            cout << "Invalid Input, please input either Y or N\n";
            cin >> answerChar;
            cout << "\n";
        }


        // If user confirms:
        if(answerChar == 'Y' || answerChar == 'y')
        {
            // Displays Round 1:
            cout << "---------------------\n";
            cout << "Processing Round One!\n";
            cout << "---------------------\n";

            elipAnim();

            // Bot goes first:
            round1.player2.botRollD12();
            round1.player2.qHardBotAddRoll();

            // Player's turn, then displays results of the round:
            round1.player1.botRollD12(); 
            round1.player1.qMedBotAddRoll(); 

            autoWinValidation(); 
            
            // Displays Round 2:
            cout << "---------------------\n";
            cout << "Processing Round Two!\n";
            cout << "---------------------\n";

            elipAnim();

            // Reuses players from previous round: (for continuity's sake)
            round2.setPlayer1(round1.getPlayer1());
            round2.setPlayer2(round1.getPlayer2());

            // Player goes first:
            round2.player1.botRollD12();
            round2.player1.qMedBotAddRoll();

            // Bot's turn, then displays results of the round:
            round2.player2.botRollD12();
            round2.player2.qHardBotAddRoll();
            
            autoWinValidation();
            
            // If the game has not been decided, goes to Round 3:
            if (gameWinner == 0)
            {
                // Displays Round 3:
                cout << "---------------------\n";
                cout << "Processing Round Three!\n";
                cout << "---------------------\n";

                elipAnim();

                // Reuses players from last round: (for continuity's sake)
                round3.setPlayer1(round2.getPlayer1());
                round3.setPlayer2(round2.getPlayer2());
                
                // Bot goes first:
                round3.player2.botRollD12();
                round3.player2.qHardBotAddRoll();
                
                // Player's turn, then displays results of the round:
                round3.player1.botRollD12();
                round3.player1.qMedBotAddRoll();
                
                autoWinValidation();
            }
        }
        break;
    }

    case '4':
    {
        // Confirms user's decision to fight Hard Bot:
        cout << "Run a VS LUNATIC bot??? (Y/N)\n\n";
        cin >> answerChar;

        // Validates user's choice:
        while(answerChar != 'Y' && answerChar != 'y' && answerChar != 'N' && answerChar != 'n')
        {
            cout << "Invalid Input, please input either Y or N\n";
            cin >> answerChar;
            cout << "\n";
        }
        if (answerChar == 'Y' || answerChar == 'y')
        {
            // Displays Round 1:
            cout << "---------------------\n";
            cout << "Processing Round One!\n";
            cout << "---------------------\n";

            elipAnim();

            // Bot goes first:
            round1.player2.rBotRollD12();
            round1.player2.qLunaticBotAddRoll();

            // Player's turn, then displays results of the round:
            round1.player1.botRollD12(); 
            round1.player1.qMedBotAddRoll(); 
            
            autoWinValidation();
            
            // Displays Round 2:
            cout << "---------------------\n";
            cout << "Processing Round Two!\n";
            cout << "---------------------\n";

            elipAnim();

            // Reuses players from previous round: (for continuity's sake)
            round2.setPlayer1(round1.getPlayer1());
            round2.setPlayer2(round1.getPlayer2());

            // Player goes first:
            round2.player1.botRollD12();
            round2.player1.qMedBotAddRoll();

            // Bot's turn, then displays results of the round:
            round2.player2.rBotRollD12();
            round2.player2.qLunaticBotAddRoll();
            
            autoWinValidation();
            
            // If the game has not been decided, goes to Round 3:
            if (gameWinner == 0)
            {
                // Displays Round 3:
                cout << "---------------------\n";
                cout << "Processing Round Three!\n";
                cout << "---------------------\n";

                elipAnim();

                // Reuses players from last round: (for continuity's sake)
                round3.setPlayer1(round2.getPlayer1());
                round3.setPlayer2(round2.getPlayer2());
                
                // Bot goes first:
                round3.player2.rBotRollD12();
                round3.player2.qLunaticBotAddRoll();
                
                // Player's turn, then displays results of the round:
                round3.player1.botRollD12();
                round3.player1.qMedBotAddRoll();
                
                autoWinValidation();
            }
        }
        break;
    }
    // Aka Case 5: does nothing, sends the user back.
    default:
        break;
    }
}