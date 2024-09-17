/******************************************************************
*   Authors:    Gage Jones, Mason Dye
*   Date:       Sunday, August 1st, 2021
*   Version:    1.6
*   Title:      VSBotMode.cpp
*   Purpose:    Holds the entire code for the VS Bot option
******************************************************************/

#include "Gwent.h"

// Displays bot-difficulty level and gets user input:
void GameScore::vsBot()
{
    char answerChar;

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
        cout << "VS EASY BOT? (Y/N)\n\n";
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
            cout << "Round One! Roll!\n";
            cout << "---------------------\n";

            pressAnyKeyToContinue();
            
            // Bot's turn first:
            round1.player2.botRollD12();
            round1.player2.easyBotAddRoll();
            
            // Sets the bot's deception check, allows player to perceive bot's rolls:
            round1.player2.deception = 10;
            round1.botDeceptionCheck();

            // Player's turn, then displays results of the round:
            round1.player1.rollD12(); 
            round1.player1.addRoll(); 
            botWinValidation(); 
            
            // Displays Round 2:
            cout << "---------------------\n";
            cout << "Round Two! Roll!\n";
            cout << "---------------------\n";

            pressAnyKeyToContinue();

            // Sets Round 2's players to Round 1's: (for continuity's sake)
            round2.setPlayer1(round1.getPlayer1());
            round2.setPlayer2(round1.getPlayer2());

            // Player 1 aka user goes first:
            round2.player1.rollD12();
            round2.player1.addRoll();

            // Bot goes second, then displays results of the round:
            round2.player2.botRollD12();
            round2.player2.easyBotAddRoll();
            botWinValidation();
            
            // If the game hasn't been decided yet, move on to Round 3:
            if (gameWinner == 0)
            {
                // Displays Round 3:
                cout << "---------------------\n";
                cout << "Round Three! Roll!\n";
                cout << "---------------------\n";

                pressAnyKeyToContinue();

                // Reuses previous players: (for continuity's sake)
                round3.setPlayer1(round2.getPlayer1());
                round3.setPlayer2(round2.getPlayer2());

                // Bot goes first:
                round3.player2.botRollD12();
                round3.player2.easyBotAddRoll();

                // Player can try for perception of bot's roll:
                round3.botDeceptionCheck();

                // Player's turn, then displays the results of the round:
                round3.player1.rollD12();
                round3.player1.addRoll();
                botWinValidation();
            }
        }
        break;
    }

    // Code for Medium Bot:
    case '2':
    {
        // Confirms user's decision:
        cout << "VS MEDIUM BOT? (Y/N)\n\n";
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
            cout << "Round One! Roll!\n";
            cout << "---------------------\n";

            pressAnyKeyToContinue();

            // Bot goes first:
            round1.player2.botRollD12();
            round1.player2.medBotAddRoll();

            // Player's chance at perception: (a bit harder)
            round1.player2.deception = 13;
            round1.botDeceptionCheck(); 

            // Player's turn, then displays results of the round:
            round1.player1.rollD12(); 
            round1.player1.addRoll(); 
            botWinValidation(); 
            
            // Displays Round
            cout << "---------------------\n";
            cout << "Round Two! Roll!\n";
            cout << "---------------------\n";

            pressAnyKeyToContinue();

            // Reuses Players from Round 1: (for continuity's sake)
            round2.setPlayer1(round1.getPlayer1());
            round2.setPlayer2(round1.getPlayer2());
            
            // Player goes first:
            round2.player1.rollD12();
            round2.player1.addRoll();
            
            // Bot's turn, then displays results of the round:
            round2.player2.botRollD12();
            round2.player2.medBotAddRoll();
            botWinValidation();
            
            // If the Game Hasn't Been Decided, Goes to Round 3:
            if (gameWinner == 0)
            {
                // Displays Round 3:
                cout << "---------------------\n";
                cout << "Round Three! Roll!\n";
                cout << "---------------------\n";

                pressAnyKeyToContinue();

                // Reuses players from Round 2: (for continuity's sake)
                round3.setPlayer1(round2.getPlayer1());
                round3.setPlayer2(round2.getPlayer2());
                
                // Bot goes first:
                round3.player2.botRollD12();
                round3.player2.medBotAddRoll();

                // Player's chance at perception:
                round1.botDeceptionCheck();
                
                // Player's turn, then displays results of Round 3:
                round3.player1.rollD12();
                round3.player1.addRoll();
                botWinValidation();
            }
        }
        break;
    }

    // Code for Hard Bot:
    case '3':
    {
        // Confirms user's decision to fight Hard Bot:
        cout << "VS HARD BOT? (Y/N)\n\n";
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
            cout << "Round One! Roll!\n";
            cout << "---------------------\n";

            pressAnyKeyToContinue();

            // Bot goes first:
            round1.player2.botRollD12();
            round1.player2.hardBotAddRoll();

            // Player's chance at perception:
            round1.player2.deception = 15;
            round1.botDeceptionCheck();

            // Player's turn, then displays results of the round:
            round1.player1.rollD12(); 
            round1.player1.addRoll(); 
            botWinValidation(); 
            
            // Displays Round 2:
            cout << "---------------------\n";
            cout << "Round Two! Roll!\n";
            cout << "---------------------\n";

            pressAnyKeyToContinue();

            // Reuses players from previous round: (for continuity's sake)
            round2.setPlayer1(round1.getPlayer1());
            round2.setPlayer2(round1.getPlayer2());

            // Player goes first:
            round2.player1.rollD12();
            round2.player1.addRoll();

            // Bot's turn, then displays results of the round:
            round2.player2.botRollD12();
            round2.player2.hardBotAddRoll();
            botWinValidation();
            
            // If the game has not been decided, goes to Round 3:
            if (gameWinner == 0)
            {
                // Displays Round 3:
                cout << "---------------------\n";
                cout << "Round Three! Roll!\n";
                cout << "---------------------\n";

                pressAnyKeyToContinue();

                // Reuses players from last round: (for continuity's sake)
                round3.setPlayer1(round2.getPlayer1());
                round3.setPlayer2(round2.getPlayer2());
                
                // Bot goes first:
                round3.player2.botRollD12();
                round3.player2.hardBotAddRoll();

                // Player's chance at perception:
                round3.botDeceptionCheck();
                
                // Player's turn, then displays results of the round:
                round3.player1.rollD12();
                round3.player1.addRoll();
                botWinValidation();
            }
        }
        break;
    }

    case '4':
    {
        // Confirms user's decision to fight Hard Bot:
        cout << "VS  L U N A T I C  BOT? (Y/N)\n\n";
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
            cout << "Are you... Are you sure?\n\n";
            cout << "This bot is EXTREMELY unfair you know...\n";
            cout << "He even cheats, too! (Y/N)\n\n";
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
                cout << "I mean... I warned you...\n\n";
                elipAnim();
                pressAnyKeyToContinue();

                // Displays Round 1:
                cout << "---------------------\n";
                cout << "Round One! Roll!\n";
                cout << "---------------------\n";

                pressAnyKeyToContinue();

                // Bot goes first:
                round1.player2.rBotRollD12();
                round1.player2.lunaticBotAddRoll();

                // Player's chance at perception:
                round1.player2.deception = 20;
                round1.botDeceptionCheck();

                // Player's turn, then displays results of the round:
                round1.player1.rollD12(); 
                round1.player1.addRoll(); 
                botWinValidation(); 
                
                // Displays Round 2:
                cout << "---------------------\n";
                cout << "Round Two! Roll!\n";
                cout << "---------------------\n";

                pressAnyKeyToContinue();

                // Reuses players from previous round: (for continuity's sake)
                round2.setPlayer1(round1.getPlayer1());
                round2.setPlayer2(round1.getPlayer2());

                // Player goes first:
                round2.player1.rollD12();
                round2.player1.addRoll();

                // Bot's turn, then displays results of the round:
                round2.player2.rBotRollD12();
                round2.player2.lunaticBotAddRoll();
                botWinValidation();
                
                // If the game has not been decided, goes to Round 3:
                if (gameWinner == 0)
                {
                    // Displays Round 3:
                    cout << "---------------------\n";
                    cout << "Round Three! Roll!\n";
                    cout << "---------------------\n";

                    pressAnyKeyToContinue();

                    // Reuses players from last round: (for continuity's sake)
                    round3.setPlayer1(round2.getPlayer1());
                    round3.setPlayer2(round2.getPlayer2());
                    
                    // Bot goes first:
                    round3.player2.rBotRollD12();
                    round3.player2.lunaticBotAddRoll();
                    

                    // Player's chance at perception:
                    round3.botDeceptionCheck();
                    
                    // Player's turn, then displays results of the round:
                    round3.player1.rollD12();
                    round3.player1.addRoll();
                    botWinValidation();
                }
            }
        }
        break;
    }
    // Aka Case 5: does nothing, sends the user back.
    default:
        break;
    }
}