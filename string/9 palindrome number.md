## 9 回文数

* **题目来源：** [9 Palindrome Number](https://leetcode-cn.com/problems/palindrome-number/submissions/)

> 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
>
> **示例 1:**
>
> ```
> 输入: 121
> 输出: true
> ```
>
> **示例 2:**
>
> ```
> 输入: -121
> 输出: false
> 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
> ```
>
> **示例 3:**
>
> ```
> 输入: 10
> 输出: false
> 解释: 从右向左读, 为 01 。因此它不是一个回文数。
> ```

**思路：** 可以将整数转换为字符串，然后从头尾开始比较，判断是否是回文数。

如果不转换为字符串，将原有的整数转换为转置之后的整数，然后判断两数是否相等。

### python实现

```pyhton
class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x==0:
            return True
        if x<0 or x%10==0:
            return False
        right=0
        y=x
        while(x):
            right=right*10+x%10
            x=x//10
        if(y!=right):
            return False
        return True
```

### C++实现

* 转换为字符串

```C++
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        vector<char> str;
        while(x){
            str.push_back(x%10);
            x=x/10;
        }
        for(int start=0,end=str.size()-1;start<=end;start++,end--){
            if(str[start]!=str[end])
                return false;
        }
        return true;
    }
};
```

* 不转换

```C++
class Solution {
public:
    bool isPalindrome(int x) {
        if(x==0)
            return true;
        if(x<0 || x%10==0)
            return false;
        int right=0;
        int y=x;
        while(x){
            right=right*10+x%10;
            x=x/10;
        }
        if(y==right)
            return true;
        return false;
    }
};
```

