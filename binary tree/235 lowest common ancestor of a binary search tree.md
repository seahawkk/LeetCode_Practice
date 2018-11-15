## 235 二叉搜索树的最近公共祖先

* **题目来源：** [235 Lowest Common Ancestor of a Binary Search Tree](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)

> 例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]
>
> ```
>         _______6______
>        /              \
>     ___2__          ___8__
>    /      \        /      \
>    0      _4       7       9
>          /  \
>          3   5
> ```
>
> **示例 1:**
>
> ```
> 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
> 输出: 6 
> 解释: 节点 2 和节点 8 的最近公共祖先是 6。
> ```
>
> **示例 2:**
>
> ```
> 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
> 输出: 2
> 解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。
> ```
>
> **说明:**
>
> - 所有节点的值都是唯一的。
> - p、q 为不同节点且均存在于给定的二叉搜索树中。

**思考：** 对于两个给定的结点，他们一定分别位于其最近公共祖先结点的左右子树上，考虑BST的性质，则结点值必定一个小于公共祖先，一个大于公共祖先。所以从根结点开始搜索，当两结点值均小于根结点值时，搜索其左子树，否则搜索其右子树。

*Just walk down from the whole tree's root as long as both p and q are in the same subtree (meaning their values are both smaller or both larger than root's). This walks straight from the root to the LCA, not looking at the rest of the tree, so it's pretty much as fast as it gets.*

### python实现

* 递归

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
        if (p.val<root.val and q.val<root.val): 
            return self.lowestCommonAncestor(root.left,p,q)
        if (p.val>root.val and q.val>root.val): 
            return self.lowestCommonAncestor(root.right,p,q)
        return root
```

* 迭代

```python
class Solution:
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        while (root.val-p.val)*(root.val-q.val)>0:
            if root.val>p.val:
                root=root.left
            else:
                root=root.right
        return root
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
        if(p->val<root->val && q->val<root->val)
            return lowestCommonAncestor(root->left,p,q);
        if(p->val>root->val && q->val>root->val)
            return lowestCommonAncestor(root->right,p,q);
        return root;
    }
};
```

