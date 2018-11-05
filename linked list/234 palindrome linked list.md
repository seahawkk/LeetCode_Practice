## 234 回文链表

* **题目来源：** [234 Palindrome Linked List](https://leetcode-cn.com/problems/palindrome-linked-list/)

>**Example 1:**
>
>```
>Input: 1->2
>Output: false
>```
>
>**Example 2:**
>
>```
>Input: 1->2->2->1
>Output: true
>```
>
>**Follow up:**
>Could you do it in O(n) time and O(1) space

**思路：**  数据以链表的形式存储时，由于不存在下标，也就意味着寻找数据的中点相对困难，因此使用快慢指针的方式显得格外便捷。

1.首先设置两个指针slow和fast置于表头head，slow指针每次移动一步，fast指针每次移动两步；

2.当链表中结点数为偶数时，fast指针无法移动时(此时位于倒数第二个结点)，slow指针刚好指向对称的中点位置，当链表中结点数为奇数时，fast指针指向最终结点时，slow指向中间结点。

之后可以通过将从中点位置开始的链表反转并与前半部分链表对比来判断是否为回文链表。

### python 实现

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if (head == None or head.next == None):
            return True
        slow=head
        fast=head
        while (fast.next != None and fast.next.next != None):
            slow=slow.next
            fast=fast.next.next
        slow=self.reverseLinkedlist(slow.next)
        while(slow != None):
            if slow.val != head.val:
                return False
            slow=slow.next
            head=head.next
        return True
    def reverseLinkedlist(self,head):
        dummyhead=None
        pre=dummyhead
        cur=head
        while(cur != None):
            nex=cur.next
            cur.next=pre
            pre=cur
            cur=nex
        return pre
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
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head,*fast=head;
        if(head==NULL || head->next==NULL)
            return true;
        while(fast->next != NULL && fast->next->next != NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow=reverselist(slow->next);
        while(slow != NULL){
            if(slow->val != head->val)
                return false;
            slow=slow->next;
            head=head->next;
        }
        return true;
        
    }
    ListNode *reverselist(ListNode *head){
        ListNode *pre=NULL,*cur=head;
        ListNode *nex=head->next;
        while(cur != NULL){
            nex=cur->next;
            cur->next=pre;
            pre=cur;
            cur=nex;
        }
        return pre;
    }
};
```

