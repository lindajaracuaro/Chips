// Chips game developed by Linda Pérez
//

#include "Header.h";

int main()
{
    bool playerTurn = 1;
    bool GameOver = 0;
    int chipsInPile, chipsTaken;

    char userChoice;
    player players[2];
    players[0].numWins = 0;
    players[1].numWins = 0;
    int game = 0;

    srand(time(NULL));

    getUserNames(players);


    do {

        chipsInPile = (rand() % MAX_CHIPS) + 1;
        std::cout << "The pile will begin with " << chipsInPile << " chips in pile. \n\n";

        int turnsCounter = 0;                                                                                                       //Se inicializa variable contador de turnos, es importante reiniciarla con el juego

        while (GameOver == false)                                                                                                        //The game starts and will continue till there's zero chips
        {

            chipsTaken = askMove(playerTurn, players, chipsInPile);                                                                 //Let's begin with the turns
            chipsInPile = chipsInPile - chipsTaken;                                                                                      //Updates the pile
            std::cout << "There are " << chipsInPile << " left in the pile \n";
            //No more chips? no more play

            if (chipsInPile == 0)                                                                                                        //If chips are over, also the game
            {
                GameOver = true;
                std::cout << "Congrats " << PrintWinner(playerTurn, players) << " You're the winner!\n";
                game++;                                                                                                                  //Counts the number of the games
            }
            else
            {
                playerTurn = !playerTurn;                                                                                                //Change player's turn
                turnsCounter++;
            }
        }



        if (playerTurn == 0)                                                                                                            //Counts the victory of each player
            players[0].numWins++;
        else
            players[1].numWins++;

        victoryRegister(playerTurn, players, turnsCounter, game);

        std::cout << "Do you want another round? Y / N \t";
        std::cin >> userChoice;
        std::cout << "\n";

        GameOver = false;
        userChoice = toupper(userChoice);


    } while (userChoice == 'Y');

    std::cout << "Victory record \n" << "GAMES\t" << game << "\n"
        << players[0].name << "\t" << players[0].numWins << "\n"
        << players[1].name << "\t" << players[1].numWins << "\n";

    return 0;
}