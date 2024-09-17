#ifndef GWENT_H
#define GWENT_H

// Includes:
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

// Namespace:
using namespace std;

// Global Structures:
class Player
{
    public:
        // Integers used for D12 number, type of extra die, die number, final score:
        int d12,
            dieType,            // dieType used for scoreboard.
            dieNum,             // Value rolled on the additional die.
            finalScore,
            
            // NEW CODE
            deception,          // Value used to see if player can hide their roll from the other player
            perception;         // Value used to see if player can determine what the other player rolled
        
        // Whether or not these dice have been used: (true for unused, false for used)
        bool d4,
             d6,
             d8;
        
        // Player constructor:
        Player();
        void addRoll();
        void rollD12();
        void rollD8();
        void rollD6();
        void rollD4();
        void reRoll();
        void qReRoll();
        void easyBotAddRoll();
        void medBotAddRoll();
        void hardBotAddRoll();
        void lunaticBotAddRoll();
        void qEasyBotAddRoll();
        void qMedBotAddRoll();
        void qHardBotAddRoll();
        void qLunaticBotAddRoll();
        void botRollD12();
        void botRollD8();
        void botRollD6();
        void botRollD4();
        void cBotRollD8();
        void cBotRollD6();
        void cBotRollD4();
        void rBotRollD12();
        void rBotRollD8();
        void rBotRollD6();
        void rBotRollD4();
        void displayDice();
        void reset();
};

class RoundScore
{
    public:
        Player player1,
               player2;
        
        // Round constructor:
        RoundScore();
        Player getPlayer1()
            { return player1; }
        Player getPlayer2()
            { return player2; }
        void setPlayer1(Player player)
            { player1 = player; }
        void setPlayer2(Player player)
            { player2 = player; }
        void botDeceptionCheck();
        void pvp1PerceptionCheck();
        void pvp2PerceptionCheck();
        void pvp1DeceptionCheck();
        void pvp2DeceptionCheck();
        void reset();
};

class GameScore
{
    public:
        // Rounds:
        RoundScore round1,
                round2,
                round3;
        
        // Integers:
        // Win and loss counts:
        int winCountP1,
            winCountP2,
            lossCountP1,
            lossCountP2,

        // 0 for not completed, 1 for Player 1 victory, 2 for Player 2 victory:
            r1Winner,
            r2Winner,
            r3Winner,
            gameWinner;
        
        // Game constructor:
        GameScore();
        void winValidation();
        void botWinValidation();
        void pvpWinValidation();
        void autoWinValidation();
        void vsBot();
        void vsLine();
        void vsLocal();
        void quickMode();
        void dmMode();
        void reset();
        void autoScore();
};

// Function Prototypes:
void printInstruct();
void deceiveCheck();
void displayMainMenu(char &);
void pressAnyKeyToContinue();
void elipAnim();



#endif