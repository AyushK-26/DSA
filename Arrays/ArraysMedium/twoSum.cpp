#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//  Returning indecies of the elements.

// BRUTE        ->      TC = O(n^2)     SC = O(1)
vector<int> brute(vector<int> arr, int n, int k) {
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] + arr[j] == k) return {i, j};
        }
    }
    return {-1, -1};
}


// BETTER        ->      TC = O(n): unordered_map (avg case)   -   O(nlogn): map     SC = O(n)
vector<int> optimal(vector<int> arr, int n, int k) {
    unordered_map<int, int> hashmap;
    hashmap[arr[0]] = 0;

    for(int i = 0; i < n; i++) {
        if(hashmap.find(k-arr[i]) != hashmap.end()) {
            return {hashmap[k-arr[i]], i};
        }
        hashmap[arr[i]] = i;
    }
    return {-1, -1};
}

int main() {
    int n, k;
    cin>>n>>k;

    vector<int> arr(n);
    for(int &i : arr) cin>>i;

    vector<int> bruteAns = brute(arr, n, k);
    for(int x : bruteAns) cout<<x<<" ";

    cout<<endl;
    
    vector<int> optimalAns = optimal(arr, n, k);
    for(int x : optimalAns) cout<<x<<" ";

    return 0;
}