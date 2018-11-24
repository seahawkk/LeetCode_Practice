## 409 最长回文串

* **题目来源：** [409 Longest Palindrome](https://leetcode-cn.com/problems/longest-palindrome/)

> 给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
>
> 在构造过程中，请注意区分大小写。比如 `"Aa"` 不能当做一个回文字符串。
>
> **注意:**
> 假设字符串的长度不会超过 1010。
>
> **示例 1:**
>
> ```
> 输入:
> "abccccdd"
> 
> 输出:
> 7
> 
> 解释:
> 我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
> ```

**思考：** 对于给定字符串中的每一个字符，当能够从其中取出偶数的个数时，则该字符就能够构成回文。所以将字符串中的每一个字符用哈希表表示，键值为字符串，映射值为其出现的次数。对于出现次数为偶数的字符，可以全部拿来构成回文串，对于出现次数为奇数的字符，将其减一之后剩下的次数可以构成回文串。另外需要注意的是：回文串的正中间允许出现单个的字符，因此，假如字符串中存在出现次数为奇数的字符，应当在回文串中间加入单个字符，即回文串长度加一。

### python实现

```python
class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        ctmap={}
        res=0
        for i in range(len(s)):
            ctmap[s[i]]=ctmap.get(s[i],0)+1
        for char in ctmap:
            res=res+(ctmap[char]//2)*2
        if res<len(s):
            res=res+1
        return res
```

### C++实现

* 哈希表

```C++
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> hash;
        int ans=0;
        for(int i=0;i<s.size();i++)
            hash[s[i]]++;
        for(auto a:hash)
            ans+=(a.second/2)*2;
        if(ans<s.size())
            ans++;
        return ans;
    }
};
```

* 数组（速度更快）

```C++
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> cnts(256);
        int ans=0;
        for(int i=0;i<s.size();i++)
            cnts[s[i]]++;
        for(auto a:cnts)
            ans+=(a/2)*2;
        if(ans<s.size())
            ans++;
        return ans;
    }
};
```

