## 404 左叶子之和

* **题目来源：** [404 Sum of Left Leaves](https://leetcode-cn.com/problems/sum-of-left-leaves/description/)

> 计算给定二叉树的所有左叶子之和。
>
> **示例：**
>
> ```
>     3
>    / \
>   9  20
>     /  \
>    15   7
> 
> 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
> ```

**思考：** 利用递归解决。从最基本的二叉树结构分析需要考虑的情况，首先讨论根结点为空；由于是要求给定二叉树左子叶的和，所以从左子叶是否存在分开讨论。之后再拓展至一般情形。

### python实现

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root==None:
            return 0
        if root.left==None:
            return self.sumOfLeftLeaves(root.right)
        if root.left.left==None and root.left.right==None:
            return root.left.val+self.sumOfLeftLeaves(root.right)
        return self.sumOfLeftLeaves(root.left)+self.sumOfLeftLeaves(root.right)
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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left==NULL) return sumOfLeftLeaves(root->right);
        if (root->left->left==NULL && root->left->right==NULL)
            return root->left->val+sumOfLeftLeaves(root->right);
        return sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
    }
};
```

