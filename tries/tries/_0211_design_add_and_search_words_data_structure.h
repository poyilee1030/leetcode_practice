#pragma once

#include <iostream>
#include <string>
#include "define.h"

using namespace std;


class _0211_design_add_and_search_words_data_structure
{
    TrieNode* root;
public:
    _0211_design_add_and_search_words_data_structure() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;
        int curr = 0;

        for (int i = 0; i < word.size(); i++) {
            curr = word[i] - 'a';
            if (node->children[curr] == NULL) {
                node->children[curr] = new TrieNode();
            }
            node = node->children[curr];
        }

        node->isWord = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        return searchInNode(word, 0, node);
    }

    bool searchInNode(string& word, int i, TrieNode* node) {
        if (node == NULL) {
            return false;
        }
        if (i == word.size()) {
            return node->isWord;
        }
        if (word[i] != '.') {
            return searchInNode(word, i + 1, node->children[word[i] - 'a']);
        }
        for (int j = 0; j < 26; j++) {
            if (searchInNode(word, i + 1, node->children[j])) {
                return true;
            }
        }
        return false;
    }

	void do_test(_0211_design_add_and_search_words_data_structure* sol)
	{
        sol->addWord("bad");
        sol->addWord("dad");
        sol->addWord("mad");
        bool ret1 = sol->search("pad");
        cout << ret1 << endl;
        // flase

        bool ret2 = sol->search("bad");
        cout << ret2 << endl;
        // true

        bool ret3 = sol->search(".ad");
        cout << ret3 << endl;
        // true

        bool ret4 = sol->search("b..");
        cout << ret4 << endl;
        // true

	}
};


