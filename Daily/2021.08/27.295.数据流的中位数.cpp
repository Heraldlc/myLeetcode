/*
295.
前置知识，使用priority_queue构建堆，函数模板为
template <typename T, typename Container=std::vector<T>, typename Compare=std::less<T>> class priority_queue
- less表示从大往小
- greater表示从小往大

我们用两个优先队列 queMax 和 queMin 分别记录大于中位数的数和小于等于中位数的数。
当累计添加的数的数量为奇数时，queMin 中的数的数量比 queMax 多一个，此时中位数为 queMin 的队头。
当累计添加的数的数量为偶数时，两个优先队列中的数的数量相同，此时中位数为它们的队头的平均值。

当我们尝试添加一个数 num 到数据结构中，我们需要分情况讨论：
1. num <= max(queMin)
- 此时 num 小于等于中位数，我们需要将该数添加到queMin 中。新的中位数将小于等于原来的中位数
因此我们可能需要将queMin 中最大的数移动到 \textit{queMax}queMax 中。

2. num > max(queMin)
此时 num 大于中位数，我们需要将该数添加到queMin 中。新的中位数将大于等于原来的中位数
因此我们可能需要将 queMax 中最小的数移动到 queMin 中。

特别地，当累计添加的数的数量为0 时，我们将 num 添加到 queMin 中。

*/


class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> queMin;
    priority_queue<int, vector<int>, greater<int>> queMax;

    MedianFinder() {}

    void addNum(int num) {
        if (queMin.empty() || num <= queMin.top()) {
            queMin.push(num);
            if (queMax.size() + 1 < queMin.size()) {
                queMax.push(queMin.top());
                queMin.pop();
            }
        } else {
            queMax.push(num);
            if (queMax.size() > queMin.size()) {
                queMin.push(queMax.top());
                queMax.pop();
            }
        }
    }

    double findMedian() {
        if (queMin.size() > queMax.size()) {
            return queMin.top();
        }
        return (queMin.top() + queMax.top()) / 2.0;
    }
};

