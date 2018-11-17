## 20 有效的括号

* **题目来源：** [20 Valid Parentheses](https://leetcode-cn.com/problems/valid-parentheses/)

> 给定一个只包括 `'('`，`')'`，`'{'`，`'}'`，`'['`，`']'` 的字符串，判断字符串是否有效。
>
> 有效字符串需满足：
>
> 1. 左括号必须用相同类型的右括号闭合。
> 2. 左括号必须以正确的顺序闭合。
>
> 注意空字符串可被认为是有效字符串。
>
> **示例 1:**
>
> ```
> 输入: "()"
> 输出: true
> ```
>
> **示例 2:**
>
> ```
> 输入: "()[]{}"
> 输出: true
> ```
>
> **示例 3:**
>
> ```
> 输入: "(]"
> 输出: false
> ```
>
> **示例 4:**
>
> ```
> 输入: "([)]"
> 输出: false
> ```
>
> **示例 5:**
>
> ```
> 输入: "{[]}"
> 输出: true
> ```

**思路：** 利用栈来解决括号匹配的问题，将字符串中的字符依次入栈，遇到匹配的括号则将其弹出，最后判断栈是否为空。若为空则返回真。

### C++实现

```C++
class Solution {
public:
    bool isValid(string s) {
        stack<int> vstack;
        if(!s.size()) return true;
        int length=s.size();
        for(int i=0;i<=length-1;i++){
            if(vstack.empty()) 
                vstack.push(s[i]);
            else{
                if((s[i]==')' && vstack.top()=='(') ||
                   (s[i]=='}' && vstack.top()=='{') ||
                   (s[i]==']' && vstack.top()=='['))
                    vstack.pop();
                else
                    vstack.push(s[i]);
            }
        }
        if(vstack.empty()) return true;
        return false;
    }
};
```

