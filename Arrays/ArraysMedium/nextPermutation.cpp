#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// BRUTE        ->      TC = O(n! * n)                                        SC = O(n) depth of recursion
//                      sorting permutations + O(n!) linear search            O(n! * n) storing the answer.
/*
1. Find all the permutations in sorted order.
2. Do a linear search to find the given permutation.
3. Return the next permutation.
*/


// OPTIMAL       ->      TC = O(3n)     SC = O(1)
void optimal(vector<int> &arr, int n) {
    int index = -1;

    for(int i = n-2; i >= 0; i--) {
        if(arr[i+1] > arr[i]) {
            index = i;
            break;
        }
    }

    if(index != -1) {
        for(int i = n-1; i > index; i--) {
            if(arr[i] > arr[index]) {
                swap(arr[i], arr[index]);
                break;
            }
        }
    }
    
    reverse(arr.begin() + (index+1), arr.end());
}

int main() {
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int &i : arr) cin>>i;

    optimal(arr, n);
    for(int x : arr) cout<<x<<" ";

    return 0;
}