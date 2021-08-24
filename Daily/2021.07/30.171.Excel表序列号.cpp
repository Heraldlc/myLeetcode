// 171.Excel表序列号

// 26进制
// A-Z的映射可以借助ASCII值，`字母的值=columnTitle[i] - 'A' +1`

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        int res = 0;
        int mul = 0;
        for(int i= n-1; i>=0; i--)
        {
            int num = columnTitle[i] - 'A' + 1;
            res += num * pow(26, mul);
            mul++;
        }
        return res;
    }
};