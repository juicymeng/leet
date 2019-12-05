#### 删除链表倒数第n个节点

```
ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1 = head;
        int i = 0;
        while (i < n && p1->next != nullptr) {
            p1 = p1->next;
            i++;
        }
        
        if (i < n && p1->next == nullptr) {
            return head->next;
        }

        ListNode * p2 = head;
        while (p1->next != nullptr) {
            p1=p1->next;
            p2=p2->next;
        } 
        p2->next = p2->next->next;
        return head;

    }
```
要求只遍历一遍，就要找出倒数第n个节点，两个指针找。
有一个特例需要考虑，就是链表的长度恰好为n，这时删除的是头节点。
