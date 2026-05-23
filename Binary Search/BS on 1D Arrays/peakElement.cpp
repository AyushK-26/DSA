#include <iostream>
#include <vector>
using namespace std;


// OPTIMAL      ->      TC = O(log n)    SC = O(1)
int optimal(vector<int> arr, int n) {
    int low = 1;
    int high = n-2;

    if(n == 1) return arr[0];
    if(arr[0] > arr[1]) return arr[0];
    if(arr[n-1] > arr[n-2]) return arr[n-1];

    while(low <= high) {
        int mid = low+(high-low)/2;

        if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]) {
            return mid;
        }

        if(arr[mid-1] < arr[mid]) low = mid+1;
        else high = mid-1;
    }

    return -1;
}

int main() {
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int &i : arr) cin>>i;

    cout<<optimal(arr, n)<<endl;

    return 0;
}