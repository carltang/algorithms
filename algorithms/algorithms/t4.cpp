//
//  t4.cpp
//  algorithms
//
//  Created by carltang on 2024/4/29.
//

#include "t4.hpp"
#include <vector>
#include <iostream>
using namespace std;

double median(vector<int>& nums, int l, int r) {
	 int n = r - l + 1;
	 if (n % 2 == 0) {
		 return (nums[l + n/2] + nums[l + n/2 - 1]) / 2.0;
	 } else {
		 return nums[l + n/2];
	 }
 }

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	 int n_1 = nums1.size();
	 int n_2 = nums2.size();
	 if (n_1 == 0) {
		 return median(nums2, 0, n_2 - 1);
	 }
	 if (n_2 == 0) {
		 return median(nums1, 0, n_1 - 1);
	 }

	 //makes sure n_1 >= n_2
	 if (n_2 > n_1) {
		 return findMedianSortedArrays(nums2, nums1);
	 }

	 int l1 = 0;
	 int l2 = 0;
	 int r1 = n_1 - 1;
	 int r2 = n_2 - 1;
	 if (n_1 - n_2 > 2) {
		 int delta = (r1 - l1 - r2 + l2 - 1) / 2;
		 l1 += delta;
		 r1 -= delta;
	 }

	 while(r2 > l2 + 1) {
		 int delta = (r2 - l2) / 2;
		 double m1 = median(nums1, l1, r1);
		 double m2 = median(nums2, l2, r2);
		 if (m1 == m2) {
			 return m1;
		 } else if (m1 > m2) {
			 r1 -= delta;
			 l2 += delta;
		 } else {
			 l1 += delta;
			 r2 -= delta;
		 }
	 }

	 int count = 0;
	 int cur_value, last_value;
	 int total = r2 + r1 - l1 - l2 + 2;
	 bool odd = (total % 2 == 1);
	 int stop = (total + 2) / 2;
	 while (count < stop) {
		 last_value = cur_value;
		 if (l1 > r1) {
			 cur_value = nums2[l2];
			 l2 ++;
		 } else if (l2 > r2) {
			 cur_value = nums1[l1];
			 l1 ++;
		 } else if (nums1[l1] < nums2[l2]) {
			 cur_value = nums1[l1];
			 l1 ++;
		 } else {
			 cur_value = nums2[l2];
			 l2 ++;
		 }
		 count ++;
	 }
	 if (odd) {
		 return cur_value;
	 } else {
		 return (last_value + cur_value) / 2.0;
	 }
}

void test_4() {
	vector<int> nums1 = {1, 2};
	vector<int> nums2 = {-1, 3};
	cout << findMedianSortedArrays(nums1, nums2) << endl;
}
