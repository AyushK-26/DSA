#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// BRUTE        ->      TC = O(n^2)     SC = O(1)
bool brute(vector<int> arr, int n, int k) {
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] + arr[j] == k) return true;
        }
    }
    return false;
}


// BETTER       ->      TC = O(nlogn + n)     SC = O(1)
bool better(vector<int> arr, int n, int k) {
    sort(arr.begin(), arr.end());
    
    int i = 0, j = n-1;
    while(i < j) {
        if(arr[i] + arr[j] < k) i++;
        else if(arr[i] + arr[j] > k) j--;
        else return true;
    }

    return false;
}


// OPTIMAL       ->      TC = O(n)     SC = O(n)
bool optimal(vector<int> arr, int n, int k) {
    unordered_set<int> presentElements;
    
    for(int i = 0; i < n; i++) {
        if(presentElements.find(k-arr[i]) != presentElements.end()) {
            return true;
        }
        presentElements.insert(arr[i]);
    }
    
    return false;
}

int main() {
    int n, k;
    cin>>n>>k;

    vector<int> arr(n);
    for(int &i : arr) cin>>i;

    cout<<brute(arr, n, k)<<endl;
    cout<<better(arr, n, k)<<endl;
    cout<<optimal(arr, n, k)<<endl;

    return 0;
}