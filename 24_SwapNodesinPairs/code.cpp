#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode (int x){
        val=x;
        next=nullptr;
    }
    ListNode (int x, ListNode *nextNode){
        val=x;
        next=nextNode;
    } 
};

class Solution{
public:
    ListNode* swapPairs(ListNode* ans){
        ListNode *head=ans;
        while (head!=nullptr){
            ListNode *fir=head;
            if (head->next!=nullptr){
                ListNode *tmp=head;
                head=head->next;
                ListNode *sec=head;
                int tmpval=fir->val;
                fir->val=sec->val;
                sec->val=tmpval;
                tmp->next=head;
            }
            head=head->next;
        }
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);




    return 0;
}