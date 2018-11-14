## 230 二叉搜索树中第K小的元素

* **题目来源：** [230 Kth Smallest Element in a BST](https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/)

> ```
> 输入: root = [3,1,4,null,2], k = 1
>    3
>   / \
>  1   4
>   \
>    2
> 输出: 1
> 输入: root = [5,3,6,2,4,null,null,1], k = 3
>        5
>       / \
>      3   6
>     / \
>    2   4
>   /
>  1
> 输出: 3
> ```

**思路：** 首先由于二叉搜索树本身的性质，其中序遍历得到的是按照从小到大的有序排列，所以首先计算中序遍历后的列表，然后输出第K个元素即可。第二种中序遍历的方式是只需要遍历前K个元素，所需代价小于第一种方式。

### python实现

* 中序遍历

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        res=self.inOrderTraversal(root)
        return res[k-1]
    def inOrderTraversal(self,root):
        res=[]
        stack=[]
        pointer=root
        while(stack or pointer):
            if pointer:
                stack.append(pointer)
                pointer=pointer.left
            else:
                pointer=stack.pop()
                res.append(pointer.val)
                pointer=pointer.right
        return res
```

```python
class Solution:
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        self.count=0
        self.val=0
        self.inOrderTraversal(root,k)
        return self.val
    def inOrderTraversal(self,root,k):
        if root==None: return
        self.inOrderTraversal(root.left,k)
        self.count+=1
        if self.count==k:
            self.val=root.val
            return
        self.inOrderTraversal(root.right,k)
```

* 递归方法

```python
class Solution:
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        left=self.count(root.left)
        if left==k-1: return root.val
        if left>k-1: return self.kthSmallest(root.left,k)
        return self.kthSmallest(root.right,k-left-1)
    def count(self,node):
        if node==None: return 0
        return 1+self.count(node.left)+self.count(node.right)
```

