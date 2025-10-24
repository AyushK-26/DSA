#include <iostream>
#include <vector>
#include <set>
using namespace std;


// BRUTE        TC = (n*logn + n)        SC = O(n)
void brute(vector<int> &arr, int n) {
    set<int> set;

    for(int n : arr) set.insert(n);
    int i = 0;
    for(int m : set) {
        arr[i] = m;
        i++;
    }
}


// OPTIMAL        TC = (n)        SC = O(1)
void optimal(vector<int> &arr, int n) {
    int i = 0;
    for(int j = 1; j < n; j++) {
        if(arr[j] != arr[i]) {
            arr[++i] = arr[j];
        }
    }
}


int main() {
    int n;
    cin>>n;

    vector<int> arr(n);

    for(int &i : arr) cin>>i;

    // brute(arr, n);
    optimal(arr, n);

    for(int n : arr) {
        cout<<n<<" ";
    }

    return 0;
}