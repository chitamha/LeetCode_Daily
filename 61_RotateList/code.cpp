#include <bits/stdc++.h>
using namespace std;

//Definition for singly-linked list
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
class Solution{
public:
    ListNode* rotateRight(ListNode* head, int k){
        if (head==nullptr || k==0) return head;
        int n=0;
        vector<int> vec;

        ListNode *prev=head;
        while (prev!=nullptr){
            n++;
            vec.push_back(prev->val);
            prev=prev->next;
        }
        if (k%n==0) return head;

        k=n-k%n;
        head=new ListNode(vec[k]);
        prev=head;

        for (int i=k+1; i<n; i++){
            ListNode *tmp=new ListNode(vec[i]);
            prev->next=tmp;
            prev=tmp;
        }

        for (int i=0; i<k; i++){
            ListNode *tmp=new ListNode(vec[i]);
            prev->next=tmp;
            prev=tmp;
        }

        return head;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    return 0;
}