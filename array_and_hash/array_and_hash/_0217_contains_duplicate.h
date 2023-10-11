#pragma once
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/*
https://shengyu7697.github.io/std-unordered_set/
C++ std::unordered_set 是一個關聯式容器，
unordered_set 容器裡面的元素是唯一的，具有不重複的特性，而且是無排序的容器，
unordered_set 容器裡面元素的值是不可修改，但 unordered_set 容器可以插入或刪除元素。
unordered_set 跟 set 不同之處是，set 是紅黑樹(red - black tree)實作，紅黑樹具有排序功能，
unordered_set 的實作方式通常是用雜湊表(hash table)實作的，
資料插入和查詢的時間複雜度很低，為常數級別O(1)，
相對的代價是消耗較多的記憶體，空間複雜度較高，無自動排序功能。
*/ 

class _0217_contains_duplicate
{
public:
	bool containsDuplicate(vector<int>& nums)
	{
        unordered_set<int> s;
        for (unsigned int i = 0; i < nums.size(); i++)
        {
            if (s.find(nums[i]) != s.end())
            {
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
	}

    void do_test(_0217_contains_duplicate *sol)
    {
        vector<int> nums1 = { 1, 2, 3, 1 };
        vector<int> nums2 = { 1, 2, 3, 4 };
        vector<int> nums3 = { 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 };
        int ret1 = sol->containsDuplicate(nums1);
        cout << ret1 << endl;
        int ret2 = sol->containsDuplicate(nums2);
        cout << ret2 << endl;
        int ret3 = sol->containsDuplicate(nums3);
        cout << ret3 << endl;
    }
};
