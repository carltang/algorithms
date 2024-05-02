//
//  t153.cpp
//  algorithms
//
//  Created by carltang on 2024/4/27.
//

#include "t153.hpp"
#include <vector>
#include <iostream>

using namespace std;

int findMin(vector<int>& nums) {
	 if (nums.size() == 1) return nums[0];
	 if (nums.size() == 2) return min(nums[0], nums[1]);
	 int left = 0;
	 int right = nums.size() - 1;
	 if (nums[left] < nums[right]) return nums[left];
	 while (left < right - 1) {
		 int mid = (left + right) / 2;
		 if (nums[mid] < nums[mid - 1]) return nums[mid];
		 if (nums[mid] > nums[left]) {
			 left = mid;
		 } else if (nums[mid] < nums[right]) {
			 right = mid;
		 }
	 }
	 return nums[right];
 }

void test_153 () {
	vector<int> nums = {3, 4, 5, 1, 2};
	cout << findMin(nums) << endl;
}
