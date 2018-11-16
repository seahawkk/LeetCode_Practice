## 109 有序链表转换为二叉搜索树

* **题目来源：** [109 Convert Sorted List to Binary Search Tree](https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/)

> ```
> 给定的有序链表： [-10, -3, 0, 5, 9],
> 
> 一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：
> 
>       0
>      / \
>    -3   9
>    /   /
>  -10  5
> ```

**思路：** 本题的主题思路和**#108 有序数组转换为二叉搜索树#**是相同的，主要区别在于寻找中点作为根结点的方式上，对于链表而言，无法直接通过下标访问元素，所以需要定义一个寻找链表中点的函数，采用快慢指针的方式（slow、fast）确定中心点的位置和中点前一个节点的位置。这种寻找中点的方式在回文链表[234 Palindrome Linked List](https://leetcode-cn.com/problems/palindrome-linked-list/)中提到过。

### python实现

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        if head==None:return None
        if head.next==None:
            root=TreeNode(head.val)
            return root
        premid=self.findpremid(head)
        mid=premid.next
        premid.next=None
        root=TreeNode(mid.val)
        root.left=self.sortedListToBST(head)
        root.right=self.sortedListToBST(mid.next)
        return root
    def findpremid(self,head):
        if head==None:
            return None
        slow=head
        fast=head
        premid=head
        while fast.next!=None and fast.next.next!=None:
            premid=slow
            slow=slow.next
            fast=fast.next.next
        return premid
```

### C++实现

```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
private:
    ListNode* findmid(ListNode* head){
        if(!head) return NULL;
        ListNode* first=head;
        ListNode* pre=head;
        ListNode* second=head;
        while(second->next!=NULL && second->next->next!=NULL){
            pre=first;
            first=first->next;
            second=second->next->next;
        }
        return pre;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        if(head->next==NULL){
            TreeNode* root=new TreeNode(head->val);
            return root;
        }
        ListNode* premid=findmid(head);
        ListNode* mid=premid->next;
        TreeNode* root=new TreeNode(mid->val);
        premid->next=NULL;
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(mid->next);
        return root;
    }
};
```