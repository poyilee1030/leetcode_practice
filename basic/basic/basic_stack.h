#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>

using namespace std;


void print_stack(stack<int> st) {
    cout << "[";
    while (!st.empty()) {
        cout << st.top() << ", ";
        st.pop();
    }
    cout << "]" << endl;
}


void basic_stack() {

	stack<int> st({1});
	
    cout << "stack top = " << st.top() << endl;
    
    st.push(2);

    cout << "stack top = " << st.top() << endl;
}
