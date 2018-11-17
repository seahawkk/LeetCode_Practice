## 232 用栈实现队列

* **题目来源：** [Implement Queue using Stacks](https://leetcode-cn.com/problems/implement-queue-using-stacks/)

> 使用栈实现队列的下列操作：
>
> - push(x) -- 将一个元素放入队列的尾部。
> - pop() -- 从队列首部移除元素。
> - peek() -- 返回队列首部的元素。
> - empty() -- 返回队列是否为空。
>
> **示例:**
>
> ```
> MyQueue queue = new MyQueue();
> 
> queue.push(1);
> queue.push(2);  
> queue.peek();  // 返回 1
> queue.pop();   // 返回 1
> queue.empty(); // 返回 false
> ```
>
> **说明:**
>
> - 你只能使用标准的栈操作 -- 也就是只有 `push to top`, `peek/pop from top`, `size`, 和 `is empty` 操作是合法的。
> - 你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
> - 假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）。

**思路：** 栈的顺序为后进先出，队列的顺序为先进先出，通过两个栈来实现队列，一个元素需要经过两个栈才能出队，经过第一个栈时，元素的顺序被翻转，此时从栈中依次弹出进入第二个栈，元素的顺序再次被翻转，此时就是先入先出的顺序。

### C++实现

```C++
class MyQueue {
    stack<int> stackin;
    stack<int> stackout;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        stack<int> stackin;
        stack<int> stackout;
    }
    /** Push element x to the back of queue. */
    void push(int x) {
        stackin.push(x);
    }
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(stackout.empty()){
            while(!stackin.empty()){
                int a=stackin.top();
                stackin.pop();
                stackout.push(a);
            }
        }
        int b=stackout.top();
        stackout.pop();
        return b;    
    }
    
    /** Get the front element. */
    int peek() {
        if(stackout.empty()){
            while(!stackin.empty()){
                int a=stackin.top();
                stackin.pop();
                stackout.push(a);
            }
        }
        int b=stackout.top();
        return b;   
    }
    /** Returns whether the queue is empty. */
    bool empty() {
        return (stackin.empty() && stackout.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
```

