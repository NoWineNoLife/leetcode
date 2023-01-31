#include "leetcode601_700.h"

#include <algorithm>

int algorithm_leetcode::Solution_601_700::maxAreaOfIsland(std::vector<std::vector<int>> &grid)
{
    std::vector<std::vector<int>> v_temp;
    v_temp.resize(grid.size());
    for(auto i = 0; i < v_temp.size(); ++i){
        v_temp[i].resize(grid[i].size());
    }

    for(int i = 0; i < grid.size(); ++i){
        for(int j = 0; j < grid[i].size(); ++j){
            if(0 == grid[i][j]){
                v_temp[i][j] = 0;
            }
            else{
                v_temp[i][j] = 1;
            }
        }
    }

    int no = 1;
    for(int i = 0; i < grid.size(); ++i){
        for(int j = 0; j < grid[i].size(); ++j){
            if(1 == v_temp[i][j]){
                assignElement(v_temp, i, j, no + 100);
                ++no;
            }
        }
    }


    // statistic of every contours
    std::vector<int> v_contours;
    std::fill(v_contours.begin(), v_contours.end(), 0);
    for(int i = 0; i < v_temp.size(); ++i){
        for(int j = 0; j < v_temp[i].size(); ++j){
            if(100 <= v_temp[i][j]){
                if(v_contours.size() < v_temp[i][j] - 99){
                    v_contours.resize(v_temp[i][j] - 99);
                }
                ++v_contours[v_temp[i][j] - 100];
            }
        }
    }
    if(v_contours.empty()){
        return 0;
    }
    int no_cpy = *std::max_element(v_contours.begin(), v_contours.end());
    // return no_cpy;
    int iter {0};
    for(; iter < v_contours.size(); ++iter){
        if(no_cpy == v_contours[iter]){
            break;
        }
    }
    iter += 100;
    for(int i = 0; i < v_temp.size(); ++i){
        for(int j = 0; j < v_temp[i].size(); ++j){
            if(iter == v_temp[i][j]){
                grid[i][j] = 1;
            }
            else{
                grid[i][j] = 0;
            }
        }
    }
}


void algorithm_leetcode::Solution_601_700::assignElement(std::vector<std::vector<int> > &src, int i, int j, int value)
{
    src[i][j] = value;
    if( 0 <= (i - 1) && 1 == src[i - 1][j]){
        assignElement(src, i - 1, j, value);
    }
    if( src.size() > (i + 1) && 1 == src[i + 1][j]){
        assignElement(src, i + 1, j, value);
    }
    if( 0 <= (j - 1) && 1 == src[i][j - 1]){
        assignElement(src, i, j - 1, value);
    }
    if( src[i].size() > (j + 1) && 1 == src[i][j + 1]){
        assignElement(src, i, j + 1, value);
    }
}

void algorithm_leetcode::Solution_601_700::show(std::vector<std::vector<int> > &src)
{
    for(int i = 0; i < src.size(); ++i){
        for(int j = 0; j < src[i].size(); ++j){
            std::cout << src[i][j] << "\t";
        }
        std::cout << std::endl;
    }

}
