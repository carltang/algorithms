//
//  t373.cpp
//  algorithms
//
//  Created by carltang on 2024/4/24.
//

#include "t373.hpp"
#include <queue>
#include <vector>
#include<utility>
#include <iostream>

using namespace std;

// 自定义比较函数，用于生成最小堆
struct compare {
	bool operator()(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
		return a.second > b.second;
	}
};

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
	//vector<int> cur_pos (nums1.size(), 0);
	priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, compare> min_heap;
	for (int i = 0; i < nums1.size(); ++ i) {
		pair<int,int> pp (i, 0);
		int sum = nums1[i] + nums2[0];
		min_heap.push(pair<pair<int, int>, int>(pp, sum));
	}
	
	vector<vector<int>> ret;
	for (int i = 0; i < k; ++ i) {
		auto t = min_heap.top().first;
		vector<int> p {nums1[t.first], nums2[t.second]};
		ret.push_back(p);
		min_heap.pop();
		if (t.second < nums2.size() - 1) {
			pair<int,int> pp (t.first, t.second+1);
			int sum = nums1[pp.first] + nums2[pp.second];
			min_heap.push(pair<pair<int, int>, int>(pp, sum));
		}
	}
	return ret;
}

void test_373() {
	vector<int> nums1{1, 7, 11};
	vector<int> nums2{2, 4, 6};
	auto result = kSmallestPairs(nums1, nums2, 3);
	for (auto i : result) {
		std::cout << "[" << i[0] << "," << i[1] << "], ";
	}
	std::cout << std::endl;
}
