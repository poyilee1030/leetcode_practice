#pragma once

#include <iostream>
#include <vector>

using namespace std;

class _0167_two_sum_ii_input_array_is_sorted
{
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        if (numbers.size() == 2)
        {
            return { 1, 2 };
        }

        int i = 0;
        int j = numbers.size() - 1;
        while (i < j)
        {
            int diff = target - numbers[j];
            if (numbers[i] < diff)
            {
                ++i;
            }
            else if (numbers[i] > diff)
            {
                --j;
            }
            else
            {
                //numbers[i] == diff
                break;
            }
        }
        return { i+1, j+1 };
    }

    void do_test(_0167_two_sum_ii_input_array_is_sorted *sol)
    {
        vector<int> numbers1 = { 2, 7, 11, 15 };
        int target1 = 9;
        vector<int> ret1 = sol->twoSum(numbers1, target1);
        print_result(ret1);
        //Output : [1, 2]
        //Explanation : The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return[1, 2].
        
        vector<int> numbers2 = { 2, 3, 4 };
        int target2 = 6;
        vector<int> ret2 = sol->twoSum(numbers2, target2);
        print_result(ret2);
        //Output : [1, 3]
        //Explanation : The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return[1, 3].
        

        vector<int> numbers3 = { -1, 0 }; 
        int target3 = -1;
        vector<int> ret3 = sol->twoSum(numbers3, target3);
        print_result(ret3);
        //Output : [1, 2]
        //Explanation : The sum of - 1 and 0 is - 1. Therefore index1 = 1, index2 = 2. We return[1, 2].

    }

    void print_result(vector<int> result)
    {
        cout << "[";
        for (int i = 0; i < result.size(); ++i)
        {
            cout << result[i] << ",";
        }
        cout << "]\n";
    }
};



