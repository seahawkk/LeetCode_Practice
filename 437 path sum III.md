## 437 路径总和 III

* **题目来源：** [437 Path Sum III](https://leetcode-cn.com/problems/path-sum-iii/)

> ```
> root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
> 
>       10
>      /  \
>     5   -3
>    / \    \
>   3   2   11
>  / \   \
> 3  -2   1
> 
> 返回 3。和等于 8 的路径有:
> 
> 1.  5 -> 3
> 2.  5 -> 2 -> 1
> 3.  -3 -> 11
> ```

**思路：** 首先，对于一个给定的二叉树，求其路径和等于给定值的路径总数。注意题目中描述的路径起点不一定过根结点，由此可以将求解过程分为两部分：1.起点过根结点；2.起点不过根结点。对于第一部分，由于过根结点已知，所以可以将问题转化为：求其左右子树中过左右根子结点的路径和等于给定值`sum`减去根结点值`root.val`的路径总数的问题，可以利用递归解决。对于第二部分，由于不过根结点，所以问题就转化为求左右子树中路径和等于给定值的路径总数的问题，依然可以用递归解决。最后返回两部分的和。

### python实现

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: int
        """
        if (root==None):
            return 0
        return self.pathSumStartWithRoot(root,sum)+self.pathSum(root.left,sum)+self.pathSum(root.right,sum)
    
    def pathSumStartWithRoot(self,root,sum):
        num=0
        if root==None:
            return 0
        if root.val==sum:
            num=num+1
        num+=self.pathSumStartWithRoot(root.left,sum-root.val)+self.pathSumStartWithRoot(root.right,sum-root.val)
        return num
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
    int pathSum(TreeNode* root, int sum) {
        if (root==NULL) return 0;
        return pathSum(root->left,sum)+pathSum(root->right,sum)+pathSumStartWithRoot(root,sum);
    }
    
    int pathSumStartWithRoot(TreeNode* root,int sum){
        int num=0;
        if(root==NULL) return 0;
        if(root->val==sum) num++;
        num+=pathSumStartWithRoot(root->left,sum-root->val)+pathSumStartWithRoot(root->right,sum-root->val);
        return num;
    }
};
```

**更多解法：**[leetcode discuss](https://leetcode.com/problems/path-sum-iii/discuss/)

