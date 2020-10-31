#include "solution.hpp"

class Range {
public:
    int start;
    int end;

    Range(int s, int e) : start{s}, end{e} {}
    int middle() { return start + (end - start) / 2; }
    bool empty() { return start >= end; }
};

class Matrix {
public:
    Matrix(vector<vector<int>>* mm, Range r, Range c)
        : m{mm}, row{r}, col{c} {}

    int middle()
    {
        int rm = row.middle();
        int rc = col.middle();
        return (*m)[rm][rc];
    }

    bool empty() { return row.empty() || col.empty(); }

    Matrix left()
    {
        Range c(col.start, col.middle());
        return Matrix{m, row, c};
    }

    Matrix topright()
    {
        Range r(row.start, row.middle());
        Range c(col.middle(), col.end);
        return Matrix{m, r, c};
    }

    Matrix bottomleft()
    {
        Range r(row.middle() + 1, row.end);
        Range c(col.start, col.middle() + 1);
        return Matrix{m, r, c};
    }

    Matrix right()
    {
        Range c(col.middle() + 1, col.end);
        return Matrix{m, row, c};
    }

    bool search(int target);

private:
    vector<vector<int>>* m;
    Range row;
    Range col;
};

bool Matrix::search(int target)
{
    if (empty()) return false;

    int mid = middle();

    if (mid == target) return true;
    if (mid > target) {
        return left().search(target) || topright().search(target);
    } else {
        return right().search(target) || bottomleft().search(target);
    }
}

bool Solution::searchMatrix(vector<vector<int>>& matrix, int target)
{
    if (matrix.empty()) return false;

    Range rr(0, matrix.size());
    Range cr(0, matrix[0].size());
    Matrix m{&matrix, rr, cr};

    return m.search(target);
}