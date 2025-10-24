#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;

    vector<int> arr(n);

    for(int &i : arr) cin>>i;

    // BRUTE        TC = O(n*logn)      SC = O(n) MS / O(1) QS

    // sort(arr.begin(), arr.end());
    // cout<<arr[n-1];


    // OPTIMAL      TC = O(n)       SC = O(1)

    int largest = arr[0];
    for(int n : arr) {
        if(n > largest) largest = n;
    }
    cout<<largest;

    return 0;
}