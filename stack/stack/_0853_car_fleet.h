#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class _0853_car_fleet
{
public:
	int carFleet(int target, vector<int>& position, vector<int>& speed) {
		int n = position.size();

		vector<pair<int, double>> cars;
		for (int i = 0; i < n; i++) {
			double time = (double)(target - position[i]) / speed[i];
			cars.push_back({ position[i], time });
		}
		sort(cars.begin(), cars.end());

		double maxTime = 0.0;
		int result = 0;

		for (int i = n - 1; i >= 0; i--) {
			double time = cars[i].second;
			if (time > maxTime) {
				maxTime = time;
				result++;
			}
		}

		return result;
	}

	void do_test(_0853_car_fleet* sol)
	{
		int target1 = 12;
		vector<int>	position1 = { 10, 8, 0, 5, 3 };
		vector<int> speed1 = { 2, 4, 1, 1, 3 };
		int ret1 = carFleet(target1, position1, speed1);
		cout << ret1 << endl;
		//Output : 3
		
		int target2 = 10;
		vector<int> position2 = { 3 };
		vector<int> speed2 = { 3 };
		int ret2 = carFleet(target2, position2, speed2);
		cout << ret2 << endl;
		//Output : 1
		
		int target3 = 100;
		vector<int> position3 = { 0, 2, 4 };
		vector<int> speed3 = { 4, 2, 1 };
		int ret3 = carFleet(target3, position3, speed3);
		cout << ret3 << endl;
		//Output : 1
	}
};



