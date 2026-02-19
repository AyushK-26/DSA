#include <iostream>
#include <vector>
#include <climits>
using namespace std;


// OPTIMAL        ->      TC = O(n)     SC = O(1)   :    returnMaxSumSubarray
vector<int> optimal(vector<int> arr, int n) {
    int maxSum = INT_MIN;
    int sum = 0;
    int start = -1;
    int ansStart =-1, ansEnd = -1;

    for(int i = 0; i < n; i++) {
        if(sum <= 0) {
            sum = 0;
            start = i;
        }
        
        sum += arr[i];

        if(sum > maxSum) {
            maxSum = sum;
            ansStart = start;
            ansEnd = i;
        }
    }

    return {ansStart, ansEnd};
}

int main() {
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int &i : arr) cin>>i;

    vector<int> optimalAns = optimal(arr, n);

    cout<<optimalAns[0]<<" "<<optimalAns[1];

    return 0;
}