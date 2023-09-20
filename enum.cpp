#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

enum StudentNames
{
    kenny, // 0
    kyle, // 1
    stan, // 2
    butters, // 3
    cartman, // 4
    max_students // 5
};

int main()
{
    std::vector<int> testScores { 78, 94, 66, 77, 14 };

    cout << testScores[StudentNames::stan] << endl;

    return 0;
}