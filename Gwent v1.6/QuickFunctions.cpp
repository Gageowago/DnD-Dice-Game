/******************************************************************
*   Authors:    Gage Jones, Mason Dye
*   Date:       Sunday, August 1st, 2021
*   Version:    1.6
*   Title:      QuickFunctions.cpp
*   Purpose:    Holds a few functions required for Quick Mode
******************************************************************/

#include "Gwent.h"



void GameScore::autoWinValidation()
{
    // End of Round 1:
    if (r1Winner == 0)
    {
        // Checks for if there is a tie, in which case the player will reroll their D12
        while(round1.player1.finalScore == round1.player2.finalScore)
        {
            round1.player1.qReRoll();
            round1.player1.finalScore = round1.player1.d12 + round1.player1.dieNum;
        }

        if (round1.player1.finalScore > round1.player2.finalScore)
        {
            cout << "Validating Round Winner...\n";
            elipAnim();
            winCountP1++;
            lossCountP2++;
            r1Winner = 1;
        }
        else if (round1.player1.finalScore < round1.player2.finalScore)
        {
            cout << "Validating Round Winner...\n";
            elipAnim();
            lossCountP1++;
            winCountP2++;
            r1Winner = 2;
        }
    }
    
    // End of Round 2:
    else if (r2Winner == 0)
    {
        // Checks for if there is a tie, in which case the player will reroll their D12
        while(round2.player1.finalScore == round2.player2.finalScore)
        {
            round2.player1.qReRoll();
            round2.player1.finalScore = round2.player1.d12 + round2.player1.dieNum;
        }

        if ((round2.player1.finalScore > round2.player2.finalScore) && winCountP1 == 1)
        {
            cout << "Validating Round Winner...\n";
            elipAnim();
            cout << "Validating Game Winner...\n";
            elipAnim();
            autoScore();
            cout << "\n\nPlayer 1 won!\n";
            pressAnyKeyToContinue();
            winCountP1++;
            lossCountP2++;
            r2Winner = 1;
            gameWinner = 1;
        }
        else if (round2.player1.finalScore > round2.player2.finalScore)
        {
            cout << "Validating Round Winner...\n";
            elipAnim();
            winCountP1++;
            lossCountP2++;
            r2Winner = 1;
        }
        else if ((round2.player1.finalScore < round2.player2.finalScore) && lossCountP1 == 1)
        {
            cout << "Validating Round Winner...\n";
            elipAnim();
            cout << "Validating Game Winner...\n";
            elipAnim();
            autoScore();
            cout << "\n\nPlayer 2 won!\n";
            pressAnyKeyToContinue();
            lossCountP1++;
            winCountP2++;
            r2Winner = 2;
            gameWinner = 2;
        }
        else if (round2.player1.finalScore < round2.player2.finalScore)
        {
            cout << "Validating Round Winner...\n";
            elipAnim();
            lossCountP1++;
            winCountP2++;
            r2Winner = 2;
        }
    }
    
    // End of Round 3:
    else if (r3Winner == 0)
    {
        // Checks for if there is a tie, in which case the player will reroll their D12
        while(round3.player1.finalScore == round3.player2.finalScore)
        {
            round3.player1.qReRoll();
            round3.player1.finalScore = round3.player1.d12 + round3.player1.dieNum;
        }

        if (round3.player1.finalScore > round3.player2.finalScore)
        {
            cout << "Validating Round Winner...\n";
            elipAnim();
            cout << "Validating Game Winner...\n";
            elipAnim();
            autoScore();
            cout << "\n\nPlayer 1 won!\n";
            pressAnyKeyToContinue();
            winCountP1++;
            lossCountP2++;
            r3Winner = 1;
            gameWinner = 1;
        }
        
        else if (round3.player1.finalScore < round3.player2.finalScore)
        {
            cout << "Validating Round Winner...\n";
            elipAnim();
            cout << "Validating Game Winner...\n";
            elipAnim();
            autoScore();
            cout << "\n\nPlayer 2 won!\n";
            pressAnyKeyToContinue();
            lossCountP1++;
            winCountP1++;
            r3Winner = 2;
            gameWinner = 2;
        }
    }
}

void Player::qReRoll()
{
    // "Rolls the die", sets d12 roll to random number 1-12:
    d12 = (rand() %12) + 1;
}


void GameScore::autoScore()
{
    cout << "                                  ___________________________________________________\n"
         << "                                 |         |      Player 1     |     Player 2          \n"
         << "                                 | Round 1 |     " << round1.player1.d12 << " + " << round1.player1.dieNum << " = " << round1.player1.finalScore
         << "         " << round1.player2.d12 << " + " << round1.player2.dieNum << " = " << round1.player2.finalScore << "     \n";
 
            
    cout << "                                 |_________|___________________|_____________________\n"
         << "                                 |         |                   |\n"
         << "                                 | Round 2 |     " << round2.player1.d12 << " + " << round2.player1.dieNum << " = " << round2.player1.finalScore

         << "         " << round2.player2.d12 << " + " << round2.player2.dieNum << " = " << round2.player2.finalScore << "       \n";


    cout << "                                 |_________|___________________|_____________________\n"
         << "                                 |         |                   |\n"
         << "                                 | Round 3 |     " << round3.player1.d12 << " + " << round3.player1.dieNum << " = " << round3.player1.finalScore

         << "         " << round3.player2.d12 << " + " << round3.player2.dieNum << " = " << round3.player2.finalScore << "       \n"

         << "                                 |_________|___________________|_____________________\n";
}