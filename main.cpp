/**
 ******************************************************************************
 * @file           : main.cpp
 * @author         : tsing
 * @brief          : None
 * @attention      : None
 * @date           : 2023.01.31
 * @email          : tsing0401@outlook.com
 ******************************************************************************
 */

#include <bits/stdc++.h>
#include <doctest/doctest.h>
#include <algorithm>
#include <chrono>
#include <iostream>
//#include <backward/backward_warning.h>

#include "leetcode1_100.h"
#include "leetcode601_700.h"

namespace test_leetcode
{
	TEST_CASE("TEST doc")
	{
		algorithm_leetcode::Solution_1_100 solution;
		std::vector<std::vector<int>> v{
			{0, 0, 1, 1}, {0, 1, 1, 0}, {0, 1, 0, 1}};

		std::vector<std::vector<int>> vv{{0, 0, 0, 0, 0, 0, 0, 0}};
		CHECK(solution.maxAreaOfIsland(vv) == 5);
	}  // namespace test_leetcode

	;

}  // namespace test_leetcode
   // int main() {
   //
   //     test_leetcode::test1_100();
   //
   //
   //
   //   ListNode* l1 = new ListNode{5};
   //   //    l1->next = new ListNode{8};
   //   ListNode* l2 = new ListNode{5};
   //   //    so.addTwoNumbers(l1, l2);
   //
   //   std::vector<int> v_tmp{1, 3, 1, 5, 4};
   //   //    std::cout << so.findPairs(v_tmp, 0) << std::endl;
   //
   //   algorithm_leetcode::Solution_601_700 so;
   //   std::vector<std::vector<int>> v{{0, 0, 1, 1}, {0, 1, 1, 0}, {0, 1, 0,
   //   1}};
   //
   //   std::vector<std::vector<int>> vv{{0, 0, 0, 0, 0, 0, 0, 0}};
   //   so.maxAreaOfIsland(vv);
   //
   //   return 0;
   // }
