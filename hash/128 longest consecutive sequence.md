128 最长连续序列

* **题目来源：** [128 Longest Consecutive Sequence](https://leetcode-cn.com/problems/longest-consecutive-sequence/submissions/)

> 给定一个未排序的整数数组，找出最长连续序列的长度。
>
> 要求算法的时间复杂度为 *O(n)*。
>
> **示例:**
>
> ```
> 输入: [100, 4, 200, 1, 3, 2]
> 输出: 4
> 解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
> ```

**思路：**[链接](http://zxi.mytechroad.com/blog/hashtable/leetcode-128-longest-consecutive-sequence/) Hashtable/Hashset

![1542718275553](C:\Users\孙浩\AppData\Roaming\Typora\typora-user-images\1542718275553.png)

​![1542718459638](C:\Users\孙浩\AppData\Roaming\Typora\typora-user-images\1542718459638.png)

### C++实现

* **online**

```C++
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> h;
        int res=0;
        for(int num:nums){
            if(h.count(num))
                continue;
            auto it_l=h.find(num-1);
            auto it_r=h.find(num+1);
            int l=it_l!=h.end() ? h[num-1] : 0;
            int r=it_r!=h.end() ? h[num+1] : 0;
            if(l>0 && r>0)
                h[num]=h[num-l]=h[num+r]=r+l+1;
            else if(l>0)
                h[num-l]=h[num]=l+1;
            else if(r>0)
                h[num]=h[num+r]=r+1;
            else
                h[num]=1;
        }
        for(const auto& a:h){
            res=max(a.second,res);
        }
        return res;
    }
};
```

* **offline**

```C++
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> h(nums.begin(), nums.end());
        int ans = 0;
        for (int num : nums)            
            if (!h.count(num - 1)) {
                int l = 0;
                while (h.count(num++)) ++l;
                ans = max(ans, l);
            }
        return ans;
    }
};
```

