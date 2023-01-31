/**
******************************************************************************
* @file           : leetcode1_100.h
* @author         : tsing
* @brief          : None
* @attention      : None
* @date           : 2023.01.31
* @email          : tsing0401@outlook.com
******************************************************************************
*/

#ifndef LEETCODE_1_100__
#define LEETCODE_1_100__

#include <iostream>
#include <vector>
using namespace std;


namespace algorithm_leetcode
{
class Solution_1_100;

}

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct unique_pair
{
    int a;
    int b;
    unique_pair(int a_i1, int a_i2):a(a_i1), b(a_i2){};
};


inline bool operator < (const unique_pair& a_1, const unique_pair& a_2)
{
    if(a_1.a < a_2.a){
        return true;
    }
    if(a_1.b < a_2.b){
        return true;
    }
    return false;
}

inline unique_pair& swap_sort(unique_pair& a_1)
{
    if(a_1.a > a_1.b){
        std::swap(a_1.a, a_1.b);
    }
    return a_1;
}


class algorithm_leetcode::Solution_1_100
{
public:
    Solution_1_100();


    /************
     * #1 twoSum easy
     * brute      time complexity: O(n^2), space complexity: O(1)
     * hash       time complexity: O(n), space complexity: O(n)
     ************/
    vector<int> twoSum(vector<int>& nums, int target);

    /************
     * #2 Add Two Numbers Medium
     * brute      time complexity: O(n^2), space complexity: O(1)
     * hash       time complexity: O(n), space complexity: O(n)
     ************/
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

    // 4 Hard Median of Two Sorted Arrays(to do)
    double findMedianSortedArrays_2(std::vector<int>& nums1, std::vector<int>& nums2);
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2);    // n int cache
    // 532. K-diff Pairs in an Array
    int findPairs(std::vector<int>& nums, int k);


    // 5 media Given a string s, return the longest palindromic substring in s.
    string longestPalindrome(string s);



    //695 medium
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid);
    void assignElement(std::vector<std::vector<int>>& src, int i, int j, int value);
    void show(std::vector<std::vector<int>>& src);

    //343 medium
    int integerBreak(int n);
    void getNth(int* ary, int no);


};


#endif
