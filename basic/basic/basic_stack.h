#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>

using namespace std;


void print_stack(stack<int> stk) {
    cout << "[";
    while (!stk.empty()) {
        cout << stk.top() << ", ";
        stk.pop();
    }
    cout << "]" << endl;
}

// Print the current pair 
void print_pair(pair<int, int> p)
{
    cout << "("
        << p.first << ", "
        << p.second << ") ";
}

// Print the Stack of Pairs 
void print_stack_pair(stack<pair<int, int>> stkp)
{
    while (!stkp.empty()) {
        print_pair(stkp.top());
        stkp.pop();
    }

    cout << '\n';
}



void basic_stack() {

	stack<int> stk({1});
	
    cout << "stack top = " << stk.top() << endl;
    
    stk.push(2);

    cout << "stack top = " << stk.top() << endl;

    stack<pair<int, int>> stkp;
    stkp.push({ 99, 1 });
    print_pair(stkp.top());
}
