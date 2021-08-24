/*
题目要求的超级丑数，是质因数都在给定数组内，那么从**1**开始，所有的丑数都是由数组中的丑数相乘得到的，为了从小到大输出，我们可以建立一个小根堆heap，每次取出堆顶元素x，则对于数组primes的任意质数p，p*x也是超级丑数，此时再把加入小根堆，再取出堆顶元素即可

**要点：**

- 用priority_queue<long, vector<long>, greator<long>>实现的小根堆，从小往大排序；大根堆为less，
- unordered_set的使用是为了避免存入相同的数
*/

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int sz = primes.size();        
        unordered_set<long> seen;
        priority_queue<long, vector<long>, greater<long>> heap;
        seen.insert(1);
        heap.push(1);
        int ugly = 0;
        for(int i=0; i<n; i++)
        {
            long cur = heap.top();
            heap.pop();
            ugly = (int)cur;
            for(int j=0; j<sz; j++)
            {
                long next = primes[j] * cur;
                if( seen.insert(next).second ) 
                    heap.push(next);
            }

        }
        return ugly;
    }
};