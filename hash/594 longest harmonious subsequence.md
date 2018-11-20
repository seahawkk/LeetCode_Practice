## 594 最长和谐子序列

* **题目来源：** [594 Longest Harmonious Subsequence](https://leetcode-cn.com/problems/longest-harmonious-subsequence/)

> 和谐数组是指一个数组里元素的最大值和最小值之间的差别正好是1。
>
> 现在，给定一个整数数组，你需要在所有可能的子序列中找到最长的和谐子序列的长度。
>
> **示例 1:**
>
> ```
> 输入: [1,3,2,2,5,2,3,7]
> 输出: 5
> 原因: 最长的和谐数组是：[3,2,2,2,3].
> ```

**思路：** 将数组中的元素依次放入hash表中，其中关键值为nums数组中出现过的元素的值，映射值是该值出现的次数。对于和谐数组，数组中的最大值和最小值相差1，实际就是表示数组中只存在两个相邻的整数，因此通过遍历hash表，来判断对于表中的关键值key，是否存在它的相邻整数值key+1(通过key-1判断也是一样的)，如果存在，就计算key和key+1所对应的映射值的和，通过遍历得到最大和，也就是最长和谐子序列的长度。

### python实现

```python
class Solution:
    def findLHS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count={}
        res=0
        for i in nums:
            count[i]=count.get(i,0)+1
        for j in count:
            if j+1 in count:
                res=max(count[j]+count[j+1],res)
        return res
```

### C++实现

```C++
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> hash;
        int res=0;
        for(auto key:nums)
            hash[key]++;
        for(auto key:hash){
            if(hash.count(key.first+1)>0)
                res=max(hash[key.first+1]+key.second,res);
        }
        return res;
    }
};
```

