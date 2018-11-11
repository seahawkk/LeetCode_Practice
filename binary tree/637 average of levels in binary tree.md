## 637 二叉树的层平均值

* **题目来源：** [637 Average of Levels in Binary Tree](https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/)

> ```
> 输入:
>     3
>    / \
>   9  20
>     /  \
>    15   7
> 输出: [3, 14.5, 11]
> 解释:
> 第0层的平均值是 3,  第1层是 14.5, 第2层是 11. 因此返回 [3, 14.5, 11].
> ```

**思考：** 使用BFS算法，通过创建一个队列来保存二叉树结点，上层结点从队首弹出的同时，该结点的左右子结点入队。从而可以求出每层的结点的平均值。也可以建立两个队列，分别存放上层结点与下层结点。

### python实现

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def averageOfLevels(self, root):
        """
        :type root: TreeNode
        :rtype: List[float]
        """
        res=[]
        q=[root]
        while q:
            new_q=[]
            sum=0
            n=0
            while q:
                node=q.pop()
                if node.left: new_q.append(node.left)
                if node.right: new_q.append(node.right)
                sum+=node.val
                n+=1
            res.append(float(sum)/n)
            q=new_q
        return res
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            long sum=0;
            int s=q.size();
            for(int i=1;i<=s;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                sum+=node->val;  
            }
            res.push_back((double)sum/s);
        }
        return res;
    }
};
```



