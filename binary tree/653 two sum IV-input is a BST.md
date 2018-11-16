## 653 两数之和IV - 输入BST

* **题目来源：**[653 Two Sum IV - Input is a BST](https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst/)

> ```
> 输入: 
>     5
>    / \
>   3   6
>  / \   \
> 2   4   7
> 
> Target = 9
> 
> 输出: True
> ```
>
> ```
> 输入: 
>     5
>    / \
>   3   6
>  / \   \
> 2   4   7
> 
> Target = 28
> 
> 输出: False
> ```

**思路：** 利用中序遍历将二叉搜索树转换为有序列表，然后再利用双指针从数组的头尾进行查找。

### python实现

```python
class Solution:
    def findTarget(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: bool
        """
        res=self.inorder(root)
        i=0
        j=len(res)-1
        while(i<j):
            if res[i]+res[j]==k:
                return True
            if res[i]+res[j]<k:
                i+=1
            else:
                j-=1
        return False
    def inorder(self,root):
        res=[]
        if root!=None:
            res+=self.inorder(root.left)
            res.append(root.val)
            res+=self.inorder(root.right)
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
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root,nums);
        for(int i=0,j=nums.size()-1;i<j;){
            int sum=nums[i]+nums[j];
            if(sum==k) return true;
            if(sum<k)
                i++;
            else
                j--;
        }
        return false;
    }
private:
    void inorder(TreeNode* node,vector<int>& nums){       //注意将vector作为参数引用
        if(!node) return;
        inorder(node->left,nums);
        nums.push_back(node->val);
        inorder(node->right,nums);
        }
};
```