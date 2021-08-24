// 在a<=b<=c的时候，a+b>c即可，
// 为了提升效率，可以在确定nums[a]+nums[b]>nums[k]时，在[b+1,n-1]内二分查找k，k-b即为输出

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if( n <3) return 0;
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int k=n-1; k>1; k--){
            int i =0, j =k-1;
            while(i < j){
                if(nums[k] < nums[i]+nums[j] ){
                    res += j-i; //还是不太懂
                    j--;
                }
                else
                i++;
            }

        }
        return res;
    }
};