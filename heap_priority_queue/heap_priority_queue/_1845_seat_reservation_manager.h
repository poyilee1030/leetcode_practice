#pragma once

#include <iostream>
#include <vector>

using namespace std;


class SeatManager {
public:
    SeatManager(int n) {

    }

    int reserve() {
        return 0;
    }

    void unreserve(int seatNumber) {

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
        int ret1 = seatManager.reserve();    // All seats are available, so return the lowest numbered seat, which is 1.
        cout << ret1 << endl;
        int ret2 = seatManager.reserve();    // The available seats are [2,3,4,5], so return the lowest of them, which is 2.
        cout << ret2 << endl;
        seatManager.unreserve(2); // Unreserve seat 2, so now the available seats are [2,3,4,5].
        int ret3 = seatManager.reserve();    // The available seats are [2,3,4,5], so return the lowest of them, which is 2.
        cout << ret3 << endl;
        int ret4 = seatManager.reserve();    // The available seats are [3,4,5], so return the lowest of them, which is 3.
        cout << ret4 << endl;
        int ret5 = seatManager.reserve();    // The available seats are [4,5], so return the lowest of them, which is 4.
        cout << ret5 << endl;
        int ret6 = seatManager.reserve();    // The only available seat is seat 5, so return 5.
        cout << ret6 << endl;
        seatManager.unreserve(5); // Unreserve seat 5, so now the available seats are [5].
        
	}
};
