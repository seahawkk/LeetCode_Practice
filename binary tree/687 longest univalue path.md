## 最长同值路径

* **题目来源：** [687 Longest Univalue Path](https://leetcode-cn.com/problems/longest-univalue-path/)

> 给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。
>
> **注意**：两个节点之间的路径长度由它们之间的边数表示。
>
> 输入:
>
> ```
>               5
>              / \
>             4   5
>            / \   \
>           1   1   5
> ```
>
> 输出:
>
> ```
> 2
> ```
>
> 输入:
>
> ```
>               1
>              / \
>             4   5
>            / \   \
>           4   4   5
> ```
>
> 输出:
>
> ```
> 2
> ```
>
> **注意:** 给定的二叉树不超过10000个结点。 树的高度不超过1000。

**思考：** 受到题目中“路径可以经过也可以不经过根结点”这句话影响，看到题目的第一想法是将题目分成求经过结点的最长同值路径和不经过结点（也就是左右子树的最长路径中最大值）两种情况讨论，实现起来是比较麻烦的。实际上，只需要定义一个求二叉树根结点为起点的最长同值路径的递归函数即可，求出根结点的左子树侧和右子树侧的最长同值路径的和（这种定义已经包含了只有单侧存在同值路径的情况），然后利用递归，与根结点父二叉树的两侧同值路径和对比，将较大值赋给一个全局变量，直至递归至题目中给定根结点。

### python实现

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def longestUnivaluePath(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.res = 0
        def dir_length(node):
            if not node:
                return 0                         #注意：必须先递归，再判断。
            left_len = dir_length(node.left)     # 左节点的length
            right_len = dir_length(node.right)   # 右节点的length
            left_dir, right_dir = 0, 0
            if node.left and node.left.val == node.val:
                left_dir = left_len + 1          # 当前节点的左节点方向的length
            if node.right and node.right.val == node.val:
                right_dir = right_len + 1        # 当前节点的右边节点方向的length
            self.res = max(self.res, left_dir + right_dir)
            return max(left_dir, right_dir)
        dir_length(root)
        return self.res
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
    int path=0;
public:
    int longestUnivaluePath(TreeNode* root) {
        Dfs(root);
        return path;
    }
    int Dfs(TreeNode* root){
        if(root==NULL) return 0;
        int lefttree=Dfs(root->left);
        int righttree=Dfs(root->right);
        int leftpath=root->left!=NULL && root->val==root->left->val ? lefttree+1 : 0;
        int rightpath=root->right!=NULL && root->val==root->right->val ? righttree+1 :0;
        path=max(path,leftpath+rightpath);
        return max(leftpath,rightpath);
    }
};
```

