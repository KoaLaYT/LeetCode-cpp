#include "solution.hpp"

#include <cmath>
#include <vector>

using namespace std;

struct QueenPosition {
    int row;
    int col;
};

class Board {
public:
    explicit Board(int n) : size{n} {}
    int solve_recu() { return solve(0, 0); }  // recursion
    int solve_iter();                         // iteration

private:
    vector<QueenPosition> queens;  // placed queen postions
    int size;                      // board size

    void place_queen(int row, int col) { queens.push_back(QueenPosition{row, col}); }
    void remove_queen() { queens.pop_back(); }
    bool is_not_under_attack(int row, int col)
    {
        for (const auto& q : queens) {
            if (q.col == col) return false;
            if (abs(q.row - row) == abs(q.col - col)) return false;
        }
        return true;
    }

    int solve(int row, int count);
};

int Board::solve(int row, int count)
{
    // for each column
    for (int col = 0; col < size; col++) {
        if (is_not_under_attack(row, col)) {
            place_queen(row, col);
            if (row + 1 == size) {
                // find a solution
                ++count;
            } else {
                // go next row
                count = solve(row + 1, count);
            }
            remove_queen();
        }
    }
    return count;
}

int Board::solve_iter()
{
    int row = 0;
    int col = 0;
    int count = 0;
    auto traceback = [this, &row, &col]() {
        row = this->queens.back().row;
        col = this->queens.back().col + 1;
        this->remove_queen();
    };

    while (size > 0) {
        if (row == size) {
            ++count;
            traceback();
        } else if (col == size) {
            if (queens.empty()) break;
            traceback();
        } else {
            while (col < size) {
                if (is_not_under_attack(row, col)) {
                    place_queen(row, col);
                    row++;
                    col = 0;
                    break;
                }
                col++;
            }
        }
    }
    return count;
}

int Solution::totalNQueens(int n)
{
    Board b{n};
    // return b.solve_recu();
    return b.solve_iter();
}