#pragma once
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/*
https://shengyu7697.github.io/std-unordered_set/
C++ std::unordered_set �O�@�����p���e���A
unordered_set �e���̭��������O�ߤ@���A�㦳�����ƪ��S�ʡA�ӥB�O�L�ƧǪ��e���A
unordered_set �e���̭��������ȬO���i�ק�A�� unordered_set �e���i�H���J�ΧR�������C
unordered_set �� set ���P���B�O�Aset �O���¾�(red - black tree)��@�A���¾�㦳�Ƨǥ\��A
unordered_set ����@�覡�q�`�O�������(hash table)��@���A
��ƴ��J�M�d�ߪ��ɶ������׫ܧC�A���`�ƯŧOO(1)�A
�۹諸�N���O���Ӹ��h���O����A�Ŷ������׸����A�L�۰ʱƧǥ\��C
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
