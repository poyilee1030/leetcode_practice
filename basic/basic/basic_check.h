#pragma once

#include <iostream>
#include <string>

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
