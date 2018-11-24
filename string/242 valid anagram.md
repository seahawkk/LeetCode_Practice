## 242 有效的字母异位词

* **题目来源：** [242 Valid Anagram](https://leetcode-cn.com/problems/valid-anagram/submissions/)

> 给定两个字符串 *s* 和 *t* ，编写一个函数来判断 *t* 是否是 *s* 的一个字母异位词。
>
> **示例 1:**
>
> ```
> 输入: s = "anagram", t = "nagaram"
> 输出: true
> ```
>
> **示例 2:**
>
> ```
> 输入: s = "rat", t = "car"
> 输出: false
> ```
>
> **说明:**
> 你可以假设字符串只包含小写字母。

**思路：** 

* 两个字母为字母异位词，意味着两个字符串的字符个数相同，且s中的字符都能在t中找到与之对应的元素。因此考虑到寻找的时间代价，将s和t都用哈希表来表示，哈希表的映射值是字符出现的次数。然后将s中的键值逐个与t中键值比较，判断t中是否存在相同的键值且映射值是否相同。也可以只用一个哈希表来存储元素：使用一个哈希表来记录两个字符串s和t中每个字母的出现次数。对于s中的每个字母，它将计数器增加1，而对于t中的每个字母，它将计数器减1。最后，如果两个是彼此的字母异位词，则所有计数器将为0。
* 由于问题陈述说“字符串只包含小写字母”，我们可以简单地使用数组来模拟unordered_map并加速代码。

### python实现

```python
class Solution:
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s)!=len(t):
            return False
        sh={}
        for i in range(len(s)):
            sh[s[i]]=sh.get(s[i],0)+1
            sh[t[i]]=sh.get(t[i],0)-1
        for j in range(len(s)):
            if sh[s[j]]:
                return False
        return True
```

### C++实现

```C++
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int n = s.length();
        int counts[26] = {0};
        for (int i = 0; i < n; i++) { 
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
            if (counts[i]) return false;
        return true;
    }
};
```

```C++
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int n = s.length();
        int counts[26] = {0};
        for (int i = 0; i < n; i++) { 
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
            if (counts[i]) return false;
        return true;
    }
};
```

