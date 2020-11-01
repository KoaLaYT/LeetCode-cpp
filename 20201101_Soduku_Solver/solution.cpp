#include "solution.hpp"

const vector<char> DIGITS{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
constexpr int SIZE = 9;

struct Position {
    int row;
    int col;
};

class Board {
public:
    explicit Board(vector<vector<char>>* bb) : b{bb}
    {
        pos.push_back(Position{0, 0});
    }

    bool solve();

private:
    vector<vector<char>>* b;
    vector<Position> pos;

    // find next position to write digit
    // return true if can find one
    // if can't find, means all slot are written, problem solved
    bool find_next_pos()
    {
        auto last_pos = pos.back();
        for (int row = last_pos.row; row < SIZE; ++row) {
            int col = row == last_pos.row ? last_pos.col : 0;
            for (; col < SIZE; ++col) {
                if ((*b)[row][col] == '.') {
                    pos.push_back(Position{row, col});
                    return true;
                }
            }
        }
        return false;
    }

    void write(char d)
    {
        auto cur_pos = pos.back();
        (*b)[cur_pos.row][cur_pos.col] = d;
    }
    void erase()
    {
        auto cur_pos = pos.back();
        at(cur_pos) = '.';
        pos.pop_back();
    }
    bool is_valid(char d)
    {
        return is_row_valid(d) &&
               is_col_valid(d) &&
               is_blk_valid(d);
    }

    char& at(int row, int col) { return (*b)[row][col]; }
    char& at(Position pos) { return at(pos.row, pos.col); }

    bool is_row_valid(char d);
    bool is_col_valid(char d);
    bool is_blk_valid(char d);
};

bool Board::is_row_valid(char d)
{
    auto cur_pos = pos.back();
    for (int col = 0; col < SIZE; ++col) {
        if (at(cur_pos.row, col) == d) return false;
    }
    return true;
}

bool Board::is_col_valid(char d)
{
    auto cur_pos = pos.back();
    for (int row = 0; row < SIZE; ++row) {
        if (at(row, cur_pos.col) == d) return false;
    }
    return true;
}

bool Board::is_blk_valid(char d)
{
    auto cur_pos = pos.back();
    int blk_num = 3 * (cur_pos.row / 3) + cur_pos.col / 3;

    for (int i = 0; i < SIZE; ++i) {
        int row = 3 * (blk_num / 3) + i / 3;
        int col = 3 * (blk_num % 3) + i % 3;
        if (at(row, col) == d) return false;
    }
    return true;
}

bool Board::solve()
{
    if (find_next_pos()) {
        for (const char d : DIGITS) {
            if (is_valid(d)) {
                write(d);
                if (solve()) return true;
                erase();
            }
        }
        return false;
    }
    return true;
}

void Solution::solveSudoku(vector<vector<char>>& board)
{
    Board b{&board};
    b.solve();
}