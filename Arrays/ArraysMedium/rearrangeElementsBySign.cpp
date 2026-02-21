#include <iostream>
#include <vector>
using namespace std;


// BRUTE        ->      TC = O(2n)     SC = O(n)
void brute(vector<int> &arr, int n) {
    int posIdx = 0;
    int negIdx = 1;

    vector<int> ans(n);

    for(int x : arr) {
        if(x > 0) { 
            ans[posIdx] = x;
            posIdx += 2;
        } else {
            ans[negIdx] = x;
            negIdx += 2;
        }
    }
    
    for(int i = 0; i < n; i++) {
        arr[i] = ans[i];
    }
}

int main() {
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int &i : arr) cin>>i;

    brute(arr, n);

    for(int x : arr) cout<<x<<" ";

    return 0;
}