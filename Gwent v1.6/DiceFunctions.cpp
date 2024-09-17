/******************************************************************
*   Authors:    Gage Jones, Mason Dye
*   Date:       Sunday, August 1st, 2021
*   Version:    1.6
*   Title:      DiceFunctions.cpp
*   Purpose:    Holds the Dice Functions, which are used to roll
*               the dice in the main function!
******************************************************************/

#include "Gwent.h"

/*
ROLLS A D12 WHEN THE PLAYER PROMPTS IT
*/
void Player::rollD12()     // FIXME: Include structure instead of too many variables.
{
    // Displays text to user:
    cout << "Press ANY KEY to roll your die!\n";
    getch();

    // "Rolls the die", sets d12 roll to random number 1-12:
    d12 = (rand() %12) + 1;

    // Displays roll to user:
    cout << "You roll your D12!\n";
    elipAnim();
    cout << "\n     ___\n"
         << "    /   \\\n"
         << "    |" << d12 << "  |\n"
         << "    \\___/\n\n";
    cout << "You rolled a " << d12 << "!\n";
   
    cout << "Press any key to continue...\n";
    getch();
}

/*
THIS IS THE CODE FOR ROLLING A D4
*/
void Player::rollD4()      // FIXME: Include structure instead of too many variables.
{
    cout << "Press any key to continue...\n";
    getch();

    cout << "You roll your D4!\n";

    dieType = 4;
    dieNum = (rand() % 4) + 1;
    elipAnim();
    cout << "\n  /\\\n"
         << " / " << dieNum << " \\\n"
         << "/_____\\ \n\n";
    cout << "You rolled a " << dieNum << "!\n";
    cout << "In total, you rolled " << d12 + dieNum << "!\n";
    cout << "You can no longer use your D4!\n\n";
    d4 = false;
    finalScore = d12 + dieNum;
}

/*
THIS IS THE CODE FOR ROLLING A D6
*/
void Player::rollD6()      // FIXME: Include structure instead of too many variables.
{
    cout << "Press any key to continue...\n";
    getch();

    cout << "You roll your D6!\n";
    dieType = 6;
    dieNum = (rand() %6) + 1;
    elipAnim();
    cout << "\n ___ \n"
         << "| " << dieNum << " |\n"
         << "|___|\n\n";
    cout << "You rolled a " << dieNum << "!\n";
    cout << "In total, you rolled " << d12 + dieNum << "!\n";
    cout << "You can no longer use your D6!\n\n";
    d6 = false;
    finalScore = d12 + dieNum;
}

/*
THIS IS THE CODE FOR ROLLING A D8
*/
void Player::rollD8()      // FIXME: Include structure instead of too many variables.
{ 
    cout << "Press any key to continue...\n";
    getch();

    cout << "You roll your D8!\n";
    dieType = 8;
    dieNum = (rand() %8) + 1;
    elipAnim();
    cout << "\n  /\\\n"
         << " |" << dieNum << " |\n"
         << "  \\/\n\n";
    cout << "You rolled a " << dieNum << "!\n";
    cout << "In total, you rolled " << d12 + dieNum << "!\n";
    cout << "You can no longer use your D8!\n\n";
    d8 = false;
    finalScore = d12 + dieNum;
}

/*
ASKS THE PLAYER WHAT ADDITIONAL DIE THEY WANT TO ROLL
*/
void Player::addRoll()       // FIXME: Include structure instead of too many variables.
{
    char answer;
    bool moveOn = false;
    
    displayDice();
    cin  >> answer;
    cout << "\n";

    while (!moveOn)
    {
        switch (answer)
        {
            case '4':
                if (!d4)
                {
                    cout << "You've already used that die! Choose another!\n";
                    cin  >> answer;
                    cout << "\n";
                    break;
                }
                rollD4();
                moveOn = true;
                break;

            case '6':
                if (!d6)
                {
                    cout << "You've already used that die! Choose another!\n";
                    cin  >> answer;
                    cout << "\n";
                    break;
                }
                rollD6();
                moveOn = true;
                break;
                
            case '8':
                if (!d8)
                {
                    cout << "You've already used that die! Choose another!\n";
                    cin  >> answer;
                    cout << "\n";
                    break;
                }
                moveOn = true;
                rollD8();
                break;

            default:
                cout << "Invalid Input! Please input 4, 6, or 8!\n";
                cin  >> answer;
                cout << "\n";
                break;
        }
    }
}

void Player::reRoll()
{
    // Displays text to user:
    cout << "Press ANY KEY to reroll your d12!\n";
    getch();

    // "Rolls the die", sets d12 roll to random number 1-12:
    d12 = (rand() %12) + 1;

    // Displays roll to user:
    cout << "You reroll your D12!\n";
    elipAnim();
    cout << "\n     ___\n"
         << "    /   \\\n"
         << "    |" << d12 << "  |\n"
         << "    \\___/\n\n";
    cout << "You rolled a " << d12 << "!\n";
   
    pressAnyKeyToContinue();
}

