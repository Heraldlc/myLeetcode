// 二分搜索的应用
// 步骤为：
// 1. 明确题目中x, f(x), target分别是什么，f(x)应该与x有单调关系（单增/单减）
// 2. 明确x的搜索区间，也就是left, right
// 3. 根据题意明确是求左侧区间还是右侧区间，随后便是套用框架

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 1e9 + 1;

        while(left < right){
            int mid = left + (right - left)/2;
            if(f(piles, mid) == h){
                // 搜索右区间
                right = mid;
            }
            else if(f(piles, mid) < h){
                // f(x)是与x反比，非常规
                right = mid;
            }
            else if(f(piles, mid) > h){
                left = mid + 1;
            }
        }
        return left;
    }

    int f(vector<int> &piles, int x){
        int n = piles.size();
        int hour = 0;
        for(int i=0; i<n; i++){
            hour += piles[i]/x;
            if(piles[i]%x > 0){
                hour++;
            }
        }
        return hour;
    }
};

// 也可以在明确后减少if，提高效率

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 1e9 + 1;

        while(left < right){
            int mid = left + (right-left)/2;
            if(f(piles, mid) <= h){
                right = mid;
            }
            else left = mid+1;
        }
        return left;
    }

    int f(vector<int> &piles, int x){
        int n = piles.size();
        int hour = 0;
        for(int i=0; i<n; i++){
            hour += piles[i]/x;
            if(piles[i]%x > 0){
                hour++;
            }
        }
        return hour;
    }
};