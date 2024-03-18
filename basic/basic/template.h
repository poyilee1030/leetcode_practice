#pragma once

#include <iostream>
#include <vector>

using namespace std;


// Find all primes <= n.
vector<int>Eratosthenes(int n)
{
    vector<int>q(n + 1, 0);
    vector<int>primes;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (q[i] == 1)
            continue;
        int j = i * 2;
        while (j <= n)
        {
            q[j] = 1;
            j += i;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (q[i] == 0)
            primes.push_back(i);
    }
    return primes;
}


// Union Find
vector<int>Father;
int FindFather(int x)
{
    if (Father[x] != x)
        Father[x] = FindFather(Father[x]);
    return Father[x];
}

void Union(int x, int y)
{
    x = Father[x];
    y = Father[y];
    if (x < y) 
        Father[y] = x;
    else 
        Father[x] = y;
}
// initial Father before use, assign the value to itself
/*
Father.resize(n);
for (int i = 0; i < n; i++)
    Father[i] = i;
*/
