#pragma once

#include <iostream>
#include <vector>

using namespace std;

class _0000_template_testing
{
public:
    int binary_search_template1(vector<int>& nums, int target)
    {
        // �n�� nums �̲Ĥ@�Ӥj�󵥩� target ����m
        // ���Φ��ҪO�̫�|���Ħb�̨θ� left == right
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
        // �n�� nums �̳̫�@�Ӥp�󵥩� target ����m
        // ���Φ��ҪO�̫�|���Ħb�̨θ� left == right
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
        // �x��������ĳ���g�k, ���ѥh youtube �ݤU�C�D��
        // 1608. Special Array With X Elements Greater Than or Equal X
        // ���D�ئ��Ѯɥ��w�u���@�ӸѮɴN�i�H�ΥH�U�g�k
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
        // left �|�]�X�̫�@�� index, nums[left] will crash
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

        // ���]�{�b�ؼЬO���Ĥ@�Ӥj�󵥩�ؼ�(10)����m�A�������ӬO idx = 9, q[9] = 20
		ret = sol->binary_search_template1(nums, target);
		cout << "ret = " << ret << endl;


        // ���]�{�b�ؼЬO���̫�@�Ӥp�󵥩�ؼЪ���m�A�������ӬO idx = 8, q[8] = 8
        ret = binary_search_template2(nums, target);
        cout << "ret = " << ret << endl;


        // �p�G nums �̭���n�� target �|��^�� idx�A�Y�L���h return -1;
        ret = binary_search_template3(nums, target);
        cout << "ret = " << ret << endl;
	}
};
