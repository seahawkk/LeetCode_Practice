## 283 移动零（将数组中的0移到末尾）

* **题目来源：** [283 Move Zeroes](https://leetcode-cn.com/problems/move-zeroes/submissions/)

> 给定一个数组 `nums`，编写一个函数将所有 `0` 移动到数组的末尾，同时保持非零元素的相对顺序。
>
> **示例:**
>
> ```
> 输入: [0,1,0,3,12]
> 输出: [1,3,12,0,0]
> ```
>
> **说明**:
>
> 1. 必须在原数组上操作，不能拷贝额外的数组。
> 2. 尽量减少操作次数。

**思路：** 数组中真正具有信息的是其中的非零值，所以只需要先遍历访问非零值，将其按照原有的顺序置于数组中，保留其数字信息和位置信息，然后将数组中剩下的元素置零即可。

### python实现

```python
class Solution:
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        index=0
        for num in nums:
            if num!=0:
                nums[index]=num
                index+=1
        while(index<len(nums)):
            nums[index]=0
            index+=1
```

### C++实现

```C++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index=0;
        for(int num:nums){
            if(num!=0)
                nums[index++]=num;
        }
        while(index<nums.size()){
            nums[index]=0;
            index++;
        }
    }
};
```

```C++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int end=nums.size();
        int start=0;
        for(int i=0;i<end;){
            if(nums[i]==0){
                for(int j=i;j<end-1;j++){
                    nums[j]=nums[j+1];
                    nums[j+1]=0;
                }
                end--;
            }
            else
                i++;
        }
    }
};
```

