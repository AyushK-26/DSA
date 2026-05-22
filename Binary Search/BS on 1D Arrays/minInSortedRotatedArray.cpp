#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// OPTIMAL      ->      TC = O(log*n)    SC = O(1)
int optimal(vector<int> arr, int n) {
    int low = 0;
    int high = n-1;
    int mini = INT_MAX;

    while(low <= high) {
        int mid = low+(high-low)/2;

        if(arr[low] <= arr[high]) {
            mini = min(mini, arr[low]);
            break;
        }

        if(arr[low] <= arr[mid]) {
            mini = min(mini, arr[low]);
            low = mid+1;
        } else {
            mini = min(mini, arr[mid]);
            high = mid-1;
        }
    }

    return mini;
}

int main () {
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int &i : arr) cin>>i;

    cout<<optimal(arr, n)<<endl;
}