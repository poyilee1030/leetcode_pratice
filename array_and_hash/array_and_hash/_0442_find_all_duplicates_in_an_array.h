#pragma once

#include <iostream>
#include <unordered_map>
#include <string>
#include "utils.h"

using namespace std;


class _0442_find_all_duplicates_in_an_array
{
public:
	/* 
	// 因為題目說這些數字只會出現一次或兩次，所以可以將第一次遇到的數字*(-1)
	// 下次看到負數時就知道這個數字出現過了
	vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        for (auto num : nums) {
            if (nums[abs(num) - 1] < 0) {  // seen before
                ans.push_back(abs(num));
            }
            nums[abs(num) - 1] *= -1;
        }

        return ans;
    }
	*/
	vector<int> findDuplicates(vector<int>& nums) {
		int n = nums.size();
		nums.insert(nums.begin(), 0);

		for (int i = 1; i <= n; i++) {
			while (nums[i] != i && nums[i] <= n && nums[i] != nums[nums[i]]) {
				swap(nums[i], nums[nums[i]]);
			}
		}

		vector<int> ans;
		for (int i = 1; i <= n; i++) {
			if (nums[i] != i)
				ans.push_back(nums[i]);
		}
		return ans;
	}

	void do_test(_0442_find_all_duplicates_in_an_array* sol) {
		vector<int> ret;
		vector<int> nums;

		nums = { 4, 3, 2, 7, 8, 2, 3, 1 };
		ret = sol->findDuplicates(nums);
		print_vector(ret);
		// Output : [2, 3]
		
		nums = { 1, 1, 2 };
		ret = sol->findDuplicates(nums);
		print_vector(ret);
		// Output : [1]
		
		nums = { 1 };
		ret = sol->findDuplicates(nums);
		print_vector(ret);
		// Output : []
	}
};
