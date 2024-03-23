// binary_search.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "_0033_search_in_rotated_sorted_array.h"
#include "_0074_search_a_2d_matrix.h"
#include "_0153_find_minimum_in_rotated_sorted_array.h"
#include "_0704_binary_search.h"
#include "_0875_koko_eating_bananas.h"
//#include "_0981_time_based_key_value_store.h"


int binary_search_template1(vector<int>& nums, int target)
{
    // �n�� nums �̲Ĥ@�Ӥj�󵥩� target ����m
    // ���Φ��ҪO�̫�|���Ħb�̨θ� left == right
    int left = 0;
    int right = nums.size()-1;
    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    cout << "left = " << left << ", nums[left] = " << nums[left] << endl;
    return left;
}

int binary_search_template2(vector<int>& nums, int target)
{
    // �n�� nums �̳̫�@�Ӥp�󵥩� target ����m
    // ���Φ��ҪO�̫�|���Ħb�̨θ� left == right
    int left = 0;
    int right = nums.size()-1;
    while (left < right) {
        int mid = right - (right - left) / 2;

        if (nums[mid] <= target)
            left = mid;
        else
            right = mid - 1;
    }
    cout << "left = " << left << ", nums[left] = " << nums[left] << endl;
    return left;
}

int binary_search_template3(vector<int>& nums, int target)
{
    // �x��������ĳ���g�k, ���ѥh youtube �ݤU�C�D��
    // 1608. Special Array With X Elements Greater Than or Equal X
    // ���D�ئ��Ѯɥ��w�u���@�ӸѮɴN�i�H�ΥH�U�g�k
    int left = 0;
    int right = nums.size()-1;
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
    //cout << "left = " << left << ", nums[left] = " << nums[left] << endl;
    //cout << "right = " << right << ", nums[right] = " << nums[right] << endl;
    return -1;
}


int main()
{
    vector<int> q = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 20, 21 };
    // vector<int> q = { 20, 21 };
    // vector<int> q = { 0, 1, 2, 3, 4, 5 };
    // ���]�{�b�ؼЬO���Ĥ@�Ӥj�󵥩�ؼ�(10)����m�A�������ӬO idx = 9, q[9] = 20
    int target = 19;
    int ret = binary_search_template1(q, target);

    // ���]�{�b�ؼЬO���̫�@�Ӥp�󵥩�ؼЪ���m�A�������ӬO idx = 8, q[8] = 8
    ret = binary_search_template2(q, target);

    // �p�G q �̭���n�� target �|��^�� idx�A�Y�L���h return -1;
    ret = binary_search_template3(q, target);
    
    cout << "#####################################" << endl;
    
    //_0033_search_in_rotated_sorted_array sol;
    //_0074_search_a_2d_matrix sol;
    //_0153_find_minimum_in_rotated_sorted_array sol;
    //_0704_binary_search sol;
    _0875_koko_eating_bananas sol;
    //_0981_time_based_key_value_store sol;
    
    sol.do_test(&sol);
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
