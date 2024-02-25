#pragma once


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

void basic_union_find()
{
    int n = 10;
    
    Father.resize(n);
    for (int i = 0; i < n; i++)
        Father[i] = i;

    Union(3, 7);
    cout << "Find father of 7 = " << FindFather(7) << endl;
}
