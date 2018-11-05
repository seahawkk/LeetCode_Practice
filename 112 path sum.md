## 112 路径求和

* **题目来源：** [112 Path Sum](https://leetcode-cn.com/problems/path-sum/)

> 给定如下二叉树，以及目标和 `sum = 22`，
>
> ```
>               5
>              / \
>             4   8
>            /   / \
>           11  13  4
>          /  \      \
>         7    2      1
> ```
>
> 返回 `true`, 因为存在目标和为 22 的根节点到叶子节点的路径 `5->4->11->2`。

**思路：** 利用递归的思想，判断是否存在路径满足路径上结点和等于目标和，实际就是判断给定二叉树的左右子树上是否存在路径满足路径上结点和等于目标和减去根结点的值。根据递归的思想，同样先判断树的结点为空和单结点的情况，然后再在假设左右子树成立的前提下思考问题。

### python实现

```python
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        if root==None:
            return False
        if root.left==None and root.right==None:
            return(root.val==sum)
        return(self.hasPathSum(root.left,sum-root.val) or self.hasPathSum(root.right,sum-root.val))
```

### C++实现

```C++
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return false;
        if(root->left==NULL and root->right==NULL)
            return (root->val==sum);
        return (hasPathSum(root->left,sum-root->val) || hasPathSum(root->right,sum-root->val));
    }
};
```