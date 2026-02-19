#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// BRUTE        ->      TC = O(nlogn)     SC = O(n)
void brute(vector<int> &arr, int n) {
    sort(arr.begin(), arr.end());
}


// BETTER        ->      TC = O(2n)     SC = O(1)
void better(vector<int> &arr, int n) {
    int count0 = 0, count1 = 0, count2 = 0;
    for(int x : arr) {
        if(x == 0) count0++;
        if(x == 1) count1++;
        if(x == 2) count2++;
    }

    for(int i = 0; i < count0; i++) {
        arr[i] = 0;
    }
    for(int i = count0; i < count0+count1; i++) {
        arr[i] = 1;
    }
    for(int i = count0+count1; i < n; i++) {
        arr[i] = 2;
    }
}


// OPTIMAL        ->      TC = O(n)     SC = O(1)
void optimal(vector<int> &arr, int n) {
    int low = 0, mid = 0, high = n-1;
    while(mid <= high) {
        if(arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1) {
            mid++;
        }
        else if(arr[mid] == 2) {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}


int main() {
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int &i : arr) cin>>i;

    // brute(arr, n);
    // better(arr, n);
    optimal(arr, n);

    for(int x : arr) {
        cout<<x<<" ";
    }

    return 0;
}