#include <iostream>
#include <vector>
using namespace std;


// OPTIMAL        ->      TC = O(2n)     SC = O(1)
int optimal(vector<int> arr, int n, int k) {
    int presum = arr[0];
    int maxi = 0;
    int i = -1;
    int j = 0;

    while(j < n) {
        if(presum < k) {
            j++;
            if (j < n) presum += arr[j];
        } else if (presum > k) {
            i++;
            presum -= arr[i];
        } else if (presum == k) {
            maxi = max(maxi, j-i);
            j++;
            if(j < n) presum += arr[j];
        }
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