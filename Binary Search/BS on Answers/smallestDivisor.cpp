#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


// OPTIMAL      ->      TC = O(n * log(max(arr)))    SC = O(1)
int optimal(vector<int> arr, int n, int threshold) {
    int maxDivisor = 0;
    for(int x : arr) maxDivisor = max(maxDivisor, x);

    int low = 1;
    int high = maxDivisor;

    while(low <= high) {
        int mid = low+(high-low)/2;

        int sumOfQuotients = 0;
        for(int i = 0; i < n; i++) {
            sumOfQuotients += ceil((double)arr[i]/mid);

            if(sumOfQuotients > threshold) break;
        }

        if(sumOfQuotients <= threshold) high = mid-1;
        else low = mid+1;
    }

    return low;
}

int main () {
    int n, threshold;
    cin>>n>>threshold;

    vector<int> arr(n);
    for(int &i : arr) cin>>i;

    cout<<optimal(arr, n, threshold)<<endl;

    return 0;
}