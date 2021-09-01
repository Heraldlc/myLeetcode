/*
题目要求找第 k 个最大的元素，和我们刚才说的第 k 大的元素在语义上不太一样，题目的意思相当于是把 nums 数组降序排列，然后返回第 k 个元素。
*/

// 解法一：使用优先队列创建堆
// 较大的元素会沉淀下去，较小的元素会浮上来
class Solution {
    public int findKthLargest(int[] nums, int k) {
        // 小顶堆，堆顶是最小元素
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int e : nums) {
            // 每个元素都要过一遍二叉堆
            pq.offer(e);
            // 堆中元素多于 k 个时，删除堆顶元素
            if (pq.size() > k) {
                pq.poll();
            }
        }   
        // pq 中剩下的是 nums 中 k 个最大元素，
        // 堆顶是最小的那个，即第 k 个最大元素
        return pq.peek();
    }
}

// 解法二：使用快速选择算法--> 需要学习

