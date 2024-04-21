#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;


void basic_string_operate() {
    cout << "-------- string test part 1 ---------" << endl;

    string word = "aAbBcCEFGefg";
    int ans = 0;
    int ret1 = word.find('d');
    int ret2 = word.find('B');
    cout << ret1 << ", " << ret2 << endl;
    cout << word.find('d') << ", " << word.find('B') << endl;
    size_t ret3 = word.find('d');
    cout << ret3 << endl;
    cout << string::npos << endl;
    if (word.find('d') == -1)
        cout << "not found d" << endl;
    
    // �`�N�Astring find ���O��^�@�� size_t (unsigned integer)
    // �ҥH�p�G�O�� >= 0 ������ܬO�|���ߪ�!
    if (word.find('d') >= 0)
        cout << "found d" << endl;
    

    cout << "-------- string test part 2 ---------" << endl;
    // string
    // string to int
    string ss = "123";
    int aa = stoi(ss);
    // int to string
    int bb = 456;
    string tt = to_string(bb);

    string ssss = "123456789";
    //                  �� start idx 
    cout << ssss.substr(2, 3) << endl;
    //                     �� length
    // output = 345
    cout << "-------- string test part 3 ---------" << endl;
    int l = 0;
    int wsize = 3;
    while (l < ssss.size()-wsize+1) {
        string ssss_sub = ssss.substr(l, wsize); // (start_pos, length)
        cout << ssss_sub << endl;
        l++;
    }
    
    // �� length ��������ɭԡA�� for loop �v���|�[�Ĳv�ܮt
    // to init a string with length and char
    int L = 10;
    char C = 'B';
    string tmp1(L, C);
    cout << "tmp1 = " << tmp1 << endl;

    string tmp2;
    tmp2.append(L, C);
    cout << "tmp2 = " << tmp2 << endl;

    //--------------------------------------------------------------------------------------------------------

    // ���� string �ϥ� < operator �N����?
    // https://stackoverflow.com/questions/13829434/using-the-less-than-comparison-operator-for-strings
    /*
    The less-than operator on strings does a lexicographical comparison on the strings.
    This compares strings in the same way that they would be listed in dictionary order, 
    generalized to work for strings with non-letter characters.

    For example:
    "a" < "b"
    "a" < "ab"
    "A" < "a"             (Since A has ASCII value 65; a has a higher ASCII value)
    "cat" < "caterpillar"
    
    For more information, 
    look at the std::lexicographical_compare algorithm, 
    which the less-than operator usually invokes.

    As for -= and *=, neither of these operators are defined on strings. 
    The only "arithmetic" operators defined are + and +=, which perform string concatenation.
    */
}
