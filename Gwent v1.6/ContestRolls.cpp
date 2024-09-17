/******************************************************************
*   Authors:    Gage Jones, Mason Dye
*   Date:       Sunday, August 1st, 2021
*   Version:    1.6
*   Title:      ContestRolls.cpp
*   Purpose:    Holds the functions for contesting ability 
*               checks such as perception and deception
******************************************************************/

#include "Gwent.h"

void RoundScore::botDeceptionCheck()
{
    char answer;
    int vantage, modifier;

    cout << "Will you attempt to discern what they have? (Y/N)\n";
    cin >> answer;
    cout << "\n";

    while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n')
    {
        cout << "Invalid Input, please input either Y or N\n";
        cin >> answer;
        cout << "\n";
    }

    if (answer == 'Y' || answer == 'y')
    {
        cout << "Roll for Perception!\n";
        pressAnyKeyToContinue();

        player1.perception = (rand() % 20) + 1;

        cout << "Do you have advantage or disadvantage? (Y/N)\n";
        cin >> answer;

        while (answer != 'Y' && answer != 'N' && answer != 'y' && answer != 'n')
        {
            cout << "Invalid Input! Please enter either Y or N!\n";
            cin >> answer;
            cout << "\n";
        }

        if (answer == 'Y' || answer == 'y')
        {
            cout << "Is it advantage or disadvantage?\n"
                << "(A or D)\n";
            cin >> answer;

            while (answer != 'A' && answer != 'a' && answer != 'D' && answer != 'D')
            {
                cout << "Invalid Input! Please enter either A or D!\n";
                cin >> answer;
                cout << "\n";
            }

            if (answer == 'A' || answer == 'a')
            {
                vantage = (rand() % 20) + 1;

                if (vantage > player1.perception)
                {
                    player1.perception = vantage;
                }
            }
            if (answer == 'D' || answer == 'D')
            {
                vantage = (rand() % 20) + 1;

                if(vantage < player1.perception)
                {
                    player1.perception = vantage;
                }
            }
        }

        cout << "\nYou rolled a " << player1.perception << "!\n"
            << " What is your perception modifier?\n";
        cin >> modifier;

        cout << "You rolled a " << player1.perception << " plus " << modifier << " !\n" 
            << "In total that's " << player1.perception + modifier << "!\n";

        player1.perception = player1.perception + modifier;

        if(player1.perception >= player2.deception + 5)
        {
            cout << "\nYour " << player1.perception << " in perception beat out your opponent's " << player2.deception << " in deception by " << player1.perception - player2.deception << " !\n\n"; 
            cout << "You completely see through them!\n";
            cout << "Your opponent has rolled a number between " << player2.finalScore - 1 << " and " << player2.finalScore + 1 << "!\n";
        }
        else if (player1.perception >= player2.deception)
        {
            cout << "\nYour " << player1.perception << " in perception beat out your opponent's " << player2.deception << " in deception!\n\n";
            cout << "You see through them!\n";
            cout << "Your opponent has rolled a number between " << player2.finalScore - 2 << " and " << player2.finalScore + 2 << "!\n";
        }
        else
        {
            cout << "You cannot see past their poker face...\n";
        }
    }

}


void RoundScore::pvp1PerceptionCheck()
{
    char answer;
    int vantage, modifier;

    cout << "Will you attempt to discern what your opponent has? (Y/N)\n";
    cin >> answer;
    cout << "\n";

    while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n')
    {
        cout << "Invalid Input, please input either Y or N\n";
        cin >> answer;
        cout << "\n";
    }

    if (answer == 'Y' || answer == 'y')
    {
        cout << "Roll for Perception!\n";
        pressAnyKeyToContinue();

        player1.perception = (rand() % 20) + 1;

        cout << "Do you have advantage or disadvantage? (Y/N)\n";
        cin >> answer;

        while (answer != 'Y' && answer != 'N' && answer != 'y' && answer != 'n')
        {
            cout << "Invalid Input! Please enter either Y or N!\n";
            cin >> answer;
            cout << "\n";
        }

        if (answer == 'Y' || answer == 'y')
        {
            cout << "Is it advantage or disadvantage?\n"
                << "(A or D)\n";
            cin >> answer;

            while (answer != 'A' && answer != 'a' && answer != 'D' && answer != 'D')
            {
                cout << "Invalid Input! Please enter either A or D!\n";
                cin >> answer;
                cout << "\n";
            }

            if (answer == 'A' || answer == 'a')
            {
                vantage = (rand() % 20) + 1;

                if (vantage > player1.perception)
                {
                    player1.perception = vantage;
                }
            }
            if (answer == 'D' || answer == 'D')
            {
                vantage = (rand() % 20) + 1;

                if(vantage < player1.perception)
                {
                    player1.perception = vantage;
                }
            }
        }

        cout << "\nYou rolled a " << player1.perception << "!\n"
            << " What is your perception modifier?\n";
        cin >> modifier;

        cout << "You rolled a " << player1.perception << " plus " << modifier << " !\n" 
            << "In total that's " << player1.perception + modifier << "!\n";

        player1.perception = player1.perception + modifier;

        if(player1.perception >= player2.deception + 5)
        {
            cout << "\nYour " << player1.perception << " in perception beat out your opponent's " << player2.deception << " in deception by " << player1.perception - player2.deception << " !\n\n"; 
            cout << "You completely see through them!\n";
            cout << "Your opponent has rolled a number between " << player2.finalScore - 1 << " and " << player2.finalScore + 1 << "!\n";
        }
        else if (player1.perception >= player2.deception)
        {
            cout << "\nYour " << player1.perception << " in perception beat out your opponent's " << player2.deception << " in deception!\n\n";
            cout << "You see through them!\n";
            cout << "Your opponent has rolled a number between " << player2.finalScore - 2 << " and " << player2.finalScore + 2 << "!\n";
        }
        else
        {
            cout << "\n\nYou cannot see past their poker face...\n\n";
        }
    }
}

void RoundScore::pvp2PerceptionCheck()
{
    char answer;
    int vantage, modifier;

    cout << "Will you attempt to discern what your opponent has? (Y/N)\n";
    cin >> answer;
    cout << "\n";

    while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n')
    {
        cout << "Invalid Input, please input either Y or N\n";
        cin >> answer;
        cout << "\n";
    }

    if (answer == 'Y' || answer == 'y')
    {
        cout << "Roll for Perception!\n";
        pressAnyKeyToContinue();

        player2.perception = (rand() % 20) + 1;

        cout << "Do you have advantage or disadvantage? (Y/N)\n";
        cin >> answer;

        while (answer != 'Y' && answer != 'N' && answer != 'y' && answer != 'n')
        {
            cout << "Invalid Input! Please enter either Y or N!\n";
            cin >> answer;
            cout << "\n";
        }

        if (answer == 'Y' || answer == 'y')
        {
            cout << "Is it advantage or disadvantage?\n"
                << "(A or D)\n";
            cin >> answer;

            while (answer != 'A' && answer != 'a' && answer != 'D' && answer != 'D')
            {
                cout << "Invalid Input! Please enter either A or D!\n";
                cin >> answer;
                cout << "\n";
            }

            if (answer == 'A' || answer == 'a')
            {
                vantage = (rand() % 20) + 1;

                if (vantage > player2.perception)
                {
                    player2.perception = vantage;
                }
            }
            if (answer == 'D' || answer == 'D')
            {
                vantage = (rand() % 20) + 1;

                if(vantage < player2.perception)
                {
                    player2.perception = vantage;
                }
            }
        }

        cout << "\nYou rolled a " << player2.perception << "!\n"
            << " What is your perception modifier?\n";
        cin >> modifier;

        cout << "You rolled a " << player2.perception << " plus " << modifier << " !\n" 
            << "In total that's " << player2.perception + modifier << "!\n";

        player2.perception = player2.perception + modifier;

        if(player2.perception >= player1.deception + 5)
        {
            cout << "\nYour " << player2.perception << " in perception beat out your opponent's " << player1.deception << " in deception by " << player2.perception - player1.deception << " !\n\n"; 
            cout << "You completely see through them!\n";
            cout << "Your opponent has rolled a number between " << player1.finalScore - 1 << " and " << player1.finalScore + 1 << "!\n";
        }
        else if (player2.perception >= player1.deception)
        {
            cout << "\nYour " << player2.perception << " in perception beat out your opponent's " << player1.deception << " in deception!\n\n";
            cout << "You see through them!\n";
            cout << "Your opponent has rolled a number between " << player1.finalScore - 2 << " and " << player1.finalScore + 2 << "!\n";
        }
        else
        {
            cout << "\n\nYou cannot see past their poker face...\n\n";
        }
    }
}

void RoundScore::pvp1DeceptionCheck()
{
    char answer; 
    int vantage, modifier;

    cout << "\nRoll a deception check to see how good your poker face is this round!\n";

    pressAnyKeyToContinue();
    
    player1.deception = (rand() % 20) + 1;

    cout << "Do you have advantage or disadvantage? (Y/N)\n";
    cin >> answer;

    while(answer != 'Y' && answer != 'N' && answer != 'y' && answer != 'n')
    {
        cout << "Invalid Input! Please enter either Y or N!\n";
        cin >> answer;
        cout << "\n";
    }

    if(answer == 'Y' || answer == 'y')
    {
        cout << "Is it advantage or disadvantage?\n"
             << "(A or D)\n";
        cin >> answer;

        while(answer != 'A' && answer != 'a' && answer != 'D' && answer != 'D')
        {
            cout << "Invalid Input! Please enter either A or D!\n";
            cin >> answer;
            cout << "\n";
        }

        if(answer == 'A' || answer == 'a')
        {
            vantage = (rand() % 20) + 1;

            if(vantage > player1.deception)
            {
                player1.deception = vantage;
            }
            else
                player1.deception = player1.deception;
        }
        if(answer == 'D' || answer == 'D')
        {
            vantage = (rand() % 20) + 1;

            if(vantage < player1.deception)
            {
                player1.deception = vantage;
            }
            else
                player1.deception = player1.deception;
        }
    }


    cout << "\nRoll!\n";

    pressAnyKeyToContinue();
    elipAnim();

    cout << "\nYou rolled a " << player1.deception << "!\n"
         << " What is your deception modifier?\n";
    cin >> modifier;

    cout << "You rolled a " << player1.deception << " plus " << modifier << " !\n" 
         << "In total that's " << player1.deception + modifier << "!\n";

    player1.deception = player1.deception + modifier;
}

void RoundScore::pvp2DeceptionCheck()
{
    char answer; 
    int vantage, modifier;

    cout << "\nRoll a deception check to see how good your poker face is this round!\n";

    pressAnyKeyToContinue();
    
    player2.deception = (rand() % 20) + 1;

    cout << "Do you have advantage or disadvantage? (Y/N)\n";
    cin >> answer;

    while(answer != 'Y' && answer != 'N' && answer != 'y' && answer != 'n')
    {
        cout << "Invalid Input! Please enter either Y or N!\n";
        cin >> answer;
        cout << "\n";
    }

    if(answer == 'Y' || answer == 'y')
    {
        cout << "Is it advantage or disadvantage?\n"
             << "(A or D)\n";
        cin >> answer;

        while(answer != 'A' && answer != 'a' && answer != 'D' && answer != 'D')
        {
            cout << "Invalid Input! Please enter either A or D!\n";
            cin >> answer;
            cout << "\n";
        }

        if(answer == 'A' || answer == 'a')
        {
            vantage = (rand() % 20) + 1;

            if(vantage > player2.deception)
            {
                player2.deception = vantage;
            }
            else
                player2.deception = player2.deception;
        }
        if(answer == 'D' || answer == 'D')
        {
            vantage = (rand() % 20) + 1;

            if(vantage < player2.deception)
            {
                player2.deception = vantage;
            }
            else
                player2.deception = player2.deception;
        }
    }


    cout << "\nRoll!\n";

    pressAnyKeyToContinue();
    elipAnim();

    cout << "\nYou rolled a " << player2.deception << "!\n"
         << " What is your deception modifier?\n";
    cin >> modifier;

    cout << "You rolled a " << player2.deception << " plus " << modifier << " !\n" 
         << "In total that's " << player2.deception + modifier << "!\n";

    player2.deception = player2.deception + modifier;
}

