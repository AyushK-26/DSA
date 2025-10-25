#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// BRUTE      TC = O(n+d)       SC = O(d)
void brute(vector<int> &arr, int n, int d) {
    vector<int> temp;
    for(int i = 0; i < d; i++) {
        temp.push_back(arr[i]);
    }

    for(int i = d; i < n; i++) {
        arr[i-d] = arr[i];
    }
    
    for(int i = 0; i < d; i++) {
        arr[n-d+i] = temp[i];
    }
}


// OPTIMAL      TC = O(n)       SC = O(1)
void optimal(vector<int> &arr, int n, int d) {

    d = d%n;    // at every *n rotations, all elements are at their original position.
    reverse(arr.begin(), arr.begin()+d);
    reverse(arr.begin()+d, arr.end());
    reverse(arr.begin(), arr.end());
}

int main() {
    int n, d;
    cin>>n>>d;

    vector<int> arr(n);

    for(int &i : arr) cin>>i;

    // brute(arr, n, d);
    optimal(arr, n, d);

    for(int n : arr) {
        cout<<n<<" ";
    }

}