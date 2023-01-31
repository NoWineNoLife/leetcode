/**
* @file [file-name]
* @brief brief description for the file.
* @author jones
* {@author <list of authors>}
* [@author <authors description>]
* @date <date>
* @version <version number>
*
* detailed description for the file.
*/



#include "leetcode1_100.h"
#include <iostream>
#include <set>
#include <unordered_map>
#include <algorithm>

namespace algorithm_leetcode {

    Solution_1_100::Solution_1_100()
    {

    }

    // 1 hash
    vector<int> Solution_1_100::twoSum(vector<int>& nums, int target)
    {
        std::unordered_map<int, int> m;
        size_t length = nums.size();
        std::vector<int> v;
        for(size_t i = 0; i < length; ++i){
            if(m.end() != m.find(target - nums[i])){
                v.push_back(int(i));
                v.push_back(m.find(target - nums[i])->second);
                return v;
            }
            m.insert({nums[i], int(i)});
        }
        return v;

    }

    // 2
    ListNode* Solution_1_100::addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* head = new ListNode;
        ListNode* node_tmp = new ListNode;
        head->next = node_tmp;
        int carry = 0;
        while( nullptr != l1 && nullptr != l2){
            node_tmp->val = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;
            l1 = l1->next;
            l2 = l2->next;
            if(nullptr != l1 || nullptr != l2 || carry){
                node_tmp->next = new ListNode;
                node_tmp = node_tmp->next;
            }
        }
        while(nullptr != l1){
            node_tmp->val = (l1->val + carry) % 10;
            carry = (l1->val + carry) / 10;
            l1 = l1->next;
            if(nullptr != l1  || carry){
                node_tmp->next = new ListNode;
                node_tmp = node_tmp->next;
            }
        }
        while(nullptr != l2){
            node_tmp->val = (l2->val + carry) % 10;
            carry = (l2->val + carry) / 10;
            l2 = l2->next;
            if(nullptr != l2  || carry){
                node_tmp->next = new ListNode;
                node_tmp = node_tmp->next;
            }
        }
        node_tmp->val += carry;
        ListNode* p = head->next;
        delete head;
        return p;
    }

    // 5
    string Solution_1_100::longestPalindrome(string s)
    {

    }


    // 532
    int Solution_1_100::findPairs(std::vector<int>& nums, int k)
    {
        std::set<unique_pair> s;
        for(size_t i = 0; i < nums.size() - 1; ++i){
            for(size_t j = i + 1; j < nums.size(); ++j){
                if(std::abs(nums[i] - nums[j]) == k){
                    unique_pair u_tmp{nums[i], nums[j]};
                    s.insert(swap_sort(u_tmp));
                }
            }
        }
        return s.size();
    }


    // 695
    int Solution_1_100::maxAreaOfIsland(std::vector<std::vector<int>> &grid)
    {
        std::vector<std::vector<int>> v_temp;
        v_temp.resize(grid.size());
        for(size_t i = 0; i < v_temp.size(); ++i){
            v_temp[i].resize(grid[i].size());
        }

        for(size_t i = 0; i < grid.size(); ++i){
            for(size_t j = 0; j < grid[i].size(); ++j){
                if(0 == grid[i][j]){
                    v_temp[i][j] = 0;
                }
                else{
                    v_temp[i][j] = 1;
                }
            }
        }

        int no = 1;
        for(size_t i = 0; i < grid.size(); ++i){
            for(size_t j = 0; j < grid[i].size(); ++j){
                if(1 == v_temp[i][j]){
                    assignElement(v_temp, i, j, no + 100);
                    ++no;
                }
            }
        }


        // statistic of every contours
        std::vector<int> v_contours;
        std::fill(v_contours.begin(), v_contours.end(), 0);
        for(size_t i = 0; i < v_temp.size(); ++i){
            for(size_t j = 0; j < v_temp[i].size(); ++j){
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


    void Solution_1_100::assignElement(std::vector<std::vector<int> > &src, int i, int j, int value)
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

    void Solution_1_100::show(std::vector<std::vector<int> > &src)
    {
        for(int i = 0; i < src.size(); ++i){
            for(int j = 0; j < src[i].size(); ++j){
                std::cout << src[i][j] << "\t";
            }
            std::cout << std::endl;
        }

    }


    //343
    int Solution_1_100::integerBreak(int n)
    {
        int int_result = 0;
        int* memory = new int[n];

        int i = 0;
        for(; i < n; ++i)
        {
            memory[i] = 0;
        }


        for(i = 1; i < n; ++i)
        {
            if( 0 == memory[i])
            {
                getNth(memory, i);
            }
            if( 0 == memory[ n - i])
            {
                getNth(memory, n - i);
            }

            if( int_result < memory[i] * memory[ n - i])
            {
                int_result = memory[i] * memory[ n - i];
            }
        }
        return int_result;

    }

    // 4 Hard Median of Two Sorted Arrays
    double Solution_1_100::findMedianSortedArrays_2(vector<int>& nums1, vector<int>& nums2) {
        size_t m = nums1.size();
        size_t n = nums2.size();
        size_t total = nums1.size() + nums2.size();
        if( (total) % 2 == 1){
            total /= 2;
            size_t i{0};
            size_t j{0};
            for(size_t t = 0; t < total; ++t){
                if(nums1[i] <= nums2[j] && i < m){
                    ++i;
                }
                else if(nums1[i] <= nums2[j]){
                    ++j;
                }
                else if(nums1[i] > nums2[j] && j < n){
                    ++j;
                }
                else {
                    ++i;
                }
            }
            int tmp;
            if(i < m){
                tmp = nums1[i];
                if(j < n){
                    return tmp < nums2[j]? tmp: nums2[j];
                }
            }
            return nums2[j];
        }
        else{
            total /= 2;
            size_t i{0};
            size_t j{0};
            for(size_t t = 0; t < total; ++t){
                if(nums1[i] <= nums2[j] && i < m){
                    ++i;
                }
                else if(nums1[i] <= nums2[j]){
                    ++j;
                }
                else if(nums1[i] > nums2[j] && j < n){
                    ++j;
                }
                else {
                    ++i;
                }
            }
            int tmp;
            if(i < m){
                tmp = nums1[i];
                if(j < n){
                    return tmp < nums2[j]? tmp: nums2[j];
                }
            }
            return nums2[j];
        }



    }


    // 4 Hard Median of Two Sorted Arrays
    double Solution_1_100::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        size_t total = nums1.size() + nums2.size();
        std::vector<int> num(total);
        size_t m{nums1.size()};
        size_t n{nums2.size()};
        size_t i{0};
        size_t j{0};
        for(size_t t = 0; t < total; ++t){
            if(i < m && j < n){
                if(nums1[i] <= nums2[j]){
                    num[t] = nums1[i];
                    ++i;
                }
                else{
                    num[t] = nums2[j];
                    ++j;
                }
            }
            else if(i < m){
                num[t] = nums1[i];
                ++i;
            }
            else{
                num[t] = nums2[j];
                ++j;
            }
        }
        if( 1 == total % 2 ){
            return num[total / 2];
        }
        return (double(num[total / 2 - 1]) + num[total / 2]) / 2;

    }

    void Solution_1_100::getNth(int* ary, int no)
    {
        if( 0 == no)
        {
            return;
        }

        if( 0 != ary[no])
            return ;


        if( 1 == no)
        {
            ary[no] = 1;
            return ;
        }


        int i = 1;
        int int_result = 1;
        for(; i < no; ++i)
        {
            if( 0 == ary[i])
            {
                getNth(ary, i);
            }
            if( 0 == ary[ no - i])
            {
                getNth(ary, no - i);
            }

            if( int_result < ary[i] * ary[ no - i])
            {
                int_result = ary[i] * ary[ no - i];
            }

        }
        if( int_result < no)
        {
            int_result = no;
        }
        ary[no] = int_result;
    }

}

