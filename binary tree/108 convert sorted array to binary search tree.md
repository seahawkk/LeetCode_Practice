## 108 将有序数组转换为二叉搜索树

* **题目来源：** [108 Convert Sorted Array to Binary Search Tree](https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/)

> ```
> 给定有序数组: [-10,-3,0,5,9],
> 
> 一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
> 
>       0
>      / \
>    -3   9
>    /   /
>  -10  5
> ```

**思路：** 对于一个高度平衡的二叉搜索树，其中序遍历是有序数组，且左右两个子树的高度差的绝对值不超过1，因此，选取有序数组的中点作为根结点，就能满足个高度平衡的条件；将数组的前半部分划分为左子树，后半部分划分为为右子树，就能够满足二叉搜索树的左子树的值均小于根结点，右子树的值均大于根结点的条件，然后再对左右子树采用相同的方式递归分治。

### python实现

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        if not nums:
            return None
        mid=len(nums)//2
        root=TreeNode(nums[mid])
        root.left=self.sortedArrayToBST(nums[0:mid])
        root.right=self.sortedArrayToBST(nums[mid+1:])
        return root
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return NULL;
        int mid=nums.size()/2;
        TreeNode* root=new TreeNode(nums[mid]);
        vector<int> leftarray(nums.begin(),nums.begin()+mid);
        vector<int> rightarray(nums.begin()+mid+1,nums.end());
        root->left=sortedArrayToBST(leftarray);
        root->right=sortedArrayToBST(rightarray);
        return root;
    }
};
```

