#pragma once


class _0097_interleaving_string
{
public:
	bool isInterleave(string s1, string s2, string s3) {
		return false;
	}

	void do_test(_0097_interleaving_string* sol) {
		string as1 = "aabcc";
		string as2 = "dbbca"; 
		string as3 = "aadbbcbcac";
		bool reta = sol->isInterleave(as1, as2, as3);
		cout << reta << endl;
		/*
		Output : true
		Explanation : One way to obtain s3 is :
		Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
		Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
		Since s3 can be obtained by interleaving s1 and s2, we return true.
		*/
		
		string bs1 = "aabcc", bs2 = "dbbca", bs3 = "aadbbbaccc";
		bool retb = sol->isInterleave(bs1, bs2, bs3);
		cout << retb << endl;
		// Output : false
		// Explanation : Notice how it is impossible to interleave s2 with any other string to obtain s3.
		
		string cs1 = "", cs2 = "", cs3 = "";
		bool retc = sol->isInterleave(cs1, cs2, cs3);
		cout << retc << endl;
		// Output : true
	}
};
