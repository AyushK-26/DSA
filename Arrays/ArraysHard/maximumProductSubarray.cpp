#include <iostream>
#include <vector>
#include <climits>
using namespace std;


// BRUTE        ->      TC = O(n^2)     SC = O(1)
int brute(vector<int> arr, int n) {
    int maxProduct = INT_MIN;
    for(int i = 0; i < n; i++) {
        int product = 1;
        for(int j = i; j < n; j++) {
            product *= arr[j];
            maxProduct = max(maxProduct, product);
        }
    }

    return maxProduct;
}


// OPTIMAL        ->      TC = O(n)     SC = O(1)
int optimal(vector<int> arr, int n) {
    int maxi = INT_MIN;
    int prefix = 1, suffix = 1;

    for(int i = 0; i < n; i++) {
        if(prefix == 0) prefix = 1;
        if(suffix == 0) suffix = 1;

        prefix *= arr[i];
        suffix *= arr[n-1-i];

        maxi = max(maxi, max(prefix, suffix));
    }

    return maxi;
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