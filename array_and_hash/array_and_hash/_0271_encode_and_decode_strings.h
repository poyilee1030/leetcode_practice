#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
    Design algorithm to encode/decode: list of strings <-> string

    Encode/decode w/ non-ASCII delimiter: {len of str, "#", str}

    Time: O(n)
    Space: O(1)
*/

class _0271_encode_and_decode_strings
{
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string result = "";

        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            result += to_string(str.size()) + "#" + str;
        }

        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;

        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            string str = s.substr(j + 1, length);
            result.push_back(str);
            i = j + 1 + length;
        }

        return result;
    }

	void do_test(_0271_encode_and_decode_strings* sol)
	{
        /*
        vector<string> dummy_input1 = { "Hello", "World" };
        string encoded_msg = sol->encode(dummy_input1);
        vector<string> decoded_msg = sol->decode(encoded_msg);
        print_result(decoded_msg);
        */
        /*
        Explanation :
        Machine 1 :
        Codec encoder = new Codec();
        String msg = encoder.encode(strs);
                    Machine 1 ---> msg ---> Machine 2
        Machine 2:
        Codec decoder = new Codec();
        String[] strs = decoder.decode(msg);
        */
        /*
        vector<string> dummy_input2 = { "", ""};
        string encoded_msg2 = sol->encode(dummy_input2);
        vector<string> decoded_msg2 = sol->decode(encoded_msg2);
        print_result(decoded_msg2);
        */
        vector<string> dummy_input3 = { "*tg,,~{A^", "qP_T,xL_", "C2-1#67%=" };
        string encoded_msg3 = sol->encode(dummy_input3);
        vector<string> decoded_msg3 = sol->decode(encoded_msg3);
        print_result(decoded_msg3);
	}

    void print_result(vector<string> res)
    {
        cout << "[";
        for (int i = 0; i < res.size(); ++i)
        {
            cout << res[i] << ",";
        }
        cout << "]" << endl;
    }
};