## 445 两数相加 II

* **题目来源：** [445 Add Two Numbers II (Medium)](https://leetcode.com/problems/add-two-numbers-ii/description/)

> Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
> Output: 7 -> 8 -> 0 -> 7

* 题目要求：不能修改原始链表。

**思路**：比较暴力的方式，首先通过遍历两个链表求出其代表的非负正数，然后直接求和。之后通过设置`dummyhead`将和的各个位数置于一个新的链表中。在python中该方法能够实现。但在C++实现时，对于大数将会遇到输入的数值超出`int`范围-2147483648 ~ +2147483647   (4 Bytes)导致溢出。

### python实现

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        value=self.value(l1)+self.value(l2)
        dummyhead=ListNode(0)
        if value == 0:
            return dummyhead
        while(value != 0):
            nodeval=value % 10
            newnode=ListNode(nodeval)
            newnode.next=dummyhead.next
            dummyhead.next=newnode
            value=value // 10
        return dummyhead.next
    def value(self, head):
        cur=head
        nex=cur.next
        value=head.val
        while(nex != None):
            value=cur.val*10+nex.val
            cur.val=value
            nex=nex.next
        return value
```

### JAVA实现

利用栈的方式

```java
public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    Stack<Integer> l1Stack = buildStack(l1);
    Stack<Integer> l2Stack = buildStack(l2);
    ListNode head = new ListNode(-1);
    int carry = 0;
    while (!l1Stack.isEmpty() || !l2Stack.isEmpty() || carry != 0) {
        int x = l1Stack.isEmpty() ? 0 : l1Stack.pop();
        int y = l2Stack.isEmpty() ? 0 : l2Stack.pop();
        int sum = x + y + carry;
        ListNode node = new ListNode(sum % 10);
        node.next = head.next;
        head.next = node;
        carry = sum / 10;
    }
    return head.next;
}

private Stack<Integer> buildStack(ListNode l) {
    Stack<Integer> stack = new Stack<>();
    while (l != null) {
        stack.push(l.val);
        l = l.next;
    }
    return stack;
}
```

