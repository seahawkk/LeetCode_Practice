## 647 回文子串

* **题目来源：** [647 Palindromic Substrings](https://leetcode-cn.com/problems/palindromic-substrings/submissions/)

> 给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
>
> 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。
>
> **示例 1:**
>
> ```
> 输入: "abc"
> 输出: 3
> 解释: 三个回文子串: "a", "b", "c".
> ```
>
> **示例 2:**
>
> ```
> 输入: "aaa"
> 输出: 6
> 说明: 6个回文子串: "a", "a", "a", "aa", "aa", "aaa".
> ```

**思路：** 从字符串的某一个字符开始，从中心向两边延伸，与此同时判断子串的头尾是否相同，如果相同则意味着可以构成一个回文子串。延伸的起点可以是一个相同的字符（子串字符数为奇数），也可以是相邻的两个字符（子串字符数为偶数）。

### python实现

```python
class Solution:
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        self.cnt=0
        for i in range(len(s)):
            self.extendSubstrings(s,i,i)
            self.extendSubstrings(s,i,i+1)
        return self.cnt
    def extendSubstrings(self,s,start,end):
        while(start>=0 and end<len(s) and s[start]==s[end]):
            start-=1
            end+=1
            self.cnt+=1
```

### C++实现

```c++
class Solution {
    int cnt=0;
public:
    int countSubstrings(string s) {
        for(int i=0;i<s.size();i++){
            extendSubstrings(s,i,i);
            extendSubstrings(s,i,i+1);
        }
        return cnt;
    }
private:
    void extendSubstrings(string s,int start,int end){
        while(start>=0 && end<s.length() && s[start]==s[end]){
            start--;
            end++;
            cnt++;
        }
    }
};
```

