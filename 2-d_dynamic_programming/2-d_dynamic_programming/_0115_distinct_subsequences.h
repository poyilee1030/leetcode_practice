#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;



class _0115_distinct_subsequences
{
public:
	int numDistinct(string s, string t) {
		return 0;
	}

	void do_test(_0115_distinct_subsequences* sol) {
		string s1 = "rabbbit";
		string t1 = "rabbit";
		int ret1 = sol->numDistinct(s1, t1);
		cout << ret1 << endl;
		/*
		Output : 3
		Explanation :
		As shown below, there are 3 ways you can generate "rabbit" from s.
		rabbbit
		rabbbit
		rabbbit
		*/
		
		string s2 = "babgbag";
		string t2 = "bag";
		int ret2 = sol->numDistinct(s2, t2);
		cout << ret2 << endl;
		/*
		Output : 5
		Explanation :
		As shown below, there are 5 ways you can generate "bag" from s.
		babgbag
		babgbag
		babgbag
		babgbag
		babgbag
		*/

		
		
	}
};


