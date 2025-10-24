#include <iostream>
#include <vector>
using namespace std;


// OPTIMAL      TC = O(n)       SC = O(1)
bool optimal(vector<int> &arr, int n) {
    int breakCount = 0;

    for(int i = 1; i < n; i++) {
        if(arr[i-1] > arr[i]) breakCount++;
    }

    if(arr[n-1] > arr[0]) breakCount++;

    return (breakCount <= 1) ? true : false;
}


int main() {
    int n;
    cin>>n;

    vector<int> arr(n);

    for(int &i : arr) cin>>i;

    cout<<optimal(arr, n)<<endl;

    return 0;
}