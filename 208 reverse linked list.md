## 208翻转链表（reverse linked list）

* 题目来源：[翻转链表](https://leetcode-cn.com/problems/reverse-linked-list/)

输入一个链表将其翻转：

> 输入：1->2->3->4->5->NULL     
>
> 输出：5->4->3->2->1->NULL

### 迭代方法

**python** 

应该注意的是python对链表结点的定义中，**self.next** 是下个结点，而不像C++中是指向下个结点的指针位置。

```python
#class ListNode(object):
#    def __init__(self,x):
#        self.val=x
#        self.next=None 
class Solution(object):
    def reverseList(self,head):
        prev=None
        cur=head
        while(cur):
            nex=cur.next #首先在cur的next结点变化之前记录下一个结点
            cur.next=prev #变化结点next方向
            prev=cur #移动结点位置，变换下一组结点
            cur=nex
        return prev  
```

**C++**

*head仅表示表头指针，和头结点（header node）区分开。

```C++
/**
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(NULL){}
};
**/
class Solution{
    public:
    ListNode *reverseList(ListNode *head){
        if(head==NULL)
            return NULL;
        else{
            ListNode *prev，*cur，*nex;
            prev=NULL;
            cur=head;
            while(cur！=NULL){
                nex=cur->next;
                cur->next=prev;
                prev=cur;
                cur=nex;
            }
            return prev;
    }
};
```

