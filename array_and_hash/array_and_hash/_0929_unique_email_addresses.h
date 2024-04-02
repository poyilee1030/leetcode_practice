#pragma once

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;


class _0929_unique_email_addresses
{
public:
	int numUniqueEmails(vector<string>& emails) {
		unordered_set<string> set;
		for (auto email : emails) {
			bool mouse_showed = false;
			bool plus_showed = false;
			string new_email = "";
			for (int i = 0; i < email.size(); i++) {
				if (email[i] == '@')
					mouse_showed = true;
				else if (email[i] == '+')
					plus_showed = true;

				if (!mouse_showed && email[i] == '.')
					continue;
				if (!mouse_showed && plus_showed)
					continue;
				
				new_email += email[i];
			}
			set.insert(new_email);
		}
		return set.size();
	}

	void do_test(_0929_unique_email_addresses* sol) {
		vector<string> emails;
		int ret;
		
		emails = { "test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com", "testemail+david@lee.tcode.com" };
		ret = sol->numUniqueEmails(emails);
		cout << ret << endl;
		// Output : 2
		// Explanation : "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails.

		emails = { "a@leetcode.com", "b@leetcode.com", "c@leetcode.com" };
		ret = sol->numUniqueEmails(emails);
		cout << ret << endl;
		// Output : 3
	}
};
