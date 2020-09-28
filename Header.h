// Chips game developed by Linda Pérez
//

#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>

struct player {
    std::string name;
    int numWins;
};

std::string PrintWinner(bool, player[]);
int askMove(bool playerTurn, player[], int chipsInPile);                                                           //Asks player to move, how much, it verifies if it's a valid number and finally returns the chipsTaken
void getUserNames(player[]);

int findAI(player[], bool);
int AITurn(int, int);
void victoryRegister(bool, player[], int, int);

const int MAX_CHIPS = 100;
const float MAX_TURN = .5;

