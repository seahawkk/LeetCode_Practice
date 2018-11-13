## 二叉树的前序遍历

* **题目来源：** [144 binary tree preorder traversal](https://leetcode-cn.com/problems/binary-tree-preorder-traversal/)

> ```
> 输入: [1,null,2,3]  
>    1
>     \
>      2
>     /
>    3 
> 
> 输出: [1,2,3]
> ```

**思路：** 分别采用递归和迭代的方法解决，采用迭代时通过栈stack临时存放二叉树的右结点，当二叉树没有左子结点可以访问时，从栈顶弹出结点。

## python实现

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        res=[]
        stack=[root]
        if root==None:
            return res
        while(len(stack)):
            res.append(root.val)
            if root.right:
                stack.append(root.right)
            if root.left:
                root=root.left
            else:
                root=stack.pop()
        return res
```

## C++实现

* 递归

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> tree,left,right;
        if(root!=NULL){
            tree.push_back(root->val);
            left=preorderTraversal(root->left);
            right=preorderTraversal(root->right);
            tree.insert(tree.end(),left.begin(),left.end());
            tree.insert(tree.end(),right.begin(),right.end());
        }
        return tree;
    }
};
```

* 迭代

```C++
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode* > aStack;
        vector<int> res;
        if(!root) return res;
        TreeNode* pointer=root;
        aStack.push(NULL);//栈底监视哨
        while(!aStack.empty()){
            res.push_back(pointer->val);
            if(pointer->right)
                aStack.push(pointer->right);
            if(pointer->left)
                pointer=pointer->left;
            else{
                pointer=aStack.top();
                aStack.pop();
            }
        }
        return res;
    }
};
```

