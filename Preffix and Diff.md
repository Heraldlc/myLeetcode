# 前缀和和差分

## 前缀和

前缀和技巧是非常常用的算法技巧，**前缀和主要适用的场景是原始数组不会被修改的情况下，频繁查询某个区间的累加和**。

核心代码就是下面这段：

```java
class PrefixSum {
    // 前缀和数组
    private int[] prefix;
    
    /* 输入一个数组，构造前缀和 */
    public PrefixSum(int[] nums) {
        prefix = new int[nums.length + 1];
        // 计算 nums 的累加和
        for (int i = 1; i < prefix.length; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
    }

    /* 查询闭区间 [i, j] 的累加和 */
    public int query(int i, int j) {
        return prefix[j + 1] - prefix[i];
    }
}
```

`prefix[i]` 就代表着 `nums[0..i-1]` 所有元素的累加和，如果我们想求区间 `nums[i..j]` 的累加和，只要计算 `prefix[j+1] - prefix[i]` 即可，而不需要遍历整个区间求和。



## 差分

**差分数组的主要适用场景是频繁对原始数组的某个区间的元素进行增减**。

比如说，我给你输入一个数组 `nums`，然后又要求给区间 `nums[2..6]` 全部加 1，再给 `nums[3..9]` 全部减 3，再给 `nums[0..4]` 全部加 2，再给…

一通操作猛如虎，然后问你，最后 `nums` 数组的值是什么？

常规的思路很容易，你让我给区间 `nums[i..j]` 加上 `val`，那我就一个 for 循环给它们都加上呗，还能咋样？这种思路的时间复杂度是 O(N)，由于这个场景下对 `nums` 的修改非常频繁，所以效率会很低下。

这里就需要差分数组的技巧，类似前缀和技巧构造的 `prefix` 数组，我们先对 `nums` 数组构造一个 `diff` 差分数组，**`diff[i]` 就是 `nums[i]` 和 `nums[i-1]` 之差**：

```java
int[] diff = new int[nums.length];
// 构造差分数组
diff[0] = nums[0];
for (int i = 1; i < nums.length; i++) {
    diff[i] = nums[i] - nums[i - 1];
```

通过这个 `diff` 差分数组是可以反推出原始数组 `nums` 的，代码逻辑如下：

```java
int[] res = new int[diff.length];
// 根据差分数组构造结果数组
res[0] = diff[0];
for (int i = 1; i < diff.length; i++) {
    res[i] = res[i - 1] + diff[i];
}
```

**这样构造差分数组 `diff`，就可以快速进行区间增减的操作**，如果你想对区间 `nums[i..j]` 的元素全部加 3，那么只需要让 `diff[i] += 3`，然后再让 `diff[j+1] -= 3` 即可，也就是说左侧加inc，右侧+1减inc。

**原理很简单，回想`diff`数组反推`nums`数组的过程，`diff[i] += 3`意味着给`nums[i..]`所有的元素都加了 3，然后`diff[j+1] -= 3`又意味着对于`nums[j+1..]`所有元素再减 3，那综合起来，是不是就是对`nums[i..j]`中的所有元素都加 3 了**？

所以只要花费O(1)的时间修改既可以给元素组一个范围内进行修改

方法抽象成代码

```java
class Difference{
    // 差分数组
    private int[] diff;
    
    public Difference(int[] nums){
        assert nums.length > 0;
        diff = new int[nums.length];
        diff[0] = 0;
        for(int i=1; i<nums.length; i++){
            diff[i] = nums[i] - nums[i-1];
        }
    }
    
    // 给闭区间[i,j]增加val（可以是负数）
    public void increment(int i, int j, int val){
        diff[i] += val;
        // 防止越界
        if(j+1 < diff.length){
            diff[j+1] -= val;
        }
    }
    
    // 反推原数组
    public int[] result(){
        int[] res = new int[diff.length];
        // 根据差分数组构造结果数组
        res[0] = diff[0];
        for(int i=1; i<nums.length; i++){
            res[i] = diff[i-1] + res[i-1];
        }
        return res;
    }
}
```

