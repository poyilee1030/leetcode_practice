#pragma once


class _0342_power_of_four
{
public:
    bool isPowerOfFour(int n) {
        if (n < 1)
            return false;

		/* 如何判斷一個數是否為 4 的次方數?
        num & (num - 1) 可以用来判斷一個數是否為2的次方數，
        更進一步說，就是二進制表示下，只有最高位是1，
        但是2的次方數，不一定是4的次方數，比如8，
        所以我們還要其他的限定條件，我們仔细觀察可以發現，
        4的次方數的最高位的1都是在奇數位，
        所以我們只需與 (0x55555555) 做 bitwise &，
        如果得到的數還是其本身，則可以肯定其為4的次方數
        */

        bool power_of_two = n > 0 && !(n & (n - 1));
        bool bit_on_odd_position = (n & 0x55555555) == n;

        return (power_of_two && bit_on_odd_position);
    }
    /* log method -> can apply on any number
    bool isPowerOfFour(int n) {
        if (n < 1)
            return false;

        double r = (log10(n) / log10(4));
        int fr = floor(r);
        return fr == r;
    }
    */

    /* Naive -> can apply on any number
    bool isPowerOfFour(int n) {
        if (n < 1)
            return false;

        while (n % 4 == 0) {
            n /= 4;
        }

        return (n == 1) ? true : false;
    }
    */
    

	void do_test(_0342_power_of_four* sol) {
        int ret1 = sol->isPowerOfFour(16);
        cout << ret1 << endl;
        // Output : true
        
        int ret2 = sol->isPowerOfFour(5);
        cout << ret2 << endl;
        // Output : false
        
        int ret3 = sol->isPowerOfFour(1);
        cout << ret3 << endl;
        // Output : true
	}
};
