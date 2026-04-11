#include <iostream>
#include <vector>
using namespace std;


// Lower Bound Linear       ->      TC = O(n)     SC = O(1)
int lowerBoundLinear(vector<int> arr, int n, int target) {
    int lowerBound = n;

    for(int i = 0; i < n; i++) {
        if(arr[i] >= target) {
            lowerBound = i;
            break;
        }
    }

    return lowerBound;
}


// Lower Bound BS      ->      TC = O(logn)     SC = O(1)
int lowerBoundBS(vector<int> arr, int n, int target) {
    int low = 0;
    int high = n-1;
    
    int lowerBound = n;

    while(low <= high) {
        int mid = low+(high-low)/2;
        if(arr[mid] >= target) {
            lowerBound = mid;
            high = mid-1;
        } else low = mid+1;
    }

    return lowerBound;
}


int main() {
    int n, target;
    cin>>n>>target;

    vector<int> arr(n);
    for(int &i : arr) cin>>i;

    cout<<lowerBoundLinear(arr, n, target)<<endl;
    cout<<lowerBoundBS(arr, n, target)<<endl;

    return 0;
}