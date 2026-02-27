#include <iostream>
#include <vector>
using namespace std;


// BRUTE        ->      TC = O(n^2)     SC = O(n)
vector<int> brute(vector<int> arr, int n) {
    vector<int> leaders;

    for(int i = 0; i < n; i++) {
        bool isLeader = true;    
        for(int j = i+1; j < n; j++) {
            if(arr[j] >= arr[i]) {
                isLeader = false;
                break;
            }
        }
        if(isLeader) leaders.push_back(arr[i]);
    }

    return leaders;
}


// OPTIMAL        ->      TC = O(n)     SC = O(n)
vector<int> optimal(vector<int> arr, int n) {
    vector<int> leaders;
    leaders.push_back(arr[n-1]);
    int lastLeader = arr[n-1];

    for(int i = n-2; i >= 0; i--) {
        if(arr[i] > lastLeader) {
            leaders.push_back(arr[i]);
            lastLeader = arr[i];
        }
    }

    return leaders;
}

int main() {
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int &i : arr) cin>>i;

    vector<int> bruteAns = brute(arr, n);
    for(int x : bruteAns) cout<<x<<" ";

    cout<<endl;

    vector<int> optimalAns = optimal(arr, n);
    for(int x : optimalAns) cout<<x<<" ";

    return 0;
}