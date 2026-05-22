#include <iostream>
#include <vector>
using namespace std;

int optimal(vector<int> arr, int n) {
    int low = 0;
    int high = n-1;
    int minIdx = 0;

    while(low <= high) {
        int mid = low+(high-low)/2;

        if(arr[low] < arr[high]) {
            if(arr[low] < arr[minIdx]) minIdx = low;
            break;
        }

        if(arr[low] <= arr[mid]) {
            // low -> mid: sorted part
            if(arr[low] < arr[minIdx]) minIdx = low;
            low = mid+1;
        } else {
            // mid -> high: sorted part
            if(arr[mid] < arr[minIdx]) minIdx = mid;
            high = mid-1;
        }
    }

    return minIdx;
}

int main() {
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int &i : arr) cin>>i;

    cout<<optimal(arr, n)<<endl;

    return 0;
}