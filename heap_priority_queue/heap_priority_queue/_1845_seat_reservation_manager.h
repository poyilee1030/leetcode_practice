#pragma once

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class SeatManager {
    // Min heap to store all unreserved seats.
    priority_queue<int, vector<int>, greater<int>> availableSeats;

public:
    SeatManager(int n) {
        // Initially all seats are unreserved.
        for (int seatNumber = 1; seatNumber <= n; ++seatNumber) {
            availableSeats.push(seatNumber);
        }
    }

    int reserve() {
        // Get the smallest-numbered unreserved seat from the min heap.
        int seatNumber = availableSeats.top();
        availableSeats.pop();
        return seatNumber;
    }

    void unreserve(int seatNumber) {
        // Push the unreserved seat in the min heap.
        availableSeats.push(seatNumber);
    }
};


class _1845_seat_reservation_manager
{
public:
	void do_test(_1845_seat_reservation_manager* sol) {
        /*
        Input
            ["SeatManager", "reserve", "reserve", "unreserve", "reserve", "reserve", "reserve", "reserve", "unreserve"]
            [[5], [], [], [2], [], [], [], [], [5]]
        Output
            [null, 1, 2, null, 2, 3, 4, 5, null]
        */
        
        SeatManager seatManager = SeatManager(5); // Initializes a SeatManager with 5 seats.
        cout << "[null, ";

        int ret1 = seatManager.reserve();    // All seats are available, so return the lowest numbered seat, which is 1.
        cout << ret1 << ", ";
        
        int ret2 = seatManager.reserve();    // The available seats are [2,3,4,5], so return the lowest of them, which is 2.
        cout << ret2 << ", ";
        
        seatManager.unreserve(2); // Unreserve seat 2, so now the available seats are [2,3,4,5].
        cout << "null, ";

        int ret3 = seatManager.reserve();    // The available seats are [2,3,4,5], so return the lowest of them, which is 2.
        cout << ret3 << ", ";
        
        int ret4 = seatManager.reserve();    // The available seats are [3,4,5], so return the lowest of them, which is 3.
        cout << ret4 << ", ";
        
        int ret5 = seatManager.reserve();    // The available seats are [4,5], so return the lowest of them, which is 4.
        cout << ret5 << ", ";
        
        int ret6 = seatManager.reserve();    // The only available seat is seat 5, so return 5.
        cout << ret6 << ", ";
        
        seatManager.unreserve(5); // Unreserve seat 5, so now the available seats are [5].
        cout << "null]";
	}
};
