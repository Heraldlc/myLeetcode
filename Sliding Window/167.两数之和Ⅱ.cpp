// 题目要求返回的是两个数之和为target的下标，可以想到用双指针
// sum = nums[left] + nums[right]
// 因为数组升序，所有采用二分搜索的办法逐渐逼近target即可

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1;
        while(left <= right){
            int sum = numbers[left] + numbers[right];
            if(sum == target){
                return {left+1, right+1};
            }
            else if(sum < target){
                left++;
            }
            else if(sum > target){
                right--;
            }
        }
        return {-1, -1};
    }
};