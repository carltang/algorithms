//
//  201.cpp
//  algorithms
//
//  Created by carltang on 2024/4/22.
//

#include "t201.hpp"
#include <cmath>
#include <iostream>

int rangeBitwiseAnd(int left, int right) {
	if (left == right) return left;
	int zero_string_len = int(log2(right - left)) + 1;
	int ret = left & right;
	ret &= int(exp2(31) - exp2(zero_string_len));
	return ret;
}

void test_201() {
	std::cout << rangeBitwiseAnd(5, 7) << std::endl;
	std::cout << rangeBitwiseAnd(0, int(exp2(31)-1)) << std::endl;
}
