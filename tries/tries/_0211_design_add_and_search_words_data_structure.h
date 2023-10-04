#pragma once

#include <iostream>
#include <string>

using namespace std;


class _0211_design_add_and_search_words_data_structure
{
public:
    _0211_design_add_and_search_words_data_structure() {

    }

    void addWord(string word) {

    }

    bool search(string word) {

    }

	void do_test(_0211_design_add_and_search_words_data_structure* sol)
	{
        sol->addWord("bad");
        sol->addWord("dad");
        sol->addWord("mad");
        bool ret1 = sol->search("pad"); // flase
        bool ret2 = sol->search("bad"); // true
        bool ret3 = sol->search(".ad"); // true
        bool ret4 = sol->search("b.."); // true
	}
};


