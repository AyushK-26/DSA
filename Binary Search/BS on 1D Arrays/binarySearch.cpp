#include <iostream>
#include <vector>
using namespace std;


// Binary Search Iterative        ->      TC = O(logn)     SC = O(1)
int bs_iterative(vector<int> arr, int n, int target) {
    int low = 0;
    int high = n-1;

    while(low <= high) {
        int mid = ((high-low)/2)+low;

        if(arr[mid] < target) {
            low = mid+1;
        } else if(arr[mid] > target) {
            high = mid-1;
        } else return mid;
    }

    return -1;
}


// Binary Search Recursive        ->      TC = O(logn)     SC = O(logn): depth of recursion
int bs_recursive(vector<int> arr, int low, int high, int target) {
    if(low > high) return -1;
    int mid = ((high-low)/2)+low;
    if(arr[mid] < target) {
        return bs_recursive(arr, mid+1, high, target);
    } else if(arr[mid] > target) {
        return bs_recursive(arr, low, mid-1, target);
    }
    return mid;
}


int main() {
    int n, target;
    cin>>n>>target;

    vector<int> arr(n);
    for(int &i : arr) cin>>i;

    cout<<bs_iterative(arr, n, target)<<endl;
    cout<<bs_recursive(arr, 0, n-1, target)<<endl;

    return 0;
}