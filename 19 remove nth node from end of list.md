## 19 删除链表的倒数第N个结点

* **题目来源 :**[19 Remove Nth Node From End of List (Medium)](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/) 

> 给定一个链表：1->2->3->4->5，和n=2
>
> 当删除了倒数第二个结点后，链表变为：1->2->3->5

**思路：** 首先第一次遍历链表确定链表的节点数，然后在通过第二次扫描链表找到需要删除的结点位置，替换其前结点的next指针。需要注意的是，当倒数第N个结点为`head ` 结点时，需要额外判断。为了解决这个问题，引入了`dummy head`，dummy->next=`head`。

### python实现

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        dummy=find=ListNode(-1)
        current=find.next=head
        m=i=1
        while current.next != None:
            current=current.next
            m=m+1
        while i <= m-n:
            find=find.next
            i=i+1
        find.next=find.next.next
        return dummy.next
```

`dummy head`结点可以直接通过初始化定义ListNode实现，-1没有实际意义，只是赋予结点一个val值。

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy=new ListNode(0);   /*dummyhead*/
        dummy->next=head;
        ListNode *current=head,*find=dummy;
        int m=1,i=1;
        while(current->next != NULL){
            current=current->next;
            m=m+1;
        }
        while(i<=m-n){
            find=find->next;
            i=i+1;
        }
        find->next=find->next->next;
        return dummy->next;
    }
};
```



C++中`dummy head`的初始化需要动态分内存，利用new运算符实现。

### 一次遍历实现

上述算法可以优化为只使用一次遍历。我们可以使用两个指针而不是一个指针。第一个指针从列表的开头向前移动 n+1 步，而第二个指针将从列表的开头出发。现在，这两个指针被 n 个结点分开。我们通过同时移动两个指针向前来保持这个恒定的间隔，直到第一个指针到达最后一个结点。此时第二个指针将指向从最后一个结点数起的第 n个结点。我们重新链接第二个指针所引用的结点的 `next` 指针指向该结点的下下个结点。

![Remove the nth element from a list](https://leetcode-cn.com/media/original_images/19/19_Remove_nth_node_from_end_of_listB.png) 

```java
public ListNode removeNthFromEnd(ListNode head, int n) {
    ListNode dummy = new ListNode(0);
    dummy.next = head;
    ListNode first = dummy;
    ListNode second = dummy;
    // Advances first pointer so that the gap between first and second is n nodes apart
    for (int i = 1; i <= n + 1; i++) {
        first = first.next;
    }
    // Move first to the end, maintaining the gap
    while (first != null) {
        first = first.next;
        second = second.next;
    }
    second.next = second.next.next;
    return dummy.next;
}
```

**复杂度分析**

*  时间复杂度：O(L)，

该算法对含有 LL 个结点的列表进行了一次遍历。因此时间复杂度为 O(L)。

- 空间复杂度：O(1)，

  我们只用了常量级的额外空间。

