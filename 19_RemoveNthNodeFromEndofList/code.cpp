#include <bits/stdc++.h>
using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *newhead=nullptr;
        int siz=0;
        while (head!=nullptr){
            newhead=new ListNode(head->val, newhead);
            head=head->next;
        }
        head=nullptr;
        while (newhead!=nullptr){
            siz++;
            //cout<< newhead->val<< " "<< siz<< endl;
            if (siz!=n) head=new ListNode(newhead->val, head);
            newhead=newhead->next;
        }
        return head;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, del; cin>> n>> del;
    ListNode *list=nullptr, *prev=nullptr;
    for (int i=1; i<=n; i++){
        int x; cin>> x;
        if (i==1){
            list=new ListNode(x);
            prev=list;
        }
        else{
            prev->next=new ListNode(x);
            prev=prev->next;
        }
    }
    Solution Sol;
    ListNode *Ans=Sol.removeNthFromEnd(list, del);
    cout<< "Ans: ";
    while (Ans!=nullptr){
        cout<< Ans->val<< " ";
        Ans=Ans->next;
    }
    return 0;
}