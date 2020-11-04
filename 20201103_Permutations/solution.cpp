#include "solution.hpp"

#include <optional>
#include <unordered_set>

class Permutations {
public:
    Permutations(vector<int>& n) : nums{&n}, order(n.size()) {}
    vector<vector<int>> generate();

private:
    vector<int>* nums;
    vector<int> combination;
    vector<int> order;
    unordered_set<int> used;

    int size() { return nums->size(); }
    bool found() { return combination.size() == size(); }
    void backtrace()
    {
        int v = combination.back();
        used.erase(v);
        combination.pop_back();
    }
    int& next_val_pos() { return order[combination.size()]; }
    bool is_used(int v) { return used.find(v) != used.end(); }

    optional<int> next();
};

optional<int> Permutations::next()
{
    if (next_val_pos() >= nums->size()) {
        if (combination.empty()) {
            return nullopt;
        }
        next_val_pos() = 0;
        backtrace();
        return next();
    }
    int v = (*nums)[next_val_pos()];
    if (is_used(v)) {
        ++next_val_pos();
        return next();
    }
    ++next_val_pos();
    return optional{v};
}

vector<vector<int>> Permutations::generate()
{
    vector<vector<int>> collection;

    while (true) {
        if (found()) {
            collection.push_back(vector<int>{combination});
            backtrace();
        } else {
            optional<int> v = next();
            if (!v.has_value()) break;

            combination.push_back(v.value());
            used.insert(v.value());
        }
    }

    return collection;
}

vector<vector<int>> Solution::permute(vector<int>& nums)
{
    Permutations p{nums};
    return p.generate();
}