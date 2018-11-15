## 538 把二叉搜索树转换为累加树

* **题目来源：** [538 Convert BST to Greater Tree](https://leetcode-cn.com/problems/convert-bst-to-greater-tree/)

> ```
> 输入: 二叉搜索树:
>               5
>             /   \
>            2     13
> 使原来的结点值是原来的结点值加上所有大于它的结点值之和
> 输出: 转换为累加树:
>              18
>             /   \
>           20     13
> ```

**思路总结：** 首先由于涉及到对二叉树搜索树中所有大于它的结点值求和，所有采用递归的方式是来逐层求和的方式是比较容易想到的。假如在对结点值进行转换时从左子树开始，则必然会有一部分二叉搜索树的结点需要被重复计算结点值，这将增大运算的时间代价。当按照右子树，当前结点，左子树的顺序转换时，后者可以直接利用前者转换后的数据，且其转换值就是：前者的转换值加当前结点原有值。

### python实现

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def convertBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        self.sum=0
        self.traversal(root)
        return root
    def traversal(self,node):
        if node==None: return
        self.traversal(node.right)
        self.sum+=node.val
        node.val=self.sum
        self.traversal(node.left)
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
    int sum=0;
public:
    TreeNode* convertBST(TreeNode* root) {
        traversalSum(root);
        return root;
    }
private:
    void traversalSum(TreeNode* node){
        if(node==NULL) return;
        traversalSum(node->right);
        sum+=node->val;
        node->val=sum;
        traversalSum(node->left);
    }
};
```

