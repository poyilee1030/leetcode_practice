#pragma once

#include <iostream>
#include <vector>

using namespace std;

/*
    Given array of banana piles, guards are gone for h hours
    Return min int k such that can eat all banans within h
    Ex. piles = [3,6,7,11] h = 8 -> 4 (1@3, 2@6, 2@7, 3@11)

    Binary search, for each k count hours needed, store min

    Time: O(n x log m) -> n = # of piles, m = max # in a pile
    Space: O(1)
*/

class _0875_koko_eating_bananas
{
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int low = 1;
        int high = 0;
        for (int i = 0; i < n; i++) {
            high = max(high, piles[i]);
        }

        int result = high;

        while (low <= high) {
            int k = low + (high - low) / 2;
            long int hours = 0;
            for (int i = 0; i < n; i++) {
                hours += ceil((double)piles[i] / k);
            }
            if (hours <= h) {
                result = min(result, k);
                high = k - 1;
            }
            else {
                low = k + 1;
            }
        }

        return result;
    }
    void do_test(_0875_koko_eating_bananas* sol)
    {
        vector<int> piles1 = { 3, 6, 7, 11 };
        int h1 = 8;
        int ret1 = sol->minEatingSpeed(piles1, h1);
        cout << ret1 << endl;
        //Output : 4
        

        vector<int> piles2 = { 30, 11, 23, 4, 20 };
        int h2 = 5;
        int ret2 = sol->minEatingSpeed(piles2, h2);
        cout << ret2 << endl;
        //Output : 30
        

        vector<int> piles3 = { 30, 11, 23, 4, 20 };
        int h3 = 6;
        int ret3 = sol->minEatingSpeed(piles3, h3);
        cout << ret3 << endl;
        //Output : 23
    }
};

