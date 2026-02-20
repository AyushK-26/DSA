#include <iostream>
#include <vector>
using namespace std;


// BRUTE        ->      TC = O(n^2)     SC = O(1)
int brute(vector<int> arr, int n) {
    int profit;
    int maxProfit = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            profit = arr[j] - arr[i];
            maxProfit = max(maxProfit, profit);
        }
    }

    return maxProfit;
}


// OPTIMAL        ->      TC = O(n)     SC = O(1)
int optimal(vector<int> arr, int n) {
    int profit;
    int maxProfit = 0;
    int minPrice = arr[0];

    for(int i = 1; i < n; i++) {
        profit = arr[i] - minPrice;
        maxProfit = max(maxProfit, profit);
        minPrice = min(minPrice, arr[i]);
    }

    return maxProfit;
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