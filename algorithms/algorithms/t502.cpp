//
//  t502.cpp
//  algorithms
//
//  Created by carltang on 2024/4/23.
//

#include "t502.hpp"
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

//自定义比较函数，用于vector排序（first）
bool compare_a (const pair<int, int>& a, const pair<int, int>& b) {
	return a.first < b.first;
}

// 自定义比较函数，用于生成最大堆
struct compare_b {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		// 按照 pair 的第2个元素比较
		return a.second < b.second;
	}
};

int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
	int n = profits.size();
	vector<pair<int, int>> pc;
	for (int i = 0; i < n ; ++ i) {
		pc.push_back({capital[i], profits[i]});
	}
	//按capital从小到大
	sort(pc.begin(), pc.end(), compare_a);
	int cur_index = 0;
	int cur_proj_num = 0;
	int cur_capital = w;
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare_b> max_heap;

	while (cur_proj_num < k) {
		cur_proj_num ++;
		while (cur_index < n && pc[cur_index].first <= cur_capital) {
			max_heap.push(pc[cur_index]);
			cur_index ++;
		}
		if (!max_heap.empty()) {
			cur_capital += max_heap.top().second;
			max_heap.pop();
		}
	}
	return cur_capital;
}

void test_502() {
	vector<int> p = {1, 2, 3};
	vector<int> c = {0, 1, 1};
	cout << findMaximizedCapital(2, 0, p, c) << endl;
}
