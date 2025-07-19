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
    ListNode* addTwoNumbers(ListNode* cur1, ListNode* cur2) {
        ListNode *Fir=nullptr;
        int nho=0;
        while (cur1!=nullptr || cur2!=nullptr){
            ListNode *tmp=new ListNode();
            int sum=nho;
            if (cur1!=nullptr) sum+=cur1->val;
            if (cur2!=nullptr) sum+=cur2->val;
            tmp->val=sum%10;
            tmp->next=Fir;
            Fir=tmp;
            if (sum>=10) nho=1;
            else nho=0;
            if (cur1!=nullptr) cur1=cur1->next;
            if (cur2!=nullptr) cur2=cur2->next;
        }
        if (nho!=0){
            ListNode *tmp=new ListNode(1);
            tmp->next=Fir;
            Fir=tmp;
        }
        ListNode *Ans=nullptr;
        while (Fir!=nullptr){
            ListNode *tmp=new ListNode();
            tmp->val=Fir->val;
            tmp->next=Ans;
            Ans=tmp;
            Fir=Fir->next;
        }
        return Ans;
    }
};