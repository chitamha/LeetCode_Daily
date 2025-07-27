/*
Kỹ thuật sinh hoán vị kế tiếp từ hoán vị hiện tại có thể xây dựng như sau:
- Xác định đoạn cuối giảm dần dài nhất, tìm chỉ số i của phần tử x[i] đứng liền trước đoạn cuối
đó. Điều này đồng nghĩa với việc tìm từ vị trí sát cuối dãy lên đầu, gặp chỉ số i đầu tiên thỏa
mãn x[i] < x[i+1].
- Có các trường hợp sau:
+ Nếu tìm thấy chỉ số i như trên:
    1) Trong đoạn cuối giảm dần, tìm phần tử x[k] nhỏ nhất thoả mãn điều kiện x[k] > x[i]. Do
đoạn cuối giảm dần, điều này thực hiện bằng cách tìm từ cuối dãy lên đầu gặp chỉ số k
đầu tiên thoả mãn x[k] > x[i] (có thể dùng tìm kiếm nhị phân).
    2) Đảo giá trị x[k] và x[i].
    3) Lật ngược thứ tự đoạn cuối giảm dần (từ x[i+1] đến x[n]) trở thành tăng dần.
+ Nếu không tìm thấy:
    Tức là toàn dãy đã sắp giảm dần, đây là cấu hình cuối cùng.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int find_upper(vector<int> nums, int l, int r, int val){
        int mid=-1;
        while (l<=r){
            mid=(l+r)/2;
            if (nums[mid]>val) l=mid+1;
            else r=mid-1;
        }
        return l-1;
    }

    void nextPermutation(vector<int>& nums){
        int n=nums.size(), id=n-2;
        while (id>=0 && nums[id]>=nums[id+1]) id--;
        if (id!=-1){
            int k=find_upper(nums, id+1, n-1, nums[id]);
            swap(nums[k], nums[id]);
        }
        reverse(nums.begin()+id+1, nums.end());
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    return 0;
}