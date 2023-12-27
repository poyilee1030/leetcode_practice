// basic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;


void basic_check() {
    // toupper
    char tmp1 = 'c';
    char res1 = toupper(tmp1);
    cout << "toupper('c') = " << res1 << endl;

    // tolower
    char tmp2 = 'C';
    char res2 = tolower(tmp2);
    cout << "toupper('C') = " << res2 << endl;

    // isalpha
    char tmp3 = '9';
    int res3 = isalpha(tmp3);
    cout << "isalpha('9') = " << res3 << endl;

    char tmp4 = 'a';
    int res4 = isalpha(tmp4);
    cout << "isalpha('a') = " << res4 << endl;

    char tmp5 = 's';
    int res5 = isalpha(tmp5);
    cout << "isalpha('s') = " << res5 << endl;

    char tmp6 = 'S';
    int res6 = isalpha(tmp6);
    cout << "isalpha('S') = " << res6 << endl;

    // isalnum
    char tmp7 = '9';
    int res7 = isalnum(tmp7);
    cout << "isalnum('9') = " << res7 << endl;

    char tmp8 = 'a';
    int res8 = isalnum(tmp8);
    cout << "isalnum('a') = " << res8 << endl;

    char tmp9 = 's';
    int res9 = isalnum(tmp9);
    cout << "isalnum('s') = " << res9 << endl;

    char tmp10 = 'S';
    int res10 = isalnum(tmp10);
    cout << "isalnum('S') = " << res10 << endl;

    // isdigit
    char tmp11 = '9';
    int res11 = isdigit(tmp11);
    cout << "isdigit('9') = " << res11 << endl;

    // islower

    // isupper

    // isblank

    // isspace
}


void basic_vector() {
    // vector
    // declare a vector
    vector<int> a;

    vector<int> b = { 1, 1, 1, 1, 1 };

    vector<int> c(5, 1); //(size, value)
}


void basic_unordered_map() {
    // unordered_map
    unordered_map<char, int> map;
    map['a'] = 1;
    map['b'] = 2;
    map['c'] = 3;
    map['d'] = 4;
    map['e'] = 5;
    map.erase('a');

    iterator<char, int> it;
}


void basic_str() {
    // string
    // string to int
    string ss = "123";
    int aa = stoi(ss);
    // int to string
    int bb = 456;
    string tt = to_string(bb);
}


int main()
{
    basic_check();

    basic_vector();

    basic_unordered_map();

    basic_str();
    
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
