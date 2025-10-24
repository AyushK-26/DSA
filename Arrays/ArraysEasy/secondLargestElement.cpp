#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;

    vector<int> arr(n);

    for(int &i : arr) cin>>i;

    // BRUTE        TC = O(n*logn + n)      SC = O(n) MS / O(1) QS

    // sort(arr.begin(), arr.end());
    // int largest = arr[n-1];
    // int sLargest = -1;
    // for(int i = n-2; i >= 0; i--) {
    //     if(arr[i] != largest) {
    //         sLargest = arr[i];
    //         break;
    //     }
    // }

    // cout<<sLargest;


    // BETTER      TC = O(2n)       SC = O(1)

    // int largest = arr[0];
    // int sLargest = -1;
    // for(int n : arr) {
    //     if(n > largest) largest = n;
    // }
    
    // for(int n : arr) {
    //     if(n > sLargest && n != largest) {
    //         sLargest = n;
    //     }
    // }
    
    // cout<<sLargest;


    // OPTIMAL      TC = O(n)       SC = O(1)

    int largest = arr[0];
    int sLargest = -1;
    for(int n : arr) {
        if(n > largest) {
            sLargest = largest;
            largest = n;
        } else if(n > sLargest && n < largest) {
            sLargest = n;
        }
    }
    cout<<sLargest;

    return 0;
}