#include <iostream>
#include <string>
#include <array>
#include "Board.h"


int main() {
    Board board = Board();
    bool player = 0;

    std::array<std::string, 2> player_str = {
        "Player 1",
        "Player 2"
    };
    std::cout << "Welcome to tic tac toe" << std::endl;
    std::cout << "----------------------" << std::endl;
    int victory;
    // game loop
    while((victory = board.checkVictory()) == Board::EndGameStat::CONTINUE) {
        std::cout << "Now it's " << player_str[player] << "'s turn" << std::endl;
        auto stat = Board::PlacementResult::NO_INPUT;
        while(stat != Board::PlacementResult::VALID_PLACEMENT) {
            std::cout << board;
            std::cout << "where do you want to play? (enter a 2-tuple (row and col) with space as delimeter, upper left is (0, 0)):";
            int x, y;
            std::cin >> x >> y;
            stat = board.play(x, y, player + 1);
            std::cout << Board::getPlacementMsg(stat) << std::endl;
        }
        player = !player;
    }
    std::cout << "EndGame!" << std::endl;
    if (victory == Board::EndGameStat::TIE) {
        std::cout << "Tie!";
    }
    else {
        std::cout << player_str[victory - 1] << " win!" << std::endl;
    }
}