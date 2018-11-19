## 1 两数之和（数组中两个数的和为给定值）

* **题目来源：** [1 Two Sum](https://leetcode-cn.com/problems/two-sum/)

> 给定一个整数数组 `nums` 和一个目标值 `target`，请你在该数组中找出和为目标值的 **两个** 整数。
>
> 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
>
> **示例:**
>
> ```
> 给定 nums = [2, 7, 11, 15], target = 9
> 
> 因为 nums[0] + nums[1] = 2 + 7 = 9
> 所以返回 [0, 1]
> ```

**思路：** 可以直接采用暴露的方法求解，从第一个元素开始遍历其后续元素，判断有没有两个元素的值等于给定值；也可以先对数组排序，然后利用双指针方法或者是二分查找方法，这样做的时间复杂度是O(NlogN)，空间复杂度是O(1)。

也可以用 hash 表来存储数组元素和索引的映射，在访问到nums[i]时，判断hash table中是否存在target-nums[i]，如果存在说明target-nums[i]所在的索引和 i 就是要找的两个数。该方法的时间复杂度是O(N)，空间复杂度是O(N)，使用空间来换取时间。

### python实现

```python
class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if len(nums)<=1:
            return False
        dict={}
        for i in range(len(nums)):
            if target-nums[i] in dict:
                return [dict[target-nums[i]],i]
            else:
                dict[nums[i]]=i
```

### C++实现

```C++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            if(hash.find(target-nums[i])!=hash.end()){
                res.push_back(hash[target-nums[i]]);
                res.push_back(i);
            }
            else
                hash[nums[i]]=i;
        }
        return res;
    }
};
```

