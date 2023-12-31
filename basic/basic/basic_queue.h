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

	cout << "q size = " << q.size() << endl;

	q.pop(); // removes the front element, 0
	assert(q.size() == 3);

	cout << "q.front() = " << q.front() << endl;
	// queue 只能訪問最前面的一個元素
	// 如果需要訪問任意位置元素，可使用 dequeue


	cout << "q: ";
	while (!q.empty()) {
		cout << q.front() << ' ';
		q.pop();
	}
	cout << endl;

	assert(q.size() == 0);
}

