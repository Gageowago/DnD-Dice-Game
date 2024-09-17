/******************************************************************
*   Authors:    Gage Jones, Mason Dye
*   Date:       Sunday, August 1st, 2021
*   Version:    1.6
*   Title:      BotFunctions.cpp
*   Purpose:    Holds the various functions used by the bot
*               in the VS BOT mode
******************************************************************/

#include "Gwent.h"


void Player::botRollD12()
{
    // "Rolls the die", sets d12 roll to random number 1-12:
    d12 = (rand() %12) + 1;

    // Displays roll to user:
    cout << "DEBUG MODE: Bot rolled a " << d12 << "!\n";
}

void Player::botRollD8()
{
    dieType = 8;
    dieNum = (rand() %8) + 1;
    cout << "DEBUG MODE: Bot rolled a " << dieNum << "!\n";
    cout << "DEBUG MODE: In total, bot rolled a " << d12 + dieNum << "!\n";
    d8 = false;
    finalScore = d12 + dieNum;
}

void Player::botRollD6()
{
    dieType = 6;
    dieNum = (rand() %6) + 1;
    cout << "DEBUG MODE: Bot rolled a " << dieNum << "!\n";
    cout << "DEBUG MODE: In total, bot rolled a " << d12 + dieNum << "!\n";
    d6 = false;
    finalScore = d12 + dieNum;
}

void Player::botRollD4()
{
    dieType = 4;
    dieNum = (rand() % 4) + 1;
    cout << "DEBUG MODE: Bot rolled a " << dieNum << "!\n";
    cout << "DEBUG MODE: In total, bot rolled a " << d12 + dieNum << "!\n";
    d4 = false;
    finalScore = d12 + dieNum;
}

void GameScore::botWinValidation()
{
    // End of Round 1:
    if (r1Winner == 0)
    {
        // Checks for if there is a tie, in which case the player will reroll their D12
        while(round1.player1.finalScore == round1.player2.finalScore)
        {
            cout << "Press any key to view the results!\n";
            elipAnim();
            cout << "You rolled a " << round1.player1.finalScore << " and your opponent rolled a " << round1.player2.finalScore << "\n\n";
            cout << "You tied!\n";
            cout << "Roll once more!\n";
            pressAnyKeyToContinue();
            round1.player1.reRoll();
            round1.player1.finalScore = round1.player1.d12 + round1.player1.dieNum;
        }

        if (round1.player1.finalScore > round1.player2.finalScore)
        {
            cout << "Press any key to view the results!\n";
            getch();
            elipAnim();
            cout << "You rolled a " << round1.player1.finalScore << " while your opponent rolled a " << round1.player2.finalScore << "\n\n";
            cout << "You won the round!\n";
            cout << "Congrats! Lets keep the streak up! Time for the next round!\n";
            pressAnyKeyToContinue();
            winCountP1++;
            lossCountP2++;
            r1Winner = 1;
        }
        else if (round1.player1.finalScore < round1.player2.finalScore)
        {
            cout << "Press any key to view the results!\n";
            elipAnim();
            cout << "You rolled a " << round1.player1.finalScore << " while your opponent rolled a " << round1.player2.finalScore << "\n\n";
            cout << "You lost the round!\n";
            cout << "That's alright! You'll get them this time! Time for the next round!\n";
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
            cout << "You rolled a " << round2.player1.finalScore << " and your opponent rolled a " << round2.player2.finalScore << "\n\n";
            cout << "You tied!\n";
            cout << "Roll once more!\n";
            round2.player1.reRoll();
            round2.player1.finalScore = round2.player1.d12 + round2.player1.dieNum;
        }

        if ((round2.player1.finalScore > round2.player2.finalScore) && winCountP1 == 1)
        {
            cout << "Press any key to view the results!\n";
            elipAnim();
            cout << "You rolled a " << round2.player1.finalScore << " while your opponent rolled a " << round2.player2.finalScore << "\n\n";
            cout << "You won the round!\n";
            cout << "Congratulations! You have bested the Bot/NPC! Collect your spoils, and Good Game!\n";
            cout << "...\n";
            pressAnyKeyToContinue();
            winCountP1++;
            lossCountP2++;
            r2Winner = 1;
            gameWinner = 1;
        }
        else if (round2.player1.finalScore > round2.player2.finalScore && winCountP1 == 0)
        {
            cout << "Press any key to view the results!\n";
            elipAnim();
            cout << "You rolled a " << round2.player1.finalScore << " while your opponent rolled a " << round2.player2.finalScore << "\n\n";
            cout << "You won the round!\n";
            cout << "Great job! You're back in it! Last round, lets bring it home!\n";
            pressAnyKeyToContinue();
            winCountP1++;
            lossCountP2++;
            r2Winner = 1;
        }
        else if ((round2.player1.finalScore < round2.player2.finalScore) && lossCountP1 == 1)
        {
            cout << "Press any key to view the results!\n";
            elipAnim();
            cout << "You rolled a " << round2.player1.finalScore << " while your opponent rolled a " << round2.player2.finalScore << "\n\n";
            cout << "You lost the round!\n";
            cout << "Well, that's game! Sorry pal, better luck next time!\n";
            cout << "...\n";
            pressAnyKeyToContinue();
            lossCountP1++;
            winCountP2++;
            r2Winner = 2;
            gameWinner = 2;
        }
        else if ((round2.player1.finalScore < round2.player2.finalScore) && lossCountP1 == 0)
        {
            cout << "Press any key to view the results!\n";
            elipAnim();
            cout << "You rolled a " << round2.player1.finalScore << " while your opponent rolled a " << round2.player2.finalScore << "\n\n";
            cout << "You lost the round!\n";
            cout << "That's okay! You can't win em' all... But you can win this next one! Go get em!\n";
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
            cout << "You rolled a " << round3.player1.finalScore << " and your opponent rolled a " << round3.player2.finalScore << "\n\n";
            cout << "You tied!\n";
            cout << "Roll once more!\n";
            round3.player1.reRoll();
            round3.player1.finalScore = round3.player1.d12 + round3.player1.dieNum;
        }

        if (round3.player1.finalScore > round3.player2.finalScore)
        {
            cout << "Press any key to view the results!\n";
            elipAnim();
            cout << "You rolled a " << round3.player1.finalScore << " while your opponent rolled a " << round3.player2.finalScore << "\n\n";
            cout << "You won the round!\n";
            cout << "A hard fought victory! Congratulations! Grab your spoils, and Good Game!\n";
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
            cout << "You rolled a " << round3.player1.finalScore << " while your opponent rolled a " << round3.player2.finalScore << "\n\n";
            cout << "You lost the round!\n";
            cout << "Aw, so close! You almost had them! Good luck next game!\n";
            pressAnyKeyToContinue();
            lossCountP1++;
            winCountP1++;
            r3Winner = 2;
            gameWinner = 2;
        }
    }
}