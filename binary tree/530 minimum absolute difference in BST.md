## 530 二叉搜索树的最小绝对差

* **题目来源：** [530 Minimum Absolute Difference in BST](https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/)

> ```
> 输入:
>    1
>     \
>      3
>     /
>    2
> 输出:
> 1
> ```

**思路：** 利用中序遍历将二叉搜索树转换为有序列表，再比较最小绝对差值。

### python实现

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getMinimumDifference(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        nums=[]
        self.inorder(root,nums)
        mindiff=abs(nums[0]-nums[1])
        for i in range(len(nums))[2:]:
            j=i-1
            diff=abs(nums[j]-nums[i])
            if mindiff>=diff:
                mindiff=diff
        return mindiff
    def inorder(self,root,nums):
        if root==None:
            return
        self.inorder(root.left,nums)
        nums.append(root.val)
        self.inorder(root.right,nums)
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
    int getMinimumDifference(TreeNode* root) {
        vector<int> nums;
        inorder(root,nums);
        int mindiff=abs(nums[0]-nums[1]);
        for(int i=1,j=2;i<nums.size()-1;i++,j++){
            int diff=abs(nums[i]-nums[j]);
            if(mindiff>=diff)
                mindiff=diff;
        }
        return mindiff;
    }
private:
    void inorder(TreeNode* root,vector<int>& nums){
        if(!root) return;
        inorder(root->left,nums);
        nums.push_back(root->val);
        inorder(root->right,nums);
    }
};
```

