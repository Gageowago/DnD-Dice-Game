/******************************************************************
*   Authors:    Gage Jones, Mason Dye
*   Date:       Sunday, August 1st, 2021
*   Version:    1.6
*   Title:      Functions.cpp
*   Purpose:    Holds many of the overarching functions for the
*               program that allows it to operate.
******************************************************************/

#include "Gwent.h"

/*
SCOREBOARD FUNCTION: FIXME!
*/

/*
DISPLAY MAIN MENU
*/
void displayMainMenu(char &answer)
{   
    cout << "\nGet ready to play some Gwent!\n" 
         << "Choose what you want to play!\n\n"
         << " _____________________________________\n"
         << "|(1) VS CPU                           |\n"
         << "|(2) VS PLAYER LOCAL    (NEW)         |\n"
         << "|(3) VS PLAYER (Another person with   |\n"
         << "|                     this program)   |\n"
         << "|(4) DM MODE  (WORK IN PROGRESS)      |\n"
         << "|(5) QUICKPLAY MODE                   |\n"
         << "|(6) HOW TO PLAY?                     |\n"
         << "|(7) EXIT PROGRAM                     |\n"
         << "|_____________________________________|\n"
         << "Input a number 1-7!\n";
    cin  >> answer;
    cin.ignore();
    cout << "\n\n";

    while (answer <= '0' && answer > '7')
    {
        cout << "Invalid Input! Please input a number 1-7!\n";
        cin  >> answer;
        cin.ignore();
        cout << "\n\n";
    }
}

void pressAnyKeyToContinue()
{
    cout << "Press any key to continue...\n\n\n";
    getch();
}

void elipAnim()
{
    cout << ".    ";
    Sleep(700);
    cout << ".    ";
    Sleep(700);
    cout << ".";
    Sleep(1000);
    cout << "\n\n\n";
}


/*
    Versus Remote Player:

    Other player's d12 roll?

    Other player's die?

    Other player's die roll?
    
    Final score?
    
*/


void GameScore::reset()
{
    round1.reset();
    round2.reset();
    round3.reset();

    winCountP1 = 0;
    winCountP2 = 0;
    lossCountP1 = 0;
    lossCountP2 = 0;

    r1Winner = 0;
    r2Winner = 0;
    r3Winner = 0;
    gameWinner = 0;
}

void RoundScore::reset()
{
    player1.reset();
    player2.reset();
}

void Player::reset()
{
    d12 = 0;
    dieType = 0;
    dieNum = 0;
    finalScore = 0;
    deception = 0;
    perception = 0;

    d4 = true;
    d6 = true;
    d8 = true;
}

/*
WIN VALIDATION
*/ 
void GameScore::winValidation()
{
    char answer;

    // End of Round 1:
    if (r1Winner == 0)
    {
        while (r1Winner == 0)
        {
            cout << "\n\nDid you win that round? (Y/N)\n";
            cin >> answer;
            
            while (answer != 'Y' && answer != 'N' && answer != 'y' && answer != 'n')
            {
                cout << "Invalid Input! Please enter either Y or N!\n"
                    << "(If you tied, input N)\n\n";
                cin >> answer;
                cout << "\n";
            }

            if (answer == 'Y' || answer == 'y')
            {
                cout << "Congrats! Lets keep the streak up! Time for the next round!\n";
                winCountP1++;
                lossCountP2++;
                r1Winner = 1;
                pressAnyKeyToContinue();
            }
            else if (answer == 'N' || answer == 'n')
            {
                cout << "\nWas it a tie?\n";
                cin >> answer;
                cout << "\n";

                while (answer != 'Y' && answer != 'N' && answer != 'y' && answer != 'n')
                {
                    cout << "Invalid Input! Please enter either Y or N!\n";
                    cin >> answer;
                    cout << "\n";
                }

                if(answer == 'Y' || answer == 'y')
                {
                    round1.player1.reRoll();
                    round1.player1.finalScore = round1.player1.d12 + round1.player1.dieNum;
                    cout << "You rolled a " << round1.player1.finalScore << " in total!\n\n";
                }
                
                else if(answer == 'N' || answer == 'n')
                {
                cout << "That's alright! You'll get them this time! Time for the next round!\n";
                lossCountP1++;
                winCountP2++;
                r1Winner = 2;
                pressAnyKeyToContinue();
                }
            }
        }
    }
    
    // End of Round 2:
    else if (r2Winner == 0)
    {
        while (r2Winner == 0)
        {
            cout << "\n\nDid you win that round? (Y/N)\n";
            cin >> answer;
            
            while (answer != 'Y' && answer != 'N' && answer != 'y' && answer != 'n')
            {
                cout << "Invalid Input! Please enter either Y or N!\n"
                    << "(If you tied, input N)\n\n";
                cin >> answer;
                cout << "\n";
            }

            if ((answer == 'Y' || answer == 'y') && winCountP1 == 1)
            {
                cout << "Congratulations! You are the Winner! Collect your spoils, and Good Game!\n";
                cout << "...\n";
                winCountP1++;
                lossCountP2++;
                pressAnyKeyToContinue();
                r2Winner = 1;
                gameWinner = 1;
            }
            else if (answer == 'Y' || answer == 'y')
            {
                cout << "Great job! You're back in it! Last round, lets bring it home!\n";
                winCountP1++;
                lossCountP2++;
                r2Winner = 1;
                pressAnyKeyToContinue();
            }
            else if ((answer == 'N' || answer == 'n') && lossCountP1 == 1)
            {
                    cout << "\nWas it a tie?\n";
                    cin >> answer;
                    cout << "\n";

                while (answer != 'Y' && answer != 'N' && answer != 'y' && answer != 'n')
                {
                    cout << "Invalid Input! Please enter either Y or N!\n";
                    cin >> answer;
                    cout << "\n";
                }

                if(answer == 'Y' || answer == 'y')
                {
                    round2.player1.reRoll();
                    round2.player1.finalScore = round2.player1.d12 + round2.player1.dieNum;
                    cout << "You rolled a " << round2.player1.finalScore << " in total!\n\n";
                }
                
                else if(answer == 'N' || answer == 'n')
                {
                    cout << "Well, that's game! Sorry pal, better luck next time!\n";
                    cout << "...\n";
                    lossCountP1++;
                    winCountP2++;
                    pressAnyKeyToContinue();
                    r2Winner = 2;
                    gameWinner = 2;
                }
            }
            else if (answer == 'N' || answer == 'n')
            {
                cout << "\nWas it a tie?\n";
                cin >> answer;
                cout << "\n";

                while (answer != 'Y' && answer != 'N' && answer != 'y' && answer != 'n')
                {
                    cout << "Invalid Input! Please enter either Y or N!\n";
                    cin >> answer;
                    cout << "\n";
                }

                if(answer == 'Y' || answer == 'y')
                {
                    round2.player1.reRoll();
                    round2.player1.finalScore = round2.player1.d12 + round2.player1.dieNum;
                    cout << "You rolled a " << round2.player1.finalScore << " in total!\n\n";
                }
                
                else if(answer == 'N' || answer == 'n')
                {
                    cout << "That's okay! You can't win em' all... But you can win this next one! Go get em!\n";
                    lossCountP1++;
                    winCountP2++;
                    r2Winner = 2;
                    pressAnyKeyToContinue();
                }   
            }
        }   
    }
    
    // End of Round 3:
    else if (r3Winner == 0)
    {
        while (r3Winner == 0)
        {
            cout << "\n\nDid you win that round? (Y/N)\n";
            cin >> answer;
            
            while (answer != 'Y' && answer != 'N' && answer != 'y' && answer != 'n')
            {
                cout << "Invalid Input! Please enter either Y or N!\n"
                    << "(If you tied, input N)\n\n";
                cin >> answer;
                cout << "\n";
            }

            if (answer == 'Y' || answer == 'y')
            {
                cout << "A hard fought victory! Congratulations! Grab your spoils, and Good Game!\n";
                winCountP1++;
                lossCountP2++;
                pressAnyKeyToContinue();
                r3Winner = 1;
                gameWinner = 1;
            }
            
            else if (answer == 'N' || answer == 'n')
            {
                cout << "\nWas it a tie?\n";
                cin >> answer;
                cout << "\n";

                while (answer != 'Y' && answer != 'N' && answer != 'y' && answer != 'n')
                {
                    cout << "Invalid Input! Please enter either Y or N!\n";
                    cin >> answer;
                    cout << "\n";
                }

                if(answer == 'Y' || answer == 'y')
                {
                    round3.player1.reRoll();
                    round3.player1.finalScore = round3.player1.d12 + round3.player1.dieNum;
                    cout << "You rolled a " << round3.player1.finalScore << " in total!\n\n";
                }
                
                else if(answer == 'N' || answer == 'n')
                {
                    cout << "Aw, so close! You almost had them! Good luck next game!\n";
                    lossCountP1++;
                    winCountP1++;
                    pressAnyKeyToContinue();
                    r3Winner = 2;
                    gameWinner = 2;
                }   
            }
        }
    }
}

void printInstruct()
{
    cout << "\n\n\nSo you need a refresher course on Gwent huh? Well here you go:\n\n\n";
    
    cout << "Gwent is a two player luck and slightly strategically based game where the\n"
         << "highest roll wins. Player 1 rolls a D12. Player 1 then chooses between and\n" 
         << "a D4, D6, and D8, and adds that to their total roll. what they rolled is \n"
         << "hidden to Player 2. Player 2 CAN make a perception check against Player 1's\n"
         << "deception roll if they so wish, to get an idea of what Player 1 rolled. \n"
         << "The additional die type (D4, D6, D8) that Player 1 rolled is known to \n"
         << "Player 2, but not the actual number on it.\n\n";

    cout << "It is now Player 2's turn, they will roll a D12 and then choose their additional\n"
         << "die. All of these numbers are visible to Player 1, since it doesn't matter any more\n"
         << "Player 1 then reveals their numbers, and whoever has the higher total wins the round.\n\n\n";

    cout << "Round Two is the same concept as Round 1 with some minor differences.\n"
         << "Player 2 is now the one who starts and has their dice rolls hidden. However, whatever\n"
         << "die that you rolled in Round 1 are now no longer usable. If you rolled your D8, it is\n"
         << "unusable for the rest of the game. If one of the players has won twice in a row at this\n"
         << "point, the game ends, and that player is the victor. If not, then the game moves on to\n"
         << "Round 3, which reverts back to Player 1 being the first to go.\n";
    
    cout << "^\n"
         << "|\n"
         << "|\n";
    cout << "And that's all there is to Gwent! Have Fun!\n";
    pressAnyKeyToContinue();
}