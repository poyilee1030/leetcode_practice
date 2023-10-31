#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class _0763_partition_labels
{
public:
	vector<int> partitionLabels(string s) {
		vector<int> q;
		return q;
	}

	void do_test(_0763_partition_labels* sol) {
		string s1 = "ababcbacadefegdehijhklij";
		vector<int> ret1 = sol->partitionLabels(s1);
		print_res(ret1);
		/*
		Output : [9, 7, 8]
		Explanation :
		The partition is "ababcbaca", "defegde", "hijhklij".
		This is a partition so that each letter appears in at most one part.
		A partition like "ababcbacadefegde", "hijhklij" is incorrect, 
		because it splits s into less parts.
		*/
		

		string s2 = "eccbbbbdec";
		vector<int> ret2 = sol->partitionLabels(s2);
		print_res(ret2);
		// Output : [10]
	}

	void print_res(vector<int>& res) {
		cout << "[";
		for (int i = 0; i < res.size() - 1;i++) {
			cout << res[i];
			if (i < res.size() - 1)
				cout << ",";
		}
		cout << "]" << endl;
	}
};
