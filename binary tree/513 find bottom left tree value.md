## 找到树左下角的值

* **题目来源：** [513 Find Bottom Left Tree Value](https://leetcode-cn.com/problems/find-bottom-left-tree-value/)

> **示例 1:**
>
> ```
> 输入:
>     2
>    / \
>   1   3
> 输出:
> 1
> ```
>
> **示例 2:**
>
> ```
> 输入:
>         1
>        / \
>       2   3
>      /   / \
>     4   5   6
>        /
>       7
> 输出:
> 7
> ```
>
>  **注意:** 您可以假设树（即给定的根节点）不为 **NULL**。

**思考：** 第一种思路是和637中方法一样类似，将结点的左右子结点从队尾插入，然后将父节点从队首弹出，不同的是注意的是当队列中的结点都在同一层时，保存好队首的结点。最终返回最后一层的队首结点就可以了。

**第二种思路则要简单的多(right-to-left思想）：比较巧妙的是在将左右子结点插入队列时，先将右子结点入队，再将左子结点入队，这样只需要重复执行插入队首父节点的右左子结点、弹出队首结点的操作，最后的结点就是左下的结点，运算也更快。**

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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* leftnode=root;
        while(!q.empty()){
            leftnode=q.front();
            int num=q.size();
            for(int i=1;i<=num;i++){
                TreeNode* node=q.front();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                q.pop();
            }
        }
        return leftnode->val;
    }
};
```

```C++
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            root=q.front();
            if(root->right) q.push(root->right);
            if(root->left) q.push(root->left);
            q.pop();
            }
        return root->val;
    }
};
```

### python实现

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def findBottomLeftValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        q=[root]
        while q:
            first=q.pop(0)
            if first.right:
                q.append(first.right)
            if first.left:
                q.append(first.left)
        return first.val
```

