## 21 合并两个有序链表

* **合并两个有序链表：**[题目来源：merge two sorted lists](https://leetcode-cn.com/problems/merge-two-sorted-lists/)

> 输入：1->2->4 , 1->3->4
>
> 输出：1->1->2->3->4->4

**开始的思路**：迭代的方法，对于链表L1，L2，将L2中的第一个结点cur2依次与L1中的结点cur1进行对比，使其位于合并链表的正确位置，之后排序时直接从该结点cur2 开始。

**python实现**

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1 == None:
            return l2
        if l2 == None:
            return l1
        cur1,cur2 = l1,l2
        while(cur2 != None):
            nex2 = cur2.next
            while(cur1 != None):
                nex1=cur1.next
                if ((cur1.val <= cur2.val and nex1 == None) or (cur1.val <=cur2.val <= nex1.val)):
                    cur1.next=cur2
                    cur2.next=nex1
                    break
                elif cur1.val > cur2.val:
                    cur2.next=cur1
                    break
                else:
                    cur1=nex1
            cur1=cur2
            cur2=nex2
        return l1 if l1.val <= l2.val else l2
```

所需时间代价较大时间大概68ms，用C++实现时更加复杂。



方法二：建立dummy head

```python
class Solution:
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1 == None:
            return l2
        if l2 == None:
            return l1
        dummy=cur=ListNode(-1)
        while l1 and l2:
            if l1.val <= l2.val:
                cur.next=l1
                l1=l1.next
            else:
                cur.next=l2
                l2=l2.next
            cur=cur.next
        cur.next=l1 if l1 else l2
        head=dummy.next
        return head
```

时间减少到44ms.



**迭代法C++实现**

```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;
        else if(l2 == NULL)
            return l1;
        else{
            if (l1->val <= l2->val){
                l1->next=mergeTwoLists(l1->next,l2);
                return l1;
            }
            else{
                l2->next=mergeTwoLists(l1,l2->next);
                return l2;
            }
            }
        }
};
```

时间代价大幅度减小。

