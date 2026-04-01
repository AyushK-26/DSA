#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


// BRUTE        ->      TC = O(n^2)     SC = O(1)
int brute(vector<int> arr, int n, int k) {
    int count = 0;

    for(int i = 0; i < n; i++) {
        int xorr = 0;
        for(int j = i; j < n; j++) {
            xorr ^= arr[j];

            if(xorr == k) count++;
        }
    }

    return count;
}


// OPTIMAL        ->      TC = O(n)     SC = O(n)
int optimal(vector<int> arr, int n, int k) {
    unordered_map<int, int> xormap;
    
    int xorr = 0;
    int count = 0;
    xormap[xorr] = 1;

    for(int x : arr) {
        xorr ^= x;
        if(xormap.find(xorr^k) != xormap.end()) {
            count += xormap[xorr^k];
        }
        xormap[xorr]++;
    }

    return count;
}


int main() {
    int n, k;
    cin>>n>>k;

    vector<int> arr(n);
    for(int &i : arr) cin>>i;

    cout<<brute(arr, n, k)<<endl;
    cout<<optimal(arr, n, k)<<endl;
    
    return 0;
}