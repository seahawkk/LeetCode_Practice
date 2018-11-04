## 617 合并二叉树

* **题目来源：** [617 Merge Two Binary Trees](https://leetcode-cn.com/problems/merge-two-binary-trees/)

> ```
> 输入: 
> 	Tree 1                     Tree 2                  
>           1                         2                             
>          / \                       / \                            
>         3   2                     1   3                        
>        /                           \   \                      
>       5                             4   7                  
> 输出: 
> 合并后的树:
> 	     3
> 	    / \
> 	   4   5
> 	  / \   \ 
> 	 5   4   7
> ```
>
> **注意:** 合并必须从两个树的根节点开始。

**思路：** 在解决问题的过程中，每个二叉树的各个结点的子树均需要解决合并的问题，且合并后的子树将作为一个整体返回，因此考虑用递归来解决。在利用递归思想解决时，首先保证最简单的情况成立，然后把问题拆解成子问题，在解决子问题成立的情况下，保证主问题成立，有些数学归纳法的思想。例如本问题，可以假设左右子树为合并二叉树已经成立，在此基础上思考问题，使父二叉树合并。

### python实现

```python
class Solution:
    def mergeTrees(self, t1, t2):
        """
        :type t1: TreeNode
        :type t2: TreeNode
        :rtype: TreeNode
        """
        if (t1==None and t2==None): return None
        if (t1!=None and t2==None): return t1
        if (t1==None and t2!=None): return t2
        root=TreeNode(t1.val+t2.val)
        root.left=self.mergeTrees(t1.left,t2.left)
        root.right=self.mergeTrees(t1.right,t2.right)
        return root  
```

### C++实现

```C++
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1==NULL && t2==NULL) return NULL;
        if(t1==NULL && t2!=NULL) return t2;
        if(t1!=NULL && t2==NULL) return t1;
        TreeNode* root=new TreeNode(t1->val+t2->val);
        root->left=mergeTrees(t1->left,t2->left);
        root->right=mergeTrees(t1->right,t2->right);
        return root;
    }
};
```





