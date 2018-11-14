## 669 修剪二叉查找树/二叉搜索树

**题目来源：** [669 Trim a Binary Search Tree](https://leetcode-cn.com/problems/trim-a-binary-search-tree/)

### python 实现（DFS详解）[链接](https://leetcode.com/problems/trim-a-binary-search-tree/discuss/158631/Python-DFS-tm)

```
> 类型：DFS分制
> Time Complexity O(N)
> Space Complexity O(1)
```

这题做法有些取巧，并不是真正意义上在内存里面删除不符合区间的Node，只是将Node的指向进行的更改，大致思路：

每一层的Condition有三种：

1. `root.val`小于区间的lower bound `L`，则返回`root.right` subtree传上来的`root`，这里就变相的'删除'掉了当前`root`和所有`root.left`的node
2. `root.val`大于区间的upper bound `R`，则返回`root.left` subtree传上来的`root`
3. 满足区间，则继续递归

当递归走到叶子节点的时候，我们向上返回`root`，这里`return root`的定义是：
返回给parent一个**区间调整完以后的subtree**

```python
#class TreeNode:
#	def __init__(self,x):
#		self.val = x
#		self.left = None
#		self.right = None
class Solution(object):
    def trimBST(self, root, L, R):
        # 每一层的Condition
        if not root: return root
        if root.val > R: return self.trimBST(root.left, L, R)
        if root.val < L: return self.trimBST(root.right, L, R)

        # 再区间内，正常的Recursion
        root.left = self.trimBST(root.left, L, R)
        root.right = self.trimBST(root.right, L, R)
        
        # 返回给parent一个区间调整完以后的subtree
        return root
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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(root==NULL) return NULL;
        if(root->val<L) return root=trimBST(root->right,L,R);
        if(root->val>R) return root=trimBST(root->left,L,R);
        root->left=trimBST(root->left,L,R);
        root->right=trimBST(root->right,L,R);
        return root;
    }
};
```

