#pragma once



class _0394_decode_string {
public:
    string decodeString(string s) {
        stack<char> stk;
        for (char c : s) {
            if (c == ']') {
                string digit;
                string text;
                while (!stk.empty()) {
                    if (stk.top() == '[') {
                        stk.pop();
                        reverse(text.begin(), text.end());
                        while (!stk.empty() && isdigit(stk.top())) {
                            digit += stk.top();
                            stk.pop();
                        }
                        reverse(digit.begin(), digit.end());
                        int cnt = stoi(digit);
                        string res;
                        for (int i = 0; i < cnt; i++)
                            res += text;
                        for (int i = 0; i < res.size(); i++)
                            stk.push(res[i]);
                        break;
                    }
                    else if (isalpha(stk.top())) {
                        text += stk.top();
                        stk.pop();
                    }
                }
            }
            else {
                stk.push(c);
            }
        }

        string ans;
        while (!stk.empty()) {
            ans += stk.top();

            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

	void do_test(_0394_decode_string* sol) {
        string ret;

        ret = sol->decodeString("3[a]2[bc]");
        cout << ret << endl;
        // Output: "aaabcbc"

        ret = sol->decodeString("3[a2[c]]");
        cout << ret << endl;
        // Output: "accaccacc"

        ret = sol->decodeString("2[abc]3[cd]ef");
        cout << ret << endl;
        // Output: "abcabccdcdcdef"
	}
};
