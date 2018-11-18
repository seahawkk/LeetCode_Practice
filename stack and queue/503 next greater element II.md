## 503 下一个更大元素（类似于739）

* **题目来源：** [503 Next Greater Element II](https://leetcode-cn.com/problems/next-greater-element-ii/submissions/)

> 给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。数字 x 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1。
>
> **示例 1:**
>
> ```
> 输入: [1,2,1]
> 输出: [2,-1,2]
> 解释: 第一个 1 的下一个更大的数是 2；
> 数字 2 找不到下一个更大的数； 
> 第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
> ```
>
> **注意:** 输入数组的长度不会超过 10000。

**思路：** 本题类似于LeetCode 739中求与下一个比当前元素大的值之间的距离，区别有两点，第一个是返回值不是两者之间的距离差值（即索引差），而是比它大的那个元素的具体值，第二个是数组是循环数组，意思也就是说第一个比当前元素大的值可能出现在它之后也可能出现在之前。当像LeetCode 739 中使用栈来解决时，为了处理较大值出现在元素之前的情况，当遍历至数组的最后一个元素之后，重新从数组的头开始遍历，这样就可以比较前面的值，且符合循环的顺序。

### python实现

```python
class Solution:
    def nextGreaterElements(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        size=len(nums)
        res=[-1]*size
        stack=[]
        for cur in range(2*size):
            curindex=cur % size
            while len(stack)!=0 and nums[curindex]>nums[stack[-1]]:
                res[stack[-1]]=nums[curindex]
                stack.pop()
            stack.append(curindex)
        return res
```

### C++实现

```C++
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size=nums.size();
        vector<int> res(size,-1);
        stack<int> index;
        for(int cur=0;cur<size*2;cur++){
            int curindex=cur % size;
            while(!index.empty() && nums[curindex]>nums[index.top()]){
                res[index.top()]=nums[curindex];
                index.pop();
            }
            index.push(curindex);
        }
        return res;
    }
};
```

