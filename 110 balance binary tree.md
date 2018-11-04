## 110 平衡二叉树

* **题目来源：** [110 Balanced Binary Tree](https://leetcode-cn.com/problems/balanced-binary-tree/)

> 判断是否为高度平衡的二叉树：一个二叉树的每个结点的左右两个子树的高度差不超过1。
>
> **示例 1:**
>
> 给定二叉树 `[3,9,20,null,null,15,7]`
>
> ```
>     3
>    / \
>   9  20
>     /  \
>    15   7
> ```
>
> 返回 `true` 。
>
> **示例 2:**
>
> 给定二叉树 `[1,2,2,3,3,null,null,4,4]`
>
> ```
>        1
>       / \
>      2   2
>     / \
>    3   3
>   / \
>  4   4
> ```
>
> 返回 `false` 。

**思路：** 由于需要判断高度差，因此首先应该定义一个求出结点子树高度的函数，利用递归的思想，假设当结点的两个子树均为高度平衡的二叉树时，只需要保证两个子节点的高度差不超过1，就能确定该二叉树为高度平衡的二叉树。

### python实现

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root==None:
            return True
        if (self.isBalanced(root.left) and self.isBalanced(root.right) and                           abs(self.Depth(root.left)-self.Depth(root.right))<=1):
            return True
        return False
    def Depth(self,root):
        if(root==None):
            return 0
        return max(self.Depth(root.left),self.Depth(root.right))+1
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
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        if(isBalanced(root->left) && isBalanced(root->right) && abs(Depth(root->left)-Depth(root->right))<=1)
            return true;
        return false;
    }
    int Depth(TreeNode* root){
        return root==NULL ? 0 : max(Depth(root->left),Depth(root->right))+1;
    }
};
```

