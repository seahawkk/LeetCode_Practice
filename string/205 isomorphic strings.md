## 205 同构字符串

* **题目来源：** [205 Isomorphic Strings](https://leetcode-cn.com/problems/isomorphic-strings/)

> 给定两个字符串 **s** 和 **t**，判断它们是否是同构的。
>
> 如果 **s** 中的字符可以被替换得到 **t** ，那么这两个字符串是同构的。
>
> 所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。
>
> **示例 1:**
>
> ```
> 输入: s = "egg", t = "add"
> 输出: true
> ```
>
> **示例 2:**
>
> ```
> 输入: s = "foo", t = "bar"
> 输出: false
> ```
>
> **示例 3:**
>
> ```
> 输入: s = "paper", t = "title"
> 输出: true
> ```

**思路：** 首先想到的是利用哈希表的键值和映射值建立起两个字符串中字符的一一对应的关系，当重复的字符串出现时，判断是否符合已经记录的对应关系。

### C++实现

```C++
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())
            return false;
        unordered_map<char,char> smap;
        unordered_map<char,char> tmap;
        for(int i=0;i<s.size();i++){
            if(smap.find(s[i])==smap.end() && tmap.find(t[i])==tmap.end()){
                smap[s[i]]=t[i];
                tmap[t[i]]=s[i];
            }
            else{
                if(smap[s[i]]!=t[i] || tmap[t[i]]!=s[i])
                    return false;
            }
        }
        return true;
    }
};
```

* 更简洁的一种方式

```C++
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())
            return false;
        int smap[256]={0};
        int tmap[256]={0};
        for(int i=0;i<s.size();i++){
            if(smap[s[i]]!= tmap[t[i]])
               return false;
            smap[s[i]]=i+1;
            tmap[t[i]]=i+1;
        }
        return true;
    }
};
```

