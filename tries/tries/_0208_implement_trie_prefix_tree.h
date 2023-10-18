#pragma once

#include <iostream>
#include <string>
#include "define.h"

using namespace std;

class _0208_implement_trie_prefix_tree
{
    TrieNode* root;
public:
    _0208_implement_trie_prefix_tree() {
        root = new TrieNode();
    }

    void insert(string word) {
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
        int curr = 0;

        for (int i = 0; i < word.size(); i++) {
            curr = word[i] - 'a';
            if (node->children[curr] == NULL) {
                return false;
            }
            node = node->children[curr];
        }

        return node->isWord;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        int curr = 0;

        for (int i = 0; i < prefix.size(); i++) {
            curr = prefix[i] - 'a';
            if (node->children[curr] == NULL) {
                return false;
            }
            node = node->children[curr];
        }

        return true;
    }

	void do_test(_0208_implement_trie_prefix_tree* sol)
	{
        sol->insert("apple");
        
        bool ret1 = sol->search("apple");
        cout << ret1 << endl; 
        // should be true
        
        bool ret2 = sol->search("app");
        cout << ret2 << endl; 
        // should be false
        
        bool ret3 = sol->startsWith("app");
        cout << ret3 << endl; 
        // should be true
        
        sol->insert("app");

        bool ret4 = sol->search("app");
        cout << ret4 << endl; 
        // should be true
	}
};


