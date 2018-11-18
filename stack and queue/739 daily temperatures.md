## 739 每日温度（数组中与下一个比它大的元素之间的距离）

* **题目来源：** [739 Daily Temperatures](https://leetcode-cn.com/problems/daily-temperatures/submissions/)

> 根据每日 `气温` 列表，请重新生成一个列表，对应位置的输入是你需要再等待多久温度才会升高的天数。如果之后都不会升高，请输入 `0` 来代替。
>
> 例如，给定一个列表 `temperatures = [73, 74, 75, 71, 69, 72, 76, 73]`，你的输出应该是 `[1, 1, 4, 2, 1, 1, 0, 0]`。
>
> **提示：**`气温` 列表长度的范围是 `[1, 30000]`。每个气温的值的都是 `[30, 100]` 范围内的整数。

**思路：** 一种比较容易想到的思路是从数组的第一个元素开始，依次寻找下一个比它的值大的元素需要的天数。但是需要比较大的时间代价。

第二种思路是利用栈。

* ### Key Point

  - Use stack to store those indexes we have not find answers
  - In the stack, from the bottom(0) to the top(stack.length-1), the temperatures decend.
  - We iterate the array just once
  - When we iterate through the array, to make sure if `temperatures[i]` is the answer to the indexes in our stack, we compare it to the toppest element in our stack, and if it is the answer, we will continue comparing and poping the stack until it's empty.

### python实现

```python
class Solution:
    def dailyTemperatures(self, temperatures):
        """
        :type temperatures: List[int]
        :rtype: List[int]
        """
        size=len(temperatures)
        res=[0]*size
        stack=[]
        for cur in range(size):
            while len(stack)!=0 and temperatures[cur]>temperatures[stack[-1]]:
                res[stack[-1]]=cur-stack[-1]
                stack.pop()
            stack.append(cur)
        return res
```

### C++实现

```C++
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> index;
        int size=temperatures.size();
        vector<int> res(size,0);
        for(int cur=0;cur<=size-1;cur++){
            while(!index.empty() && temperatures[cur]>temperatures[index.top()]){
                res[index.top()]=cur-index.top();
                index.pop();
            }
            index.push(cur);
        }
        return res;
    }
};
```

