#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;


class _1814_count_nice_pairs_in_an_array
{
public:
    int countNicePairs(vector<int>& nums) {
        vector<int> arr;
        for (int i = 0; i < nums.size(); i++) {
            arr.push_back(nums[i] - rev(nums[i]));
        }

        unordered_map<int, int> dic;
        int ans = 0;
        int MOD = 1e9 + 7;
        for (int num : arr) {
            ans = (ans + dic[num]) % MOD;
            dic[num]++;
        }

        return ans;
    }

    int rev(int num) {
        int result = 0;
        while (num > 0) {
            result = result * 10 + num % 10;
            num /= 10;
        }

        return result;
    }

	void do_test(_1814_count_nice_pairs_in_an_array* sol) {
		vector<int> nums1 = { 42, 11, 1, 97 };
		int ret1 = sol->countNicePairs(nums1);
		cout << ret1 << endl;
		/*
		Output : 2
		Explanation : The two pairs are :
		- (0, 3) : 42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121.
		- (1, 2) : 11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12.
		*/

		vector<int> nums2 = { 13, 10, 35, 24, 76 };
		int ret2 = sol->countNicePairs(nums2);
		cout << ret2 << endl;
		// Output : 4
	}
};
