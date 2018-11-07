## 111 二叉树的最小深度

* **题目来源：** [111 Minimum Depth of Binary Tree](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/)

> 给定二叉树 `[3,9,20,null,null,15,7]`,
>
> ```
>     3
>    / \
>   9  20
>     /  \
>    15   7
> ```
>
> 返回它的最小深度  2.

**思路：** 首先考虑的是按照递归的方法解决，考虑最基本的情况即根结点为空和单结点。之后在假设给定二叉树的子树的最小深度已知的情况下，若想要得到正确的最小深度，只需要返回左右子树最小深度中较小的一个，再加一即可。需要注意的特殊情况是左右子树有某一个为空的情况。

### python实现

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root==None:
            return 0
        if root.left==None and root.right==None:
            return 1
        if root.left==None or root.right==None:
            return self.minDepth(root.left)+self.minDepth(root.right)+1
        return min(self.minDepth(root.left),self.minDepth(root.right))+1
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
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 1;
        if((root->right==NULL || root->left==NULL))
            return minDepth(root->left)+minDepth(root->right)+1;
        return min(minDepth(root->left),minDepth(root->right))+1;
    }
};
```

