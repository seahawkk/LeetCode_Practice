## 225 用队列实现栈

* **题目来源：** [225 Implement Stack using Stacks](https://leetcode-cn.com/problems/implement-stack-using-queues/)

> 使用队列实现栈的下列操作：
>
> - push(x) -- 元素 x 入栈
> - pop() -- 移除栈顶元素
> - top() -- 获取栈顶元素
> - empty() -- 返回栈是否为空
>
> **注意:**
>
> - 你只能使用队列的基本操作-- 也就是 `push to back`, `peek/pop from front`, `size`, 和 `is empty` 这些操作是合法的。
> - 你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
> - 你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。

**思考：** 栈是后入先出类型，用队列实现栈，当元素 `X` 入队时，为了保证后入先出的顺序，需要将 `X` 插入队列的首部，而默认的入队顺序是队列尾部，因此在将 `X` 入队之后，需要将  `X` 前面的元素依次先出队再入队，这样就能保证 `X` 后入先出。

### C++实现 

```C++
class MyStack {
    queue<int> Queue;
public:
    /** Initialize your data structure here. */
    MyStack() {
        queue<int> Queue;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        Queue.push(x);
        int count=Queue.size()-1;
        for(int i=1;i<=count;i++){
            int front=Queue.front();
            Queue.pop();
            Queue.push(front);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int front=Queue.front();
        Queue.pop();
        return front;
    }
    
    /** Get the top element. */
    int top() {
        return Queue.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return Queue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
```

