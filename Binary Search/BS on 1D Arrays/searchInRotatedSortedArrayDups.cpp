#include <iostream>
#include <vector>
using namespace std;

// OPTIMAL      ->      TC = O(n/2): Worst Case    SC = O(1)
//                      TC = Θ(log n): Avg. Case 
bool optimal(vector<int> arr, int n, int target) {
    int low = 0;
    int high = n-1;

    while(low <= high) {
        int mid = low+(high-low)/2;

        if(arr[mid] == target) return true;
        if(arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low++;
            high--;
            continue;
        }

        if(arr[low] <= arr[mid]) {
            // low -> mid: sorted part
            if(arr[low] <= target && target < arr[mid]) high = mid-1;
            else low = mid+1;
        } else {
            // mid -> high: sorted part
            if(arr[mid] < target && target <= arr[high]) low = low+1;
            else high = high-1;
        }
    }

    return false;

}

int main () {
    int n, target;
    cin>>n>>target;

    vector<int> arr(n);
    for(int &i : arr) cin>>i;

    cout<<optimal(arr, n, target)<<endl;
}