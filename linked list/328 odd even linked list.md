## 328 奇偶链表

* **题目来源：** [328 Odd Even Linked List](https://leetcode-cn.com/problems/odd-even-linked-list/)

> 示例 1:
>
> 输入: 1->2->3->4->5->NULL
> 输出: 1->3->5->2->4->NULL
> 示例 2:
>
> 输入: 2->1->3->5->6->4->7->NULL 
> 输出: 2->3->6->7->1->5->4->NULL
> 说明:
>
> 应当保持奇数节点和偶数节点的相对顺序。
> 链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。

**思路：**  `odd->next=odd->next->next; odd=odd->next `

​                  `even->next=even->next->next;even=even->next`

### C++实现

```c++
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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)
            return head;
        ListNode *odd=head,*even=head->next,*evenhead=even;
        while(even != NULL && even->next != NULL){
            odd->next=odd->next->next;
            odd=odd->next;
            even->next=even->next->next;
            even=even->next;
        }
        odd->next=evenhead;
        return head;
    }
};
```

