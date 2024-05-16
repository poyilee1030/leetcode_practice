#pragma once

#include <iostream>
#include <vector>

using namespace std;

class _0000_template_testing
{
public:
    int binary_search_template1(vector<int>& nums, int target)
    {
        // 要找 nums 裡第一個大於等於 target 的位置
        // 那用此模板最後會收斂在最佳解 left == right
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        cout << "left = " << left << ", right = " << right << ", nums[left] = " << nums[left] << endl;
        return left;
    }

    int binary_search_template2(vector<int>& nums, int target)
    {
        // 要找 nums 裡最後一個小於等於 target 的位置
        // 那用此模板最後會收斂在最佳解 left == right
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = right - (right - left) / 2;

            if (nums[mid] <= target)
                left = mid;
            else
                right = mid - 1;
        }
        cout << "left = " << left << ", right = " << right << ", nums[left] = " << nums[left] << endl;
        return left;
    }

    int binary_search_template3(vector<int>& nums, int target)
    {
        // 官神較不建議此寫法, 講解去 youtube 看下列題號
        // 1608. Special Array With X Elements Greater Than or Equal X
        // 當題目有解時必定只有一個解時就可以用以下寫法
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) {
                cout << "mid = " << mid << ", nums[mid] = " << nums[mid] << endl;
                return mid;
            }
            else if (target > mid)
                left = mid + 1;
            else
                right = mid - 1;
        }
        // left 會跑出最後一個 index, nums[left] will crash
        cout << "left = " << left << ", right = " << right << endl;
        //cout << "left = " << left << ", nums[left] = " << nums[left] << endl;
        //cout << "right = " << right << ", nums[right] = " << nums[right] << endl;
        return -1;
    }


	void do_test(_0000_template_testing* sol)
	{
		vector<int> nums;
        int target;
		int ret;

		nums = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 20, 21 };
        target = 19;

        // 假設現在目標是找到第一個大於等於目標(10)的位置，答案應該是 idx = 9, q[9] = 20
		ret = sol->binary_search_template1(nums, target);
		cout << "ret = " << ret << endl;


        // 假設現在目標是找到最後一個小於等於目標的位置，答案應該是 idx = 8, q[8] = 8
        ret = binary_search_template2(nums, target);
        cout << "ret = " << ret << endl;


        // 如果 nums 裡面剛好有 target 會返回其 idx，若無找到則 return -1;
        ret = binary_search_template3(nums, target);
        cout << "ret = " << ret << endl;
	}
};
