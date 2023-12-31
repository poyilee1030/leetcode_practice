#pragma once

#include <iostream>
#include <queue>
#include <cassert>

using namespace std;


void basic_queue() {
	
	queue<int> q;
	
	q.push(0); // back pushes 0
	q.push(1); // q = 0 1
	q.push(2); // q = 0 1 2
	q.push(3); // q = 0 1 2 3

	q.pop(); // removes the front element, 0
	assert(q.size() == 3);

	// Print and remove all elements. Note that std::queue does not
	// support begin()/end(), so a range-for-loop cannot be used.
	cout << "q: ";
	for (; !q.empty(); q.pop())
		cout << q.front() << ' ';
	cout << '\n';
	assert(q.size() == 0);
}

