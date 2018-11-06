## 572 另一个树的子树

* **题目来源：** [Subtree of Another Tree](https://leetcode-cn.com/problems/subtree-of-another-tree/)

> **示例 1:**
> 给定的树 s:
>
> ```
>      3
>     / \
>    4   5
>   / \
>  1   2
> ```
>
> 给定的树 t：
>
> ```
>    4 
>   / \
>  1   2
> ```
>
> 返回 **true**，因为 t 与 s 的一个子树拥有相同的结构和节点值。
>
> **示例 2:**
> 给定的树 s：
>
> ```
>      3
>     / \
>    4   5
>   / \
>  1   2
>     /
>    0
> ```
>
> 给定的树 t：
>
> ```
>    4
>   / \
>  1   2
> ```
>
> 返回 **false**。

**思路：** 首先考虑到的是既然涉及到子树与给定二叉树是否相同的判断，所以定义一个判断两个二叉树是否相同的函数也就理所当然。然后从给定二叉树`s` 的根结点开始，并延伸至左右子树，逐个与二叉树`t` 比较，输出结果。

### python实现

```python
class Solution:
    def isSubtree(self, s, t):
        """
        :type s: TreeNode
        :type t: TreeNode
        :rtype: bool
        """
        if s==None:
            return False
        return self.equalTree(s,t) or self.isSubtree(s.left,t) or self.isSubtree(s.right,t)
    def equalTree(self, s ,t):
        if s==None and t==None:
            return True
        if s==None or t==None:
            return False
        if s.val!=t.val:
            return False
        return self.equalTree(s.left,t.left) and self.equalTree(s.right,t.right)
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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s==NULL) return false;
        return equalTree(s,t) || isSubtree(s->left,t) || isSubtree(s->right,t);
    }
    bool equalTree(TreeNode* s, TreeNode* t){
        if(s==NULL && t==NULL) return true;
        if(s==NULL || t==NULL) return false;
        if(s->val != t->val) return false;
        return equalTree(s->left,t->left) && equalTree(s->right,t->right);
            
    }
};
```

