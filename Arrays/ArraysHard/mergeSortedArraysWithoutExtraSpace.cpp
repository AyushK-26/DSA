#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// OPTIMAL1        ->      TC = O(min(n,m)) + O(n*logn) + O(m*logm)     SC = O(1)
void optimal1(vector<int> &nums1, vector<int> &nums2, int n, int m) {
    int i = n-1;
    int j = 0;

    while(i >= 0 && j < m) {
        if(nums1[i] > nums2[j]) {
            swap(nums1[i], nums2[j]);
            i--;
            j++;
        } else break;
    }

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
}


// OPTIMAL2        ->      TC = O((n+m)*log(n+m))     SC = O(1)
void swapIfGreater(vector<int> &nums1, vector<int> &nums2, int i, int j) {
    if(nums1[i] > nums2[j]) {
        swap(nums1[i], nums2[j]);
    }
}

void optimal2(vector<int> &nums1, vector<int> &nums2, int n, int m) {

    int len = n+m;
    int gap = (len/2) + (len%2);

    while(gap > 0) {
        int left = 0;
        int right = left + gap;
        
        while(right < len) {
            //arr1 & arr2
            if(left < n && right >= n){
                swapIfGreater(nums1, nums2, left, right-n);
            }
            //arr2 & arr2
            else if(left >= n) {
                swapIfGreater(nums2, nums2, left-n, right-n);    
            }
            //arr1 & arr1
            else {
                swapIfGreater(nums1, nums1, left, right);    
            }
            left++;
            right++;
        }

        if(gap == 1) break;
        gap = (gap/2) + (gap%2);
    }

}

int main() {
    int n, m;
    cin>>n>>m;

    vector<int> nums1(n), nums2(m);
    for(int &i : nums1) cin>>i;
    for(int &i : nums2) cin>>i;

    // optimal1(nums1, nums2, n, m);
    optimal2(nums1, nums2, n, m);

    for(int x : nums1) cout<<x<<" ";
    for(int x : nums2) cout<<x<<" ";

    return 0;
}