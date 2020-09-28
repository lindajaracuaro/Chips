// Chips game developed by Linda Pérez
//

#include "Header.h"


std::string PrintWinner(bool playerTurn, player players[])
{

    if (playerTurn)
        return players[1].name;
    else
        return players[0].name;

}

void getUserNames(player players[]) {

    std::cout << "If you rather playing alone enter AI under player 2 field \n";

    std::cout << "Enter Player 1 name \t";
    std::cin >> players[0].name;

    std::cout << "Enter Player 2 name \t";
    std::cin >> players[1].name;

    std::cout << "Good luck! \n";
}

int findAI(player players[], bool playerTurn)
{
    if (players[1].name == "AI" && playerTurn == 0)
        return 1;

    return 0;

}

int AITurn(int chipsInPile, int maxPerTurn)
{
    int chipsTaken;

    if (chipsInPile == 1)
    {
        std::cout << "You can take up to " << 1 << "\t";
        chipsTaken = 1;
    }
    else
    {
        std::cout << "You can take up to " << maxPerTurn << "\t";
        chipsTaken = (rand() % maxPerTurn) + 1;
    }

    std::cout << chipsTaken << "\n\n";

    return chipsTaken;


}

int askMove(bool playerTurn, player players[], int chipsInPile) {

    int chipsTaken;
    int AIenabled = findAI(players, playerTurn);
    int maxPerTurn = chipsInPile * MAX_TURN;


    do {                                                                        //Do till the user writes a valid number of chips to take 

        if (playerTurn == true)                                                     //Depending of the turn the name of the player will be printed
            std::cout << players[0].name << ", how many chips would you like? \n";
        else
            std::cout << players[1].name << ", how many chips would you like? \n";


        if (AIenabled)                                                                 //If the AI is playing then execute turn
            chipsTaken = AITurn(chipsInPile, maxPerTurn);

        else {                                                                      //Else let the players play
            if (chipsInPile == 1)
                maxPerTurn = 1;                                                         //In case there's just one chip in pile, it'll show ONE instead of getting the max value of possible chips to take, else it'll trunk .5 to 0

            std::cout << "You can take up to " << maxPerTurn << "\t";
            std::cin >> chipsTaken;
            std::cout << "\n";
        }

    } while (chipsTaken > maxPerTurn && chipsInPile > 1);


    return chipsTaken;
}

void victoryRegister(bool playerTurn, player players[], int turns, int game) {

    std::ofstream outputFile;
    outputFile.open("victoryRegister.txt", std::ios::app);


    outputFile << "Game number \t" << game
        << "\nThe winner is \t" << PrintWinner(playerTurn, players)
        << "\nThe game took \t" << turns << " turns.\n\n";           //The winner is the one with the turn active

    outputFile.close();

}

