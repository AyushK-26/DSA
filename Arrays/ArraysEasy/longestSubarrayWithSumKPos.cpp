#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


// BRUTE        ->      TC = O(n^2)     SC = O(1)
int brute(vector<int> arr, int n, int k) {
    int maxi = 0;
    
    for(int i = 0; i < n; i++) {
        int sum = 0;
        int currMax = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            currMax++;

            if(sum == k) {
                maxi = max(currMax, maxi);
                break;
            } else if(sum > k) break;
        }
    }
    
    return maxi;
}


// BETTER        ->      TC = O(n)     SC = O(n)
int better(vector<int> arr, int n, int k) {
    unordered_map<int, int> presumIndex;

    int presum = 0;
    int maxi = 0;

    for(int i = 0; i < n; i++) {
        presum += arr[i];
        if(presum == k) maxi = i+1;

        if(presumIndex.find(presum-k) != presumIndex.end()) {
            maxi = max(maxi, i-presumIndex[presum-k]);
        }

        presumIndex[presum] = i;
    }

    return maxi;
}


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

    cout<<brute(arr, n, k)<<endl;
    cout<<better(arr, n, k)<<endl;
    cout<<optimal(arr, n, k)<<endl;

    return 0;
};