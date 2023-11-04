#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class _1503_last_moment_before_all_ants_fall_out_of_a_plank
{
public:
	int getLastMoment(int n, vector<int>& left, vector<int>& right) {
		int ans = 0;
		for (int num : left) {
			ans = max(ans, num);
		}

		for (int num : right) {
			ans = max(ans, n - num);
		}

		return ans;
	}

	/*
	int getLastMoment(int n, vector<int>& left, vector<int>& right) {
		sort(left.begin(), left.end());
		sort(right.begin(), right.end());

		int t = 0;
		while (left.size() > 0 || right.size() > 0) {
			if (!left.empty() && left[0] == 0)
				left.erase(left.begin());
			for (int i = 0; i < left.size(); i++)
				left[i]--;

			if (!right.empty() && right[right.size() - 1] == n)
				right.pop_back();
			for (int j = 0; j < right.size(); j++)
				right[j]++;

			t++;
		}
		return t - 1;
	}
	*/

	void do_test(_1503_last_moment_before_all_ants_fall_out_of_a_plank* sol) {
		int n1 = 4;
		vector<int> left1 = { 4, 3 };
		vector<int> right1 = { 0, 1 };
		int ret1 = sol->getLastMoment(n1, left1, right1);
		cout << ret1 << endl;
		/*
		Output : 4
		Explanation : In the image above :
		- The ant at index 0 is named A and going to the right.
		- The ant at index 1 is named B and going to the right.
		- The ant at index 3 is named C and going to the left.
		- The ant at index 4 is named D and going to the left.
		The last moment when an ant was on the plank is t = 4 seconds.
		After that, it falls immediately out of the plank. 
		(i.e., We can say that at t = 4.0000000001, there are no ants on the plank).
		*/

		int n2 = 7;
		vector<int> left2 = {};
		vector<int> right2 = { 0, 1, 2, 3, 4, 5, 6, 7 };
		int ret2 = sol->getLastMoment(n2, left2, right2);
		cout << ret2 << endl;
		/*
		Output : 7
		Explanation : All ants are going to the right, 
		the ant at index 0 needs 7 seconds to fall.
		*/
		
		int n3 = 7;
		vector<int> left3 = { 0, 1, 2, 3, 4, 5, 6, 7 };
		vector<int> right3 = {};
		int ret3 = sol->getLastMoment(n3, left3, right3);
		cout << ret3 << endl;
		/*
		Output : 7
		Explanation : All ants are going to the left, 
		the ant at index 7 needs 7 seconds to fall.
		*/
		
		int n4 = 9;
		vector<int> left4 = {5};
		vector<int> right4 = {4};
		int ret4 = sol->getLastMoment(n4, left4, right4);
		cout << ret4 << endl;
		/*
		Output : 5
		*/

		int n5 = 1;
		vector<int> left5 = { 0 };
		vector<int> right5 = { };
		int ret5 = sol->getLastMoment(n5, left5, right5);
		cout << ret5 << endl;
		/*
		Output : 0
		*/
	}
};

