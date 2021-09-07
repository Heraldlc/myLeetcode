class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // x为装载重量，f(x)为运输所有包裹的天数，两者为反比
        int left = 0;
        int right = 1;
        for(int i=0; i<weights.size(); i++){
            left = max(left, weights[i]);
            right += weights[i];
        }
        
        while(left < right){
            int mid = left + (right-left)/2;
            if(f(weights, mid) <= days){
                right = mid;
            }
            else if(f(weights, mid) > days){
                left = mid+1;
            }
        }
        return left;
    }

    int f(vector<int> &weights, int x){
        int day = 0;
        for(int i=0; i<weights.size(); ){
            // 尽可能多的装货物
            int cap = x;
            while(i<weights.size()){
                if(cap<weights[i]) break;
                else cap -= weights[i];
                i++;
            }
            day++;
        }
        return day;
    }
};