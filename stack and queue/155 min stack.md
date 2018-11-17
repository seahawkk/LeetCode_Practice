## 155 最小值栈

* **题目来源：** [155 Min Stack](https://leetcode-cn.com/problems/min-stack/)

> 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
>
> - push(x) -- 将元素 x 推入栈中。
> - pop() -- 删除栈顶的元素。
> - top() -- 获取栈顶元素。
> - getMin() -- 检索栈中的最小元素。
>
> **示例:**
>
> ```
> MinStack minStack = new MinStack();
> minStack.push(-2);
> minStack.push(0);
> minStack.push(-3);
> minStack.getMin();   --> 返回 -3.
> minStack.pop();
> minStack.top();      --> 返回 0.
> minStack.getMin();   --> 返回 -2.
> ```

**思路：**

* 首先想到的是建立一个列表，使列表中的元素始终与栈中元素保持一致，需要返回最小值时就遍历列表，返回其中的最小值，但需要的时间代价较大。推荐第二种方法。
* 假设需要建立的栈为 `Stack` ，建立一个额外的栈 `minStack` ，`Stack`每执行一次`push` 或 `pop` 操作，都将新栈的最小值`push` 或 `pop` 进`minStack` 中，始终保持`minStack` 的最上层元素对应当前 `Stack` 的最小值。

### C++实现

* 列表

```C++
class MinStack {
    stack<int> Stack;
    vector<int> nums;
public:
    void push(int x) {
        Stack.push(x);
        nums.push_back(x);
    }
    void pop() {
        Stack.pop();
        nums.pop_back();
    }
    int top() {
        return Stack.top();
    }
    
    int getMin() {
        int min=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<min)
                min=nums[i];
        }
        return min;
    }
};
```

* **双栈**

```C++
class MinStack {
    stack<int> Stack;
    stack<int> minStack;
    int min;
public:
    void push(int x) {
        if(Stack.empty()) min=x;
        else{
            min=minStack.top();
            if(x<min)
                min=x;
        }
        Stack.push(x);
        minStack.push(min);
    }
    void pop() {
        Stack.pop();
        minStack.pop();
    }
    int top() {
        return Stack.top();
    }
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
```

