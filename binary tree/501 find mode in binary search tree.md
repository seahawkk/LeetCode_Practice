## 二叉搜索树中的众数

* **题目来源：** [501 Find Mode in Binary Search Tree](https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/)

> 给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。
>
> 假定 BST 有如下定义：
>
> - 结点左子树中所含结点的值小于等于当前结点的值
> - 结点右子树中所含结点的值大于等于当前结点的值
> - 左子树和右子树都是二叉搜索树
>
> 例如：
> 给定 BST `[1,null,2,2]`,
>
> ```
>    1
>     \
>      2
>     /
>    2
> ```
>
> `返回[2]`.
>
> **提示**：如果众数超过1个，不需考虑输出顺序

**思路：** 为便于比较二叉搜索树中的数值，首先中序遍历将二叉搜索树转换为有序列表，为了比较元素出现次数，初始化最大次数`maxcount`、元素出现次数`count`，以及一个空数组保存当前次数最大的值。通过元素直接对比，计算元素 `cur` 出现的次数 `count` ，当遇到不相等的值时，比较`count`和`maxcount`，如果`count`大于`maxcount`，则清空当前数组，将`cur`加入，如果得到`count`等于`maxcount`，则不清空数组，直接将`cur`加入数组。然后将`cur`赋予新的值。这样就能保证数组中存入的一直是出现次数最多的值。需要比较注意的是，对于最后的一个元素，由于没有后续的值与其比较，所以要特殊考虑。

### C++实现

```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> nums;
        inorder(root,nums);
        vector<int> modes;
        if(!root) return modes;
        int cur=nums[0];
        int count=0,maxcount=0;
        for(int i=0;i<=nums.size()-1;i++){
            if(cur==nums[i])
                count++;
            if((nums[i+1]!=cur && count>=maxcount)||(i+1==nums.size() && count>=maxcount)){
                if(count>maxcount)
                    modes.clear();
                modes.push_back(cur);
                maxcount=count;
                count=0;
                cur=nums[i+1];
            }
            if((nums[i+1]!=cur) && count<maxcount){
                count=0;
                cur=nums[i+1];
            }
        }
        return modes;
    }
private:
    void inorder(TreeNode* root,vector<int>& nums){
        if(!root) return;
        inorder(root->left,nums);
        nums.push_back(root->val);
        inorder(root->right,nums);
    }
};
```