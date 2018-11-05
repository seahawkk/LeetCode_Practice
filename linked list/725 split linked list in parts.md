## 725 分隔链表

* **题目来源：** [725 Split Linked List in Parts](https://leetcode-cn.com/problems/split-linked-list-in-parts/)

> 输入: root = [1, 2, 3], k = 5
> 输出: [[1],[2],[3],[],[]]
>
> 解释:输入输出各部分都应该是链表，而不是数组。
>
> 输入: root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
> 输出: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
> 解释:输入被分成了几个连续的部分，并且每部分的长度相差不超过1.前面部分的长度大于等于后面部分的长度。

**结题思路：** 该题的结题思路根据分成的几个连续的部分长度相差不能超过1，因此首先想到的是将总长度分为长度相同的几个部分，然后将剩下的结点均匀的分散到前几个结点中去。需要特别注意的是，可能存在一种情况：即需要分成的部分比结点总数还要多，此时将通过空链表来补充。

### python实现

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def splitListToParts(self, root, k):
        """
        :type root: ListNode
        :type k: int
        :rtype: List[ListNode]
        """
        parts=[None for m in range(k)]
        num=i=j=0
        node=root
        while node != None:
            num=num+1
            node=node.next
        n=num // k
        r=num % k
        head=root
        prev=None
        while (i<k and head != None):
            parts[i]=head
            j=0
            while(j<n+(r>0)):
                prev=head
                head=head.next
                j=j+1
            prev.next=None
            i=i+1
            r=r-1
        return parts
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> parts(k,nullptr);
        int len=0;
        for(ListNode* node=root;node;node=node->next)
            len++;
        int n=len / k,r=len % k;
        ListNode* node=root,*pre=nullptr;
        for(int i=0;node && i<k;i++,r--){
            parts[i]=node;
            for(int j=0;j<n+(r>0);j++){
                pre=node;
                node=node->next;
            }
            pre->next=nullptr;
        }
        return parts;
    }
};
```

