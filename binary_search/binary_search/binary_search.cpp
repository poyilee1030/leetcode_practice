// binary_search.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "_0033_search_in_rotated_sorted_array.h"
#include "_0074_search_a_2d_matrix.h"
#include "_0153_find_minimum_in_rotated_sorted_array.h"
#include "_0704_binary_search.h"
#include "_0875_koko_eating_bananas.h"
#include "_0981_time_based_key_value_store.h"


int main()
{
    //_0033_search_in_rotated_sorted_array sol;
    //_0074_search_a_2d_matrix sol;
    //_0153_find_minimum_in_rotated_sorted_array sol;
    //_0704_binary_search sol;
    //_0875_koko_eating_bananas sol;
    _0981_time_based_key_value_store sol;
    
    sol.do_test(&sol);
}

int binary_search_template1(vector<int> nums)
{
    // �p�G�D�ئ��h�ӥi���, �ӧڭ̭n��̤j���i��ѩγ̤p���i���
    // ���Φ��ҪO�|���Ħb�̨θ�
    int left = 1;
    int right = nums.size();
    while (left < right) {
        int x = right - (right - left) / 2;
        int count = 0;
        for (auto a : nums)
            if (a >= x) count++;

        if (count >= x)
            left = x;
        else
            right = x - 1;
    }
    int count = 0;
    for (auto a : nums)
        if (a >= left) count++;
    if (count == left)
        return left;
    else
        return -1;
}

int binary_search_template2(vector<int> nums)
{
    // �x��������ĳ���g�k, ���ѥh youtube �ݤU�C�D��
    // 1608. Special Array With X Elements Greater Than or Equal X
    // ���D�ئ��Ѯɥ��w�u���@�ӸѮɴN�i�H�ΥH�U�g�k
    int left = 1;
    int right = nums.size();
    while (left <= right) {
        int x = right - (right - left) / 2;
        int count = 0;
        for (auto a : nums)
            if (a >= x) count++;

        if (count == x)
            return x;
        else if (count > x)
            left = x + 1;
        else
            right = x - 1;
    }
    return -1;
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
