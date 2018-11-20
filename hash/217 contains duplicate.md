## 217 存在重复元素

* **题目来源：** [217 Contains Duplicate](https://leetcode-cn.com/problems/contains-duplicate/submissions/)

> 给定一个整数数组，判断是否存在重复元素。
>
> 如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。
>
> **示例 1:**
>
> ```
> 输入: [1,2,3,1]
> 输出: true
> ```
>
> **示例 2:**
>
> ```
> 输入: [1,2,3,4]
> 输出: false
> ```
>
> **示例 3:**
>
> ```
> 输入: [1,1,1,3,3,4,3,2,4,2]
> 输出: true
> ```

**思路：** 本题的思路和题目 1 中的相似，将数组中的元素依次放入hash表中，在插入的过程中判断是否已经存在相同的元素。时间复杂度为O(n)，空间复杂度为O(n)。

### C++实现

```C++
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()<2) return false;
        unordered_map<int,int> hash;
        for(int i=0;i<nums.size();i++){
            if(hash.find(nums[i])!=hash.end())
                return true;
            else
                hash[nums[i]]=i;
        }
        return false;  
    }
};
```

