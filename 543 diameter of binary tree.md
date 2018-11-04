## 543 二叉树的直径

* **题目来源：** [543 Diameter of Binary Tree](https://leetcode-cn.com/problems/diameter-of-binary-tree/)

> 给定二叉树
>
> ```
>           1
>          / \
>         2   3
>        / \     
>       4   5    
> ```
>
> 返回 **3**, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。
>
> **注意：**两结点之间的路径长度是以它们之间边的数目表示。

**思路：** 根据二叉树的直径的定义，直径长度为任意两点结点路径长度中的最大值，且有可能穿过根结点。所以可以分为两种情况考虑，当两个结点路径穿过根节点时（结点异侧），左右子树均取最大深度时，路径长度最大，即为二叉树直径。当结点在同一侧时，所求实际为左（右）子树的直径。

**更优的思路：** 如下面的`Java`实现。

### python实现

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root== None:
            return 0
        return max(self.diameterOfBinaryTree(root.left),
                   self.diameterOfBinaryTree(root.right),
                   self.Depth(root.left)+self.Depth(root.right))
    def Depth(self,root):
        if root == None:
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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root==NULL)
            return 0;
        return max(Depth(root->left)+Depth(root->right),
                   max(diameterOfBinaryTree(root->left),
                   diameterOfBinaryTree(root->right)));
    }
    int Depth(TreeNode* root){
        return root==NULL ? 0 : max(Depth(root->left),Depth(root->right))+1;
    }
};
```

###  Java实现

```Java
private int max = 0;

public int diameterOfBinaryTree(TreeNode root) {
    depth(root);
    return max;
}

private int depth(TreeNode root) {
    if (root == null) return 0;
    int leftDepth = depth(root.left);
    int rightDepth = depth(root.right);
    max = Math.max(max, leftDepth + rightDepth);
    return Math.max(leftDepth, rightDepth) + 1;
}
```

