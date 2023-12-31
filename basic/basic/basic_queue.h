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
	// queue �u��X�ݳ̫e�����@�Ӥ���
	// �p�G�ݭn�X�ݥ��N��m�����A�i�ϥ� dequeue


	cout << "q: ";
	while (!q.empty()) {
		cout << q.front() << ' ';
		q.pop();
	}
	cout << endl;

	assert(q.size() == 0);
}

