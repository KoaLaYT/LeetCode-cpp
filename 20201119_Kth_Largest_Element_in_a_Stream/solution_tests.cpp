#include <utility>

#include "../catch.hpp"
#include "solution.hpp"

struct TestCase {
    int k;
    vector<int> init;
    vector<pair<int, int>> steps;
};

TEST_CASE("kth largest element in a stream")
{
    vector<TestCase> cases{
        {
            3,
            {4, 5, 8, 2},
            {{3, 4}, {5, 5}, {10, 5}, {9, 8}, {4, 8}},
        },
        {
            2,
            {1, 2, 3, 4},
            {{5, 4}, {4, 4}, {5, 5}},
        },
        {
            2,
            {0},
            {{-1, -1}, {1, 0}, {-2, 0}, {-4, 0}, {3, 1}},
        },
        {
            7,
            {-10, 1, 3, 1, 4, 10, 3, 9, 4, 5, 1},
            {
                {3, 3},   //1
                {2, 3},   //2
                {3, 3},   //3
                {1, 3},   //4
                {2, 3},   //5
                {4, 3},   //6
                {5, 4},   //7
                {5, 4},   //8
                {6, 4},   //9
                {7, 5},   //10
                {7, 5},   //11
                {8, 5},   //12
                {2, 5},   //13
                {3, 5},   //14
                {1, 5},   //15
                {1, 5},   //16
                {1, 5},   //17
                {10, 6},  //18
                {11, 7},
                {5, 7},
                {6, 7},
                {2, 7},
                {4, 7},
                {7, 7},
                {8, 7},
                {5, 7},
                {6, 7},
            },
        },
    };

    for (auto& c : cases) {
        KthLargest s{c.k, c.init};
        for (auto& step : c.steps) {
            auto res = s.add(step.first);
            REQUIRE(res == step.second);
        }
    }
}
