// 剑指offer原题
// 没有理解！

class Solution {
public:
    int countDigitOne(int n) {
        long digit = 1; // digit 需为 long 型，因为比如 n 是 INT_MAX，digit 会在最后一次循环越界
        int high = n / 10, cur = n % 10, low = 0;
        int res = 0;

        while (high != 0 || cur != 0) {
            if (cur == 0) {
                res += high * digit;
            }
            else if (cur == 1) {
                res += high * digit + low + 1;
            }
            else {
                res += (high + 1) * digit;
            }

            low += cur * digit;
            cur = high % 10;
            high /= 10;
            digit *= 10; 
        }

        return res;
    }
};