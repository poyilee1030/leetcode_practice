#pragma once

#include <iostream>
#include <vector>
#include <map>

using namespace std;


class _0846_hand_of_straights
{
public:
	bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if (n % groupSize != 0) {
            return false;
        }

        // map {card value -> count}
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            m[hand[i]]++;
        }

        while (!m.empty()) {
            int curr = m.begin()->first;
            for (int i = 0; i < groupSize; i++) {
                if (m[curr + i] == 0) {
                    return false;
                }
                m[curr + i]--;
                if (m[curr + i] < 1) {
                    m.erase(curr + i);
                }
            }
        }

        return true;
	}

	void do_test(_0846_hand_of_straights* sol) {
		vector<int> hand1 = { 1, 2, 3, 6, 2, 3, 4, 7, 8 };
		int groupSize1 = 3;
		bool ret1 = sol->isNStraightHand(hand1, groupSize1);
		cout << ret1 << endl;
		// Output : true
		// Explanation : Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]

		vector<int> hand2 = { 1, 2, 3, 4, 5 };
		int groupSize2 = 4;
		bool ret2 = sol->isNStraightHand(hand2, groupSize2);
		cout << ret2 << endl;
		// Output : false
		// Explanation : Alice's hand can not be rearranged into groups of 4.
	}
};
