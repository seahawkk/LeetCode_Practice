## 94 二叉树的中序遍历

* **题目来源：** [94 Binary Tree Inorder Traversal](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)

> ```
> 输入: [1,null,2,3]
>    1
>     \
>      2
>     /
>    3
> 
> 输出: [1,3,2]
> ```

**思考：** 二叉树中序遍历的非递归实现：同前序遍历和后序遍历一样，利用栈来实现。首先访问的根结点，将根结点入栈，然后访问左子树，如果没有左子树，则从栈中弹出一个结点，访问结点值，最后访问右子树。

### C++实现

* 递归实现

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        vector<int> left;
        vector<int> right;
        if(!root) return res;
        if(root->left) left=inorderTraversal(root->left);
        res.insert(res.end(),left.begin(),left.end());
        res.push_back(root->val);
        if(root->right) right=inorderTraversal(root->right);
        res.insert(res.end(),right.begin(),right.end());
        return res;
    }
};
```

* 非递归实现

```C++
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> aStack;
        TreeNode* pointer=root;
        while(!aStack.empty() || pointer){
            if(pointer){
                aStack.push(pointer);
                pointer=pointer->left;
            }
            else{
                pointer=aStack.top();
                aStack.pop();
                res.push_back(pointer->val);
                pointer=pointer->right;
            }
        }
        return res;
    }
};
```

