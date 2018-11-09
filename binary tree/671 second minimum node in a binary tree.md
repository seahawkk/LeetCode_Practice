## 671 二叉树中第二小的节点

* **题目来源：** [671 Second Minimum Node in a Binary Tree](https://leetcode-cn.com/problems/second-minimum-node-in-a-binary-tree/)

> **示例 1:**
>
> ```
> 输入: 
>     2
>    / \
>   2   5
>      / \
>     5   7
> 
> 输出: 5
> 说明: 最小的值是 2 ，第二小的值是 5 。
> ```
>
> **示例 2:**
>
> ```
> 输入: 
>     2
>    / \
>   2   2
> 
> 输出: -1
> 说明: 最小的值是 2, 但是不存在第二小的值。
> ```

**思路：** 求二叉树中第二小的结点思路和求二叉树中最小的结点的思路类似。由于题目中二叉树满足结点的值不大于其子结点的值，所以根结点的值一定是最小的，且结点值的大致趋势是递增的。需要做的只是利用递归，找到二叉树的左右子树中大于根结点的最小值。

### python实现

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findSecondMinimumValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root==None:
            return -1
        return self.minval(root,root.val)
    def minval(self,node,val):
        if node==None:
            return -1
        if node.val!=val:
            return node.val
        left=self.minval(node.left,val)
        right=self.minval(node.right,val)
        if left==-1:
            return right
        if right==-1:
            return left
        return min(left,right)
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
    int findSecondMinimumValue(TreeNode* root) {
        if (root==NULL) return -1;
        int ans=minval(root,root->val);
        return ans;
    }
private:
    int minval(TreeNode* node,int rootval){
        if (node==NULL) return -1;
        if (node->val!=rootval) return node->val;
        int left=minval(node->left,rootval),right=minval(node->right,rootval);
        if (left==-1) return right;
        if (right==-1) return left;
        return min(left,right);
    }
};
```

