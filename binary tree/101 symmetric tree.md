## 对称二叉树

* **题目来源：** [101 Symmetric Tree](https://leetcode-cn.com/problems/symmetric-tree/)

> 给定一个二叉树，检查它是否是镜像对称的。
>
> 例如，二叉树 `[1,2,2,3,4,4,3]` 是对称的。
>
> ```
>     1
>    / \
>   2   2
>  / \ / \
> 3  4 4  3
> ```
>
> 但是下面这个 `[1,2,2,null,3,null,3]` 则不是镜像对称的:
>
> ```
>     1
>    / \
>   2   2
>    \   \
>    3    3
> ```

**思路：** 仍然是利用递归的思想，由于根结点只有一个，没有可以比较的对称项，因此从其左右子结点开始判断。发现镜像对称规律总是将两个对称结点`t1`/`t2`的相反子结点比较，从而在对开始结点做出判断的基础上，利用这个性质逐层对子孙结点进行递归比较。

### python实现

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root==None:
            return True
        return self.isMirror(root.left,root.right)
    def isMirror(self,t1,t2):
        if t1==None and t2==None:
            return True
        if t1==None or t2==None:
            return False
        if t1.val!=t2.val:
            return False
        return self.isMirror(t1.left,t2.right) and self.isMirror(t1.right,t2.left)
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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return isMirror(root->left,root->right);
    }
    bool isMirror(TreeNode* t1,TreeNode* t2){
        if(t1==NULL && t2==NULL) return true;
        if(t1==NULL || t2==NULL) return false;
        if(t1->val!=t2->val) return false;
        return isMirror(t1->left,t2->right) && isMirror(t1->right,t2->left);
    }
};
```

