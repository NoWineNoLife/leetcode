#ifndef LEETCODE_601_700__
#define LEETCODE_601_700__

#include <iostream>
#include <vector>
using namespace std;


namespace algorithm_leetcode
{
class Solution_601_700;

}

class algorithm_leetcode::Solution_601_700
{
public:

    int maxAreaOfIsland(std::vector<std::vector<int>>& grid);

    void assignElement(std::vector<std::vector<int>>& src, int i, int j, int value);
    void show(std::vector<std::vector<int>>& src);
};



#endif
