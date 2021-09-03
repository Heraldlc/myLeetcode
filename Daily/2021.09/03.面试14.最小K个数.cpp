// 构造大根堆

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        int n = arr.size();
        if(n == 0) return {};
        vector<int> res(k);
        // 容量为k的大根堆        
        priority_queue<int> heap;
        heap.push(arr[0]);
        for(int i=1; i<n; i++){
            if(heap.size() < k){
                heap.push(arr[i]);
            }
            else if(heap.top() > arr[i]){
                heap.pop();
                heap.push(arr[i]);
            }
        }
        // 输出堆        
        for(int j=0; j<k; j++){
            res[j] = heap.top();
            heap.pop();
        }
        return res;
    }
};