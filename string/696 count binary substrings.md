## 696 计数二进制子串

* **题目来源：** [696 Count Binary Substrings](https://leetcode-cn.com/problems/count-binary-substrings/submissions/)

> 给定一个字符串 `s`，计算具有相同数量0和1的非空(连续)子字符串的数量，并且这些子字符串中的所有0和所有1都是组合在一起的。
>
> 重复出现的子串要计算它们出现的次数。
>
> **示例 1 :**
>
> ```
> 输入: "00110011"
> 输出: 6
> 解释: 有6个子串具有相同数量的连续1和0：“0011”，“01”，“1100”，“10”，“0011” 和 “01”。
> 
> 请注意，一些重复出现的子串要计算它们出现的次数。
> 
> 另外，“00110011”不是有效的子串，因为所有的0（和1）没有组合在一起。
> ```
>
> **示例 2 :**
>
> ```
> 输入: "10101"
> 输出: 4
> 解释: 有4个子串：“10”，“01”，“10”，“01”，它们具有相同数量的连续1和0。
> ```

**思路：** 先遍历一遍字符串，记录每次重复的0和1的数量，比如："00110011"，遍历后记录为：“2222”。“00011”遍历后记录为：“32”。然后再对这个新的记录遍历，并取两个相邻数中较小的那一个。

### C++实现

```C++
class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> rec;
        int count = 1;
        for(int i=1, n=s.size(); i<=n; ++i){
            if(s[i] == s[i-1]){
                ++count;
            }else{
                rec.push_back(count);
                count = 1;
            }
        }
        int res = 0;
        for(int i=1, n=rec.size(); i<n; ++i){
            res += min(rec[i-1], rec[i]);
        }
        return res;
    }
};
```

* **更快的方式**

```C++
class Solution {
public:
    int countBinarySubstrings(string s) {
        int prelen=0,curlen=1,count=0;
        for(int i=1;i<s.size();i++){
            if(s[i] == s[i-1])
                curlen++;
            else{
                prelen=curlen;
                curlen=1;
            }
            if(prelen>=curlen)
                count++;
        }
        return count;
    }
};
```

