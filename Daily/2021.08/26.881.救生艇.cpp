/*
881.
贪心+排序双指针
为了船尽量少，需要有尽量多的2人乘船
- 如果最轻的人和最重的人>limit，则最重者无论与谁都无法乘同一搜船，右指针--
- 否则，两人同乘一艘船，左右指针缩进
*/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size(); // the number of people
        if(n == 1) return 1;
        sort(people.begin(), people.end());
        int i=0, j=n-1;
        int ship = 0;
        while(i <= j){
            if(people[i] + people[j] > limit){
                ship++;
                j--;
            }
            else{
                ship++;
                i++; j--;
            }
        }
        return ship;
    }
};