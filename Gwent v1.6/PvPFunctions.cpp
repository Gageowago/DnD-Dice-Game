/******************************************************************
*   Authors:    Gage Jones, Mason Dye
*   Date:       Sunday, August 1st, 2021
*   Version:    1.6
*   Title:      PvPFunctions.cpp
*   Purpose:    Holds a few functions required for vsLocal Mode
******************************************************************/

#include "Gwent.h"


void GameScore::pvpWinValidation()
{
    // End of Round 1:
    if (r1Winner == 0)
    {
        // Checks for if there is a tie, in which case the player will reroll their D12
        while(round1.player1.finalScore == round1.player2.finalScore)
        {
            cout << "Press any key to view the results!\n";
            elipAnim();
            cout << "Player 1 rolled a " << round1.player1.finalScore << " and Player 2 rolled a " << round1.player2.finalScore << "\n\n";
            cout << "Players tied!\n";

            cout << "Player 1 roll once more!\n";
            pressAnyKeyToContinue();
            round1.player1.reRoll();
            round1.player1.finalScore = round1.player1.d12 + round1.player1.dieNum;

            cout << "Now Player 2!\n";
            pressAnyKeyToContinue();
            round1.player2.reRoll();
            round1.player2.finalScore = round1.player2.d12 + round1.player2.dieNum;
        }

        if (round1.player1.finalScore > round1.player2.finalScore)
        {
            cout << "Press any key to view the results!\n";
            getch();
            elipAnim();
            cout << "Player 1 rolled a " << round1.player1.finalScore << " while Player 2 rolled a " << round1.player2.finalScore << "\n\n";
            cout << "Player 1 won the round!\n";
            cout << "Congrats Player 1! Lets keep the streak up! Time for the next round!\n";
            cout << "That's alright Player 2! You'll get them this time! Time for the next round!\n";
            pressAnyKeyToContinue();
            winCountP1++;
            lossCountP2++;
            r1Winner = 1;
        }
        else if (round1.player1.finalScore < round1.player2.finalScore)
        {
            cout << "Press any key to view the results!\n";
            elipAnim();
            cout << "Player 1 rolled a " << round1.player1.finalScore << " while Player 2 rolled a " << round1.player2.finalScore << "\n\n";
            cout << "Player 2 won the round!\n";
            cout << "Congrats Player 2! Lets keep the streak up! Time for the next round!\n";
            cout << "That's alright Player 1! You'll get them this time! Time for the next round!\n";
            pressAnyKeyToContinue();
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
            cout << "Press any key to view the results!\n";
            elipAnim();
            cout << "Player 1 rolled a " << round2.player1.finalScore << " and Player 2 rolled a " << round2.player2.finalScore << "\n\n";
            cout << "Players tied!\n";

            cout << "Player 1 roll once more!\n";
            pressAnyKeyToContinue();
            round2.player1.reRoll();
            round2.player1.finalScore = round2.player1.d12 + round2.player1.dieNum;

            cout << "Now Player 2!\n";
            pressAnyKeyToContinue();
            round2.player2.reRoll();
            round2.player2.finalScore = round2.player2.d12 + round2.player2.dieNum;
        }

        if ((round2.player1.finalScore > round2.player2.finalScore) && winCountP1 == 1)
        {
            cout << "Press any key to view the results!\n";
            elipAnim();
            cout << "Player 1 rolled a " << round2.player1.finalScore << " while Player 2 rolled a " << round2.player2.finalScore << "\n\n";
            cout << "Player 1 won the round!\n";
            cout << "Congratulations Player 1! You have won! Collect your spoils, and Good Game!\n";
            cout << "Well, that's game! Sorry Player 2, better luck next time!\n";
            cout << "...\n";
            pressAnyKeyToContinue();
            winCountP1++;
            lossCountP2++;
            r2Winner = 1;
            gameWinner = 1;
        }
        else if (round2.player1.finalScore > round2.player2.finalScore)
        {
            cout << "Press any key to view the results!\n";
            elipAnim();
            cout << "Player 1 rolled a " << round2.player1.finalScore << " while Player 2 rolled a " << round2.player2.finalScore << "\n\n";
            cout << "Player 1 won the round!\n";
            cout << "Great job Player 1! You're back in it! Last round, lets bring it home!\n";
            cout << "That's okay Player 2! You can't win em' all... But you can win this next one! Go get em!\n";
            pressAnyKeyToContinue();
            winCountP1++;
            lossCountP2++;
            r2Winner = 1;
        }
        else if ((round2.player1.finalScore < round2.player2.finalScore) && lossCountP1 == 1)
        {
            cout << "Press any key to view the results!\n";
            elipAnim();
            cout << "Player 1 rolled a " << round2.player1.finalScore << " while Player 2 rolled a " << round2.player2.finalScore << "\n\n";
            cout << "Player 2 won the round!\n";
            cout << "Congratulations Player 2! You have won! Collect your spoils, and Good Game!\n";
            cout << "Well, that's game! Sorry Player 1, better luck next time!\n";
            cout << "...\n";
            pressAnyKeyToContinue();
            lossCountP1++;
            winCountP2++;
            r2Winner = 2;
            gameWinner = 2;
        }
        else if (round2.player1.finalScore < round2.player2.finalScore)
        {
            cout << "Press any key to view the results!\n";
            elipAnim();
            cout << "Player 1 rolled a " << round2.player1.finalScore << " while Player 2 rolled a " << round2.player2.finalScore << "\n\n";
            cout << "Player 2 won the round!\n";
            cout << "Great job Player 2! You're back in it! Last round, lets bring it home!\n";
            cout << "That's okay Player 1! You can't win em' all... But you can win this next one! Go get em!\n";
            pressAnyKeyToContinue();
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
            cout << "Press any key to view the results!\n";
            elipAnim();
            cout << "Player 1 rolled a " << round3.player1.finalScore << " and Player 2 rolled a " << round3.player2.finalScore << "\n\n";
            cout << "Players tied!\n";

            cout << "Player 1 roll once more!\n";
            pressAnyKeyToContinue();
            round3.player1.reRoll();
            round3.player1.finalScore = round3.player1.d12 + round3.player1.dieNum;

            cout << "Now Player 2!\n";
            pressAnyKeyToContinue();
            round3.player2.reRoll();
            round3.player2.finalScore = round3.player2.d12 + round3.player2.dieNum;
        }

        if (round3.player1.finalScore > round3.player2.finalScore)
        {
            cout << "Press any key to view the results!\n";
            elipAnim();
            cout << "Player 1 rolled a " << round3.player1.finalScore << " while Player 2 rolled a " << round3.player2.finalScore << "\n\n";
            cout << "Player 1 won the round!\n";
            cout << "A hard fought victory! Congratulations Player 1! Grab your spoils, and Good Game!\n";
            cout << "Aw, so close! You almost had them Player 2! Good luck next game!\n";
            pressAnyKeyToContinue();
            winCountP1++;
            lossCountP2++;
            r3Winner = 1;
            gameWinner = 1;
        }
        
        else if (round3.player1.finalScore < round3.player2.finalScore)
        {
            cout << "Press any key to view the results!\n";
            elipAnim();
            cout << "Player 1 rolled a " << round3.player1.finalScore << " while Player 2 rolled a " << round3.player2.finalScore << "\n\n";
            cout << "Player 2 won the round!\n";
            cout << "A hard fought victory! Congratulations Player 2! Grab your spoils, and Good Game!\n";
            cout << "Aw, so close! You almost had them Player 1! Good luck next game!\n";
            pressAnyKeyToContinue();
            lossCountP1++;
            winCountP1++;
            r3Winner = 2;
            gameWinner = 2;
        }
    }
}