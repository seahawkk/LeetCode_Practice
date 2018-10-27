## 160交叉链表

* **找到两个链表的交点**：题目来源[160交叉链表](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/)

```
A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
```

**解题思路**

对于两个具有交叉项的链表A和B，设A的链表长度为**a+c**,B的长度为**b+c**.也就是两个链表可以拆分为相交的部分和独立的部分。则有**a+c+b=b+c+a**.

所有，在通过指针来访问链表时，当链表A从表头访问到表尾后，使其从B的表头继续开始访问，同理，当链表B从表头访问到表尾后，使其从A的表头开始访问，这样，当二者访问相同的节点个数后，将会在交点处相遇。

**python实现**

```python
#class ListNode(object):
#	def __init__(self,x):
#        self.val=x
#        self.next=None
class Solution(object):
    def getIntersectionNode(self,headA,headB):
        LA,LB=headA,headB
        while(LA != LB):
            LA=LA.next if LA else headB
            LB=LB.next if LB else headA
        return LA #当没有交点时，返回None
```

**C++实现**

```C++
struct ListNode{
    int val;
    ListNode *Next;
    ListNode(int x): val(x),next(NULL){}
};
class *getIntersectionNode(ListNode *headA,ListNode *headB){
    ListNode *LA,*LB=headA,headB;
    while(LA!=LB){
        LA=LA?LA->next:headB;
        LB=LB?LB->next:headA;
    }
    return LA;
};
```



使用到了条件运算符：x=(y<0) ? -y : y。括号为真，为-y,括号为假，为y。

