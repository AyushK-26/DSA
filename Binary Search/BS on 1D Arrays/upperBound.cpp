#include <iostream>
#include <vector>
using namespace std;


// Upper Bound Linear       ->      TC = O(n)     SC = O(1)
int upperBoundLinear(vector<int> arr, int n, int target) {
    int upperBound = n;

    for(int i = 0; i < n; i++) {
        if(arr[i] > target) {
            upperBound = i;
            break;
        }
    }

    return upperBound;
}


// Upper Bound BS      ->      TC = O(logn)     SC = O(1)
int upperBoundBS(vector<int> arr, int n, int target) {
    int low = 0;
    int high = n-1;
    
    int upperBound = n;

    while(low <= high) {
        int mid = low+(high-low)/2;
        if(arr[mid] > target) {
            upperBound = mid;
            high = mid-1;
        } else low = mid+1;
    }

    return upperBound;
}


int main() {
    int n, target;
    cin>>n>>target;

    vector<int> arr(n);
    for(int &i : arr) cin>>i;

    cout<<upperBoundLinear(arr, n, target)<<endl;
    cout<<upperBoundBS(arr, n, target)<<endl;

    return 0;
}