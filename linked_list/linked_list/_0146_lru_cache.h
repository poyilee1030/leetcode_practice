#pragma once

#include <iostream>
#include <unordered_map>
#include "define.h"

using namespace std;



class _0146_lru_cache
{
public:
    _0146_lru_cache(int capacity) {
        cap = capacity;

        left = new Node2(0, 0);
        right = new Node2(0, 0);

        left->next = right;
        right->prev = left;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);

            // Free allocated memory for the removed node
            delete cache[key];
        }
        cache[key] = new Node2(key, value);
        insert(cache[key]);

        if (cache.size() > cap) {
            // remove from list & delete LRU from map
            Node2* lru = left->next;
            remove(lru);
            cache.erase(lru->k);

            // Free allocated memory for the removed node
            delete lru;
        }
    }

	void do_test(_0146_lru_cache* sol)
	{
        //LRUCache lRUCache = new LRUCache(2);
        sol->put(1, 1); // cache is {1=1}
        sol->put(2, 2); // cache is {1=1, 2=2}
        int ret1 = sol->get(1);    // return 1
        cout << ret1 << endl;
        sol->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
        int ret2 = sol->get(2);    // returns -1 (not found)
        cout << ret2 << endl;
        sol->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
        int ret3 = sol->get(1);    // return -1 (not found)
        cout << ret3 << endl;
        int ret4 = sol->get(3);    // return 3
        cout << ret4 << endl;
        int ret5 = sol->get(4);    // return 4
        cout << ret5 << endl;
	}

private:
    int cap;
    unordered_map<int, Node2*> cache; // {key -> node}
    Node2* left;
    Node2* right;

    // remove node from list
    void remove(Node2* node) {
        Node2* prev = node->prev;
        Node2* next = node->next;

        prev->next = next;
        next->prev = prev;
    }

    // insert node at right
    void insert(Node2* node) {
        Node2* prev = right->prev;
        Node2* next = right;

        prev->next = node;
        next->prev = node;

        node->prev = prev;
        node->next = next;
    }
};


