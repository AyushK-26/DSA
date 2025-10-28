#include <iostream>
#include <vector>
using namespace std;

// OPTIMAL      TC = O(n)       SC = O(1)
void optimal(vector<int> &arr, int n) {
    int temp = arr[0];
    for(int i = 1; i < n; i++) {
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
}


int main() {
    int n;
    cin>>n;

    vector<int> arr(n);

    for(int &i : arr) cin>>i;

    optimal(arr, n);

    for(int n : arr) {
        cout<<n<<" ";
    }

    return 0;
}