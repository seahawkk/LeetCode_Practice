## 104 二叉树的最大深度

* **题目来源：** [104 Maximum Depth of Binary Tree](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/) 

> 给定二叉树 [3,9,20,null,null,15,7]
>
> ```
>     3
>    / \
>   9  20
>     /  \
>    15   7
> ```
>
> 返回它的最大深度 3 。

**思路：** 主要是利用递归的思想，利用深度优先遍历搜索（DFS），若想求得二叉树的最大深度，只需要求得其左右子树的最大深度，选择较深的子树深度加一。

### 递归的思想

**1.递归的思考方式**

> 1.当n=0, 1的时候, 结果正确.
>
> 2.假设函数对于n是正确的, 函数对n+1结果也正确.
> 如果这两点是成立的，我们知道这个函数对于所有可能的n都是正确的.

这种方法很像数学归纳法，也是递归的正确思考方式。

**2.如何找到一个问题的递归算法**

> 1.你必须要示范如何解决问题的一般情况, 通过将问题切分成有限小并更小的子问题.
> 你必须要示范如何通过有限的步骤, 来解决最小的问题(基本用例).
>
> 2.如果这两件事完成了, 那问题就解决了. 因为递归每次都将问题变得更小, 而一个有限的问题终究会被解决的, 而最小的问题仅需几个有限的步骤就能解决.

参考：[写递归函数的正确思维方法](https://blog.csdn.net/vagrxie/article/details/8470798)

### python实现

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root == None:
            return 0
        return max(self.maxDepth(root.left),self.maxDepth(root.right))+1
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
    int maxDepth(TreeNode* root) {
        return root==NULL ? 0 : max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};
```