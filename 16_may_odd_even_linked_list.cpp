/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd, *even, *join, *top;
        top=head;
        if(head==nullptr || head->next==nullptr)
            return top;
        join = head->next;
        odd = head;
        even = head->next;
        int i=1;
        for( ;head != nullptr; head=head->next){
            if(i%2){
                odd->next = even->next;
                if(odd->next!=nullptr)
                    odd = odd->next;
            }
            else{
                even->next = odd->next;
                if(even->next!=nullptr)
                    even = even->next;
            }
            i++;
        }
        odd->next = join;
        return top;
    }
};
