//
//  137.cpp
//  algorithms
//
//  Created by carltang on 2024/4/22.
//

#include "t137.hpp"
#include <vector>
#include <iostream>
using namespace std;

int singleNumber(vector<int>& nums) {
	/*
	int counts[32] = {0};
	for (auto& n : nums) {
		for (int i = 0; i < 32; ++ i) {
			if (n & 1 << i) {
				counts[i] ++;
			}
		}
	}
	int ret = 0;
	for (int i = 0; i < 32; ++ i) {
		counts[i] %= 3;
		if (counts[i]) ret |= 1 << i;
	}
	return ret;
	 */
	int ret = 0;
	for (int i = 0; i < 32; ++ i) {
		int c = 0;
		for (auto& n : nums) {
			if (n & 1 << i) c ++;
		}

		if (c % 3) {
			ret |= 1 << i;
		}
	}
	return ret;
}

void test_137() {
	vector<int> test_data = {2, 2, 2, 3};
	std::cout << singleNumber(test_data) << endl;
}
