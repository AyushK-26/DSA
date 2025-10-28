#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


// BRUTE        ->      TC = O(n^2)         SC = O(1)
int brute(vector<int> arr, int n) {

    for(int i = 1; i <= n; i++) {
        bool found = false;
        for(int x : arr) {
            if(i == x) {
                found = true;
                break;
            }
        }
        if(!found) return i;
    }
}


// BETTER       ->      TC = O(2n)      SC = O(n-1)
int better(vector<int> arr, int n) {

    unordered_set<int> set;
    for(int x : arr) set.insert(x);

    for(int i = 1; i <= n; i++) {
        if(set.count(i) == 0) return i; 
    }
}


// OPTIMAL 1     ->     TC = O(n)       SC = O(1)
int optimal1(vector<int> arr, int n) {
    int totalSum = n*(n+1)/2;
    int sum = 0;

    for(int x : arr) sum += x;

    return totalSum - sum;
}


// OPTIMAL 2     ->     TC = O(n)       SC = O(1)
int optimal2(vector<int> arr, int n) {

    int xor1, xor2;
    xor1 = xor2 = 0;

    for(int i = 0; i < n-1; i++) {
        xor1 ^= (i+1);
        xor2 ^= arr[i];
    }

    xor1 ^= n;

    return xor1 ^ xor2;
}

int main() {
    int n;
    cin>>n;

    vector<int> arr(n-1);
    for(int &i : arr) cin>>i;

    cout<<brute(arr, n)<<endl;
    cout<<better(arr, n)<<endl;
    cout<<optimal1(arr, n)<<endl;
    cout<<optimal2(arr, n)<<endl;

    return 0;
}