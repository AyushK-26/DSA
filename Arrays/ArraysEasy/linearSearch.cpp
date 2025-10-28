#include <iostream>
#include <vector>
using namespace std;


// OPTIMAL      TC = O(n)       SC = O(1)
int optimal(vector<int> arr, int n, int target) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == target) return i;
    }
    return -1;
}

int main() {
    int n, target;
    cin>>n>>target;
    
    vector<int> arr(n);
    for(int &i : arr) cin>>i;

    cout<<optimal(arr, n, target);

    return 0;
}