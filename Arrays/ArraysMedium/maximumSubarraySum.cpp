#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// BRUTE        ->      TC = O(n^2)     SC = O(1)
int brute(vector<int> arr, int n) {
    int maxSum = INT_MIN;

    for(int i = 0; i < n; i++) {
        int sum = 0;

        for(int j = i; j < n; j++) {
            sum += arr[j];
            if(sum > maxSum) maxSum = sum;
        }
    }

    return maxSum;
}


// OPTIMAL        ->      TC = O(n)     SC = O(1)
int optimal(vector<int> arr, int n) {
    int maxSum = INT_MIN;
    int sum = 0;
    
    for(int i = 0; i < n; i++) {
        if(sum <= 0) sum = 0;
        sum += arr[i];
        if(sum > maxSum) maxSum = sum;
    }

    return maxSum;
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