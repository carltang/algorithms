//
//  t34.cpp
//  algorithms
//
//  Created by carltang on 2024/4/27.
//

#include "t34.hpp"
#include <vector>
#include <iostream>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
	vector<int> ret = {-1, -1};
	if (nums.size() == 0 || target < nums[0] || target > nums[nums.size() - 1]) return ret;
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (nums[mid] < target) {
			left = mid + 1;
		} else if (nums[mid] > target) {
			right = mid - 1;
		} else {
			ret[0] = ret[1] = mid;
			while (ret[0] > 0 && nums[ret[0] - 1] == target) ret[0] --;
			while (ret[1] < nums.size() - 1 && nums[ret[1] + 1] == target) ret[1] ++;
			return move(ret);
		}
	}
	return ret;
}

void test_34() {
	vector<int> nums = {5,7,7,8,8,10};
	vector<int> ret = searchRange(nums, 8);
	cout << ret[0] << " " << ret[1] << endl;
}
