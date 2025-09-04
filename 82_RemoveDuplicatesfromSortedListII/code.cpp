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
    ListNode* deleteDuplicates(ListNode* head){
        if (head==nullptr) return nullptr;
        ListNode *ans=nullptr, *prevNode=ans;
        while (head!=nullptr){
            int check=0;
            while (head->next!=nullptr && head->val==head->next->val){
                check=1;
                head=head->next;
            }
            if (check==0){
                ListNode *tmp=new ListNode(head->val);
                if (ans==nullptr){
                    ans=tmp;
                    prevNode=ans;
                }
                else{
                    prevNode->next=tmp;
                    prevNode=tmp;
                }
            }
            head=head->next;
        }
        
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);




    return 0;
}