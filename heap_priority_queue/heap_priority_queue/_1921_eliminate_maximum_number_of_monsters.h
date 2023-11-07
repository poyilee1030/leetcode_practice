#pragma once

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class _1921_eliminate_maximum_number_of_monsters
{
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        priority_queue<float, vector<float>, greater<float>> heap;

        for (int i = 0; i < dist.size(); i++) {
            heap.push((float)dist[i] / speed[i]);
        }

        int ans = 0;
        while (!heap.empty()) {
            if (heap.top() <= ans) {
                break;
            }

            ans++;
            heap.pop();
        }

        return ans;
    }

	void do_test(_1921_eliminate_maximum_number_of_monsters* sol) {
        vector<int> dist1 = { 1, 3, 4 };
        vector<int> speed1 = { 1, 1, 1 };
        int ret1 = sol->eliminateMaximum(dist1, speed1);
        cout << ret1 << endl;
        /*
        Output : 3
        Explanation :
        In the beginning, the distances of the monsters are[1, 3, 4].You eliminate the first monster.
        After a minute, the distances of the monsters are[X, 2, 3].You eliminate the second monster.
        After a minute, the distances of the monsters are[X, X, 2].You eliminate the thrid monster.
        All 3 monsters can be eliminated.
        */
        
        vector<int> dist2 = { 1, 1, 2, 3 };
        vector<int> speed2 = { 1, 1, 1, 1 };
        int ret2 = sol->eliminateMaximum(dist2, speed2);
        cout << ret2 << endl;
        /*
        Output : 1
        Explanation :
        In the beginning, the distances of the monsters are[1, 1, 2, 3].You eliminate the first monster.
        After a minute, the distances of the monsters are[X, 0, 1, 2], so you lose.
        You can only eliminate 1 monster.
        */
        
        vector<int> dist3 = { 3, 2, 4 };
        vector<int> speed3 = { 5, 3, 2 };
        int ret3 = sol->eliminateMaximum(dist3, speed3);
        cout << ret3 << endl;
        /*
        Output : 1
        Explanation :
        In the beginning, the distances of the monsters are[3, 2, 4].You eliminate the first monster.
        After a minute, the distances of the monsters are[X, 0, 2], so you lose.
        You can only eliminate 1 monster.
        */
	}
};
