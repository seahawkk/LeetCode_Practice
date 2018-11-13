## 145 二叉树的后序遍历

* **题目来源：** [145 Binary Tree Postorder Traversal](https://leetcode-cn.com/problems/binary-tree-postorder-traversal/)

> ```
> 输入: [1,null,2,3]  
>    1
>     \
>      2
>     /
>    3 
> 输出: [3,2,1]
> ```

**思路：** 一种很巧妙的方式，前序遍历是root-left-right，中序遍历是left-root-right，后续遍历是left-right-root，由此可以看出，当我们在进行前序遍历时，假如将遍历的顺序改为root-right-left(在用stack实现时，实际就是将放入堆栈的由右子结点改变为左子结点)，然后再翻转输出，就能得到left-right-root，即后续遍历。[参照](https://leetcode.com/problems/binary-tree-postorder-traversal/discuss/45559/My-Accepted-code-with-explaination.-Does-anyone-have-a-better-idea)

pre-order traversal is **root-left-right**, and post order is **left-right-root**. modify the code for pre-order to make it root-right-left, and then **reverse** the output so that we can get left-right-root .

1. Create an empty stack, Push root node to the stack.

2. Do following while stack is not empty.

   2.1. pop an item from the stack and print it.

   2.2. push the left child of popped item to stack.

   2.3. push the right child of popped item to stack.

3. reverse the ouput.

### python实现

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        res=[]
        stack=[root]
        if root==None:
            return res
        while(stack):
            res.append(root.val)
            if root.left:
                stack.append(root.left)
            if root.right:
                root=root.right
            else:
                root=stack.pop()
        return res[::-1]
```

### C++实现

* 迭代

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> aStack;
        TreeNode* pointer=root;
        aStack.push(NULL);
        if(!root) return res;
        while(!aStack.empty()){
            res.insert(res.begin(),pointer->val);
            if(pointer->left) aStack.push(pointer->left);
            if(pointer->right)
                pointer=pointer->right;
            else{
                pointer=aStack.top();
                aStack.pop();
            }
        }
        return res;
    }
};
```

* 递归

```C++
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        vector<int> left;
        vector<int> right;
        if(!root) return res;
        left=postorderTraversal(root->left);
        right=postorderTraversal(root->right);
        res.insert(res.end(),left.begin(),left.end());
        res.insert(res.end(),right.begin(),right.end());
        res.push_back(root->val);
        return res;
    }
};
```

