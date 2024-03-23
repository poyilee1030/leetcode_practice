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
    // 要找 nums 裡第一個大於等於 target 的位置
    // 那用此模板最後會收斂在最佳解 left == right
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
    // 要找 nums 裡最後一個小於等於 target 的位置
    // 那用此模板最後會收斂在最佳解 left == right
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
    // 官神較不建議此寫法, 講解去 youtube 看下列題號
    // 1608. Special Array With X Elements Greater Than or Equal X
    // 當題目有解時必定只有一個解時就可以用以下寫法
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
    // left 會跑出最後一個 index, nums[left] will crash
    //cout << "left = " << left << ", nums[left] = " << nums[left] << endl;
    //cout << "right = " << right << ", nums[right] = " << nums[right] << endl;
    return -1;
}


int main()
{
    vector<int> q = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 20, 21 };
    // vector<int> q = { 20, 21 };
    // vector<int> q = { 0, 1, 2, 3, 4, 5 };
    // 假設現在目標是找到第一個大於等於目標(10)的位置，答案應該是 idx = 9, q[9] = 20
    int target = 19;
    int ret = binary_search_template1(q, target);

    // 假設現在目標是找到最後一個小於等於目標的位置，答案應該是 idx = 8, q[8] = 8
    ret = binary_search_template2(q, target);

    // 如果 q 裡面剛好有 target 會返回其 idx，若無找到則 return -1;
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
