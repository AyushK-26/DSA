#include <iostream>
#include <vector>
using namespace std;


// OPTIMAL      ->      TC = O(log n)     SC = O(1)
int optimal(vector<int> arr, int n, int target) {

    int low = 0;
    int high = n-1;

    while(low <= high) {
        int mid = low+(high-low)/2;

        if(arr[mid] == target) return mid;

        if(arr[low] <= arr[mid]) {
            // low -> mid: sorted part

            if(arr[low] <= target && target < arr[mid] ) high = mid-1;
            else low = mid+1;
        }else {
            // mid -> high: sorted part

            if(arr[mid] < target && target <= arr[high] ) low = low+1;
            else high = mid-1;
        }
    }

    return -1;
}

int main() {
    int n, target;
    cin>>n>>target;

    vector<int> arr(n);
    
    for(int &i : arr) cin>>i;

    cout<<optimal(arr, n, target)<<endl;

    return 0;
}