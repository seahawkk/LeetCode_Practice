## 24 两两交换链表中的结点

* **题目来源：** [24 Swap Nodes in Pairs](https://leetcode-cn.com/problems/swap-nodes-in-pairs/)

> 输入：1->2->3->4
>
> 输出： 2->1->4->3

**思路：** 本题的思路依然是借助`dummy head`求解。然后通过迭代的方式两两交换链表中的结点。需要注意的是结点总数可能为奇数或偶数。

 ### python实现

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        dummyhead = ListNode(-1)
        dummyhead.next = head
        cur = dummyhead
        while(cur.next != None and cur.next.next != None):
            first = cur.next
            second = first.next
            cur.next = second
            first.next=second.next
            second.next=first
            cur=first
        return dummyhead.next
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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode *cur = dummyhead,*first=head,*second=head;
        while(cur->next != NULL && cur->next->next != NULL){
            first = cur->next;
            second = first->next;
            cur->next = second;
            first->next =second->next;
            second->next=first;
            cur=first;
        }
        return dummyhead->next;
    }
};
```

