## 236 二叉树的最近公共祖先

* **题目来源：** [236 Lowest Common Ancestor of a Binary Tree](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/)

> 给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]
>
> ```
>         _______3______
>        /              \
>     ___5__          ___1__
>    /      \        /      \
>    6      _2       0       8
>          /  \
>          7   4
> ```
>
> **示例 1:**
>
> ```
> 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
> 输出: 3
> 解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
> ```
>
> **示例 2:**
>
> ```
> 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
> 输出: 5
> 解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
> ```
>
> **说明:**
>
> - 所有节点的值都是唯一的。
> - p、q 为不同节点且均存在于给定的二叉树中。

**思路：** 对于二叉搜索树的LCA(最近公共祖先)问题，我们可以利用二叉搜索树的性质来判断两个结点相对于给定根结点的位置，是位于根结点的同一子树还是不同子树，从根结点开始逐渐向子结点判断，当两个结点位于不同子树时，返回此时的父节点，即为所求。

对于二叉树问题，无法直接通过结点值的比较来判断两个结点相对于根结点的位置，只有通过DFS来寻找结点，判断两个结点位于相同子树还是不同子树，进行判断。

### python实现

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        if not root:
            return None
        if root==p or root==q:
            return root          # 判断树中是否存在p或q结点
        left=self.lowestCommonAncestor(root.left,p,q)  # 对左子树判断
        right=self.lowestCommonAncestor(root.right,p,q) # 对右子树判断
        if left and right:
            return root   # 如果左右子树均能找到结点值，则root就是最近祖先
        if left:
            return left  # 否则在左子树寻找返回
        else:
            return right
```

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q) return root;
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(left && right) return root;
        return left ? left : right;
    }
};
```

