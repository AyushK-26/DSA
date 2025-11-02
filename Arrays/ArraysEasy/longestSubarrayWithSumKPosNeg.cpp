#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


// OPTIMAL        ->      TC = O(n)     SC = O(n)
// Better for positives & zeroes only, optimal for negatives.
int optimal(vector<int> arr, int n, int k) {
    unordered_map<int, int> presumIndex;

    int presum = 0;
    int maxi = 0;

    for(int i = 0; i < n; i++) {
        presum += arr[i];
        if(presum == k) maxi = i+1;

        if(presumIndex.find(presum-k) != presumIndex.end()) {
            maxi = max(maxi, i-presumIndex[presum-k]);
        }

        if(presumIndex.find(presum) == presumIndex.end()) presumIndex[presum] = i;
    }

    return maxi;
}


int main () {
    int n;
    int k;
    cin>>n>>k;

    vector<int> arr(n);
    for(int &i : arr) cin>>i;

    cout<<optimal(arr, n, k)<<endl;

    return 0;
}