#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _2013_detect_squares
{
public:
    _2013_detect_squares() {

    }

    void add(vector<int> point) {

    }

    int count(vector<int> point) {

    }

	void do_test(_2013_detect_squares* sol) {

        // Explanation
        // DetectSquares detectSquares = new DetectSquares();
        sol->add({3, 10});
        sol->add({11, 2});
        sol->add({3, 2});
        
        int ret1 = sol->count({11, 10}); // return 1. You can choose:
                                         //   - The first, second, and third points
        cout << ret1 << endl;
        
        int ret2 = sol->count({14, 8});  // return 0. The query point cannot form a square 
                                         //           with any points in the data structure.
        cout << ret2 << endl;
        
        sol->add({11, 2});               // Adding duplicate points is allowed.
        
        int ret3 = sol->count({11, 10}); // return 2. You can choose:
                                         //   - The first, second, and third points
                                         //   - The first, third, and fourth points
        cout << ret3 << endl;
	}
};
