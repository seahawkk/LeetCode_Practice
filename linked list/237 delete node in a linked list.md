## 237 删除链表的结点

* **题目来源：** [237 Delete Node in a Linked List](https://leetcode-cn.com/problems/delete-node-in-a-linked-list/)

> ```
> 输入: head = [4,5,1,9], node = 5
> 输出: [4,1,9]
> 解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
> ```

**思路：** 由于只知道该结点的位置，题目说了不会删最后一个点，所以`node.next.next`一定存在，所以直接让`node`的val等于它`next`的val，然后让`node.next`指向`node.next.next`，举个例子： 1->2->3->4->5->None,要删除第四个节点，就让4变成5，然后让第四个节点指向第五个节点的next， 这样原来的第四个节点就不存在了，虽然原来的第五个节点仍然存在且指向None，变成了1->2->3->5->None-<5。==时间代价仅为O(1)==。

### python实现

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        node.val=node.next.val
        node.next=node.next.next
```

### C++实现

```C++
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;
    }
};
```

