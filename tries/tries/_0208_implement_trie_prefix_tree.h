#pragma once

#include <iostream>
#include <string>

using namespace std;


class _0208_implement_trie_prefix_tree
{
public:
    _0208_implement_trie_prefix_tree() {

    }

    void insert(string word) {

    }

    bool search(string word) {

    }

    bool startsWith(string prefix) {

    }

	void do_test(_0208_implement_trie_prefix_tree* sol)
	{
        sol->insert("apple");
        bool ret1 = sol->search("apple");
        cout << ret1 << endl; // should be true
        bool ret2 = sol->search("app");
        cout << ret2 << endl; // should be false
        bool ret3 = sol->startsWith("app");
        cout << ret3 << endl; // should be true
        sol->insert("app");
        bool ret4 = sol->search("app"); // should be true
        cout << ret4 << endl; // should be true
	}
};


