## 83 从有序链表删除重复节点

**题目来源：** [83. Remove Duplicates from Sorted List ](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/) 

> 输入：1->1->2->3->3->4
>
> 输出：1->2->3->4

**思路：** 首先判断头结点head是否为空即其是否为单结点链表，如果是则直接输出head，否则进行下面的删除结点操作。重复节点的删除主要是通过移动结点指针的方式。对于三个链表结点cur->nex->nexnex，若cur和nex相同，则令cur的指针指向nexnex，即变为cur->nexnex，否则将判断结点指针移动至nex，继续上述操作。

### python实现

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None or head.next == None:
            return head
        else:
            cur=head
            while(cur.next != None):
                nex=cur.next
                if cur.val == nex.val:
                    cur.next=nex.next
                else:
                    cur=nex
            return head
```

执行用时：76ms。

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        else{
            ListNode *cur=head,*nex;
            while(cur->next != NULL){
                nex=cur->next;
                if(cur->val == nex->val)
                    cur->next=nex->next;
                else
                    cur=nex;
            }
            return head;
            }
    }
        
};
```

执行用时：8ms。