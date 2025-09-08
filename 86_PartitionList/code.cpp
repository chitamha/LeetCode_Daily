#include <bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
public:
    void addNode(ListNode *&parent, ListNode *&prev, ListNode *&present){
        if (parent==nullptr){
            parent=new ListNode(present->val);
            prev=parent;
        }
        else{
            ListNode *tmp=new ListNode(present->val);
            prev->next=tmp;
            prev=tmp;
        }
    }

    ListNode* partition(ListNode* head, int x){
        ListNode *greater=nullptr, *smaller=nullptr, *prev1=nullptr, *prev2=nullptr;
        while (head!=nullptr){
            if (head->val<x) addNode(smaller, prev1, head);
            else addNode(greater, prev2, head);
            head=head->next;
        }
        if (prev1!=nullptr) prev1->next=greater;
        else return greater;
        return smaller;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);


    return 0;
}