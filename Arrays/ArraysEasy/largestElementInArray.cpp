#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// BRUTE        TC = O(n*logn)      SC = O(n) MS / O(1) QS

int brute(vector<int> &arr, int n) {

    sort(arr.begin(), arr.end());
    return arr[n-1];
}


// OPTIMAL      TC = O(n)       SC = O(1)

int optimal(vector<int> &arr, int n) {

    int largest = arr[0];
    for(int n : arr) {
        if(n > largest) largest = n;
    }
    return largest;
}


int main() {
    int n;
    cin>>n;

    vector<int> arr(n);

    for(int &i : arr) cin>>i;

    cout<<brute(arr, n)<<endl;
    cout<<optimal(arr, n)<<endl;
    return 0;
}