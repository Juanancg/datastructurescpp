#include <iostream>
#include <vector>

void printPlayers(std::vector<int> players) {
    std::cout << "Players: ";

    for (int i = 0; i < players.size(); i++) {
        std::cout << players.at(i) << " ";
    }

    std::cout << std::endl;
}

int main(int argc, char **argv) {
    std::cout << "Josephus problem" << std::endl;

    int Mpasses = 4;
    int Npeople = 123;

    std::vector<int> game;

    for (int i = 1; i <= Npeople; i++) {
        game.push_back(i);
    }

    printPlayers(game);

    int NpeopleRemaining = Npeople;

    std::cout << "The game starts!" << std::endl;

    for (int i = 0; i < Npeople; i++) {
        int player = 0;
        if (Mpasses < NpeopleRemaining) {
            player = Mpasses;
        } else {
            player = (Mpasses % NpeopleRemaining);
            if (Npeople < player) {
                player = player - Npeople;
            }
        }

        NpeopleRemaining--;
        std::cout << "Eliminated player " << game.at(player) << " Remaining " << NpeopleRemaining << std::endl;
        game.erase(game.begin() + player);
        printPlayers(game);
    }

    return 0;
}
