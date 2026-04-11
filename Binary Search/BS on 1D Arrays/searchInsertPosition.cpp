#include <iostream>
#include <vector>
using namespace std;


// Search Insert Position      ->      TC = O(logn)     SC = O(1)
// Return Lower Bound - return lower_bound(arr.begin(), arr.end(), target) - arr.begin();
int searchInsertPosition(vector<int> arr, int n, int target) {
    int low = 0;
    int high = n-1;
    
    int ans = n;

    while(low <= high) {
        int mid = low+(high-low)/2;
        if(arr[mid] >= target) {
            ans = mid;
            high = mid-1;
        } else low = mid+1;
    }

    return ans;
}


int main() {
    int n, target;
    cin>>n>>target;

    vector<int> arr(n);
    for(int &i : arr) cin>>i;

    cout<<searchInsertPosition(arr, n, target)<<endl;

    return 0;
}