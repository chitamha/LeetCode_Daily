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

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==nullptr) return nullptr;
        ListNode *ans=new ListNode(head->val), *prevNode=ans;
        head=head->next;
        while (head!=nullptr){
            if (head->val!=prevNode->val){
                ListNode *tmp=new ListNode(head->val);
                prevNode->next=tmp;
                prevNode=tmp;
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