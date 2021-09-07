// 贪心写法，没有特别弄懂

class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0, d = 0;
        for(char ch : s){
            if(ch == 'R') d++;
            else d--;
            if(d == 0) res++;
        }
        return res;
    }
};