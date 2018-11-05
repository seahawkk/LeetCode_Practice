## 翻转二叉树

* **题目来源：** [226 Invert Binary Tree](https://leetcode-cn.com/problems/invert-binary-tree/)

> 输入：
>
> ```
>      4
>    /   \
>   2     7
>  / \   / \
> 1   3 6   9
> ```
>
> 输出：
>
> ```
>      4
>    /   \
>   7     2
>  / \   / \
> 9   6 3   1
> ```

**思考：** 由于对二叉树的每个结点的左右子树均进行翻转操作，因此可以考虑使用递归的思想。将根的左右子结点的指针互换，指向新的子树，同时新的子树也满足翻转操作。需要注意的是在指针互换时，要注意指针地址信息的保护，防止信息丢失。

### python实现

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if root== None:
            return root
        left=root.left
        root.left=self.invertTree(root.right)
        root.right=self.invertTree(left)
        return root
```

### C++

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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return root;
        TreeNode* left=root->left;
        root->left=invertTree(root->right);
        root->right=invertTree(left);
        return root;
    } 
};
```

