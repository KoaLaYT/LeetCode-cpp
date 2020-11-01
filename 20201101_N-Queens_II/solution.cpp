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
    int solve() { return solve(0, 0); }

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

int Solution::totalNQueens(int n)
{
    Board b{n};

    return b.solve();
}