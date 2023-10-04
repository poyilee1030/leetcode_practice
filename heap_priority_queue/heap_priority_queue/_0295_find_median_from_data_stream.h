#pragma once

#include <iostream>
#include <vector>

using namespace std;


class MedianFinder {

public:
    MedianFinder() {

    }

    void addNum(int num) {
        if (lower.empty()) {
            lower.push(num);
            return;
        }

        if (lower.size() > higher.size()) {
            if (lower.top() > num) {
                higher.push(lower.top());
                lower.pop();
                lower.push(num);
            }
            else {
                higher.push(num);
            }
        }
        else {
            if (num > higher.top()) {
                lower.push(higher.top());
                higher.pop();
                higher.push(num);
            }
            else {
                lower.push(num);
            }
        }
    }

    double findMedian() {
        double result = 0.0;

        if (lower.size() == higher.size()) {
            result = lower.top() + (higher.top() - lower.top()) / 2.0;
        }
        else {
            if (lower.size() > higher.size()) {
                result = lower.top();
            }
            else {
                result = higher.top();
            }
        }

        return result;
    }
private:
    priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<int>> higher;
};


class _0295_find_median_from_data_stream
{
public:
	void do_test(_0295_find_median_from_data_stream* sol)
	{
        MedianFinder medianFinder;
        
        // arr = [1]
        medianFinder.addNum(1);
        
        // arr = [1, 2]
        medianFinder.addNum(2);

        // return 1.5 (i.e., (1 + 2) / 2)
        double res1 = medianFinder.findMedian();
        cout << res1 << endl;
        
        // arr[1, 2, 3]
        medianFinder.addNum(3);

        // return 2.0
        double res2 = medianFinder.findMedian();
        cout << res2 << endl;
	}
};
