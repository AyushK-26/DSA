#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


// BRUTE        ->      TC = O(n^2)     SC = O(1)
int brute(vector<int> arr, int n) {
    for(int i = 0; i < n; i++) {
        bool twiceFlag = false;
        for(int j = 0; j < n; j++) {
            if(i != j && arr[i] == arr[j]) {
                twiceFlag = true;
                break;
           }
        }
        if(!twiceFlag) return arr[i];
    }
}


// BETTER        ->      TC = O(n) + O((n/2)+1)     SC = O((n/2)+1)
int better(vector<int> arr, int n) {
    unordered_map<int, int> mpp;

    for(int x : arr) mpp[x]++;
    for(auto it : mpp) {
        if(it.second == 1) return it.first;
    }
}


// OPTIMAL        ->      TC = O(n)     SC = O(1)
int optimal(vector<int> arr, int n) {
    int xorr = 0;
    for(int x : arr) xorr ^= x;
    return xorr;
}


int main() {
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int &i : arr) cin>>i;
    
    cout<<brute(arr, n)<<endl;
    cout<<better(arr, n)<<endl;
    cout<<optimal(arr, n)<<endl;

    return 0;
}