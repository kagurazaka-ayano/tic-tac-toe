#include "Board.h"
#include <cstring>

Board::EndGameStat Board::checkVictory() const
{
    if (played == 9)
        return TIE;
    if (data[0][0] == data[1][1] && data[1][1] == data[2][2]) {
        return (Board::EndGameStat)data[0][0];
    }
    if (data[0][2] == data[1][1] && data[1][1] == data[2][0]) {
        return (Board::EndGameStat)data[0][2];
    }
    for (int i = 0; i < 3; ++i) {
        if (data[i][0] == data[i][1] && data[i][1] == data[i][2]) {
            return (Board::EndGameStat)data[i][0];
        }
        if (data[0][i] == data[1][i] && data[1][i] == data[2][i]) {
            return (Board::EndGameStat)data[0][i];
        }
    }
    return CONTINUE;
}

Board::PlacementResult Board::play(int x, int y, int player)
{
    auto stat = validatePlacement(x, y);
    if (stat == VALID_PLACEMENT) {
        data[x][y] = player;
        ++played;
    }
    return stat;
}

std::string Board::getPlacementMsg(PlacementResult res)
{
    return placement_msg[res];
}

Board::operator std::string() const
{
    auto str = std::string(board_template);
    int idx = 0;
    const char* data_display_ref = " XO";
    while (str.find('k') != std::string::npos) {
        str[str.find('k')] = data_display_ref[data[idx / 3][idx % 3]];
        idx++;
    }
    return str;
}

Board::PlacementResult Board::validatePlacement(int x, int y) const
{
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        return NUMBER_ONLY;
    }
    if (data[x][y])
        return ALREADY_OCCUPIED;
    if (x < 0 || y < 0)
        return NEGATIVE_NUM;
    auto within = [](int num, int left, int right) {
        return (left <= num) && (num <= right);
    };
    if (!(within(x, 0, 2) && within(y, 0, 2)))
        return OUT_OF_RANGE;
    return VALID_PLACEMENT;
}

std::ostream& operator<<(std::ostream& os, const Board& other)
{
    os << std::string(other);
    return os;
}

Board::Board()
{
    memset(data, 0, 9 * sizeof(int));
}
