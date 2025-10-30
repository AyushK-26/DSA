#include <iostream>
#include <vector>
using namespace std;

// OPTIMAL      ->      TC = O(n)       SC = O(1)
int optimal(vector<int> arr, int n) {
    
    int maxi, currMax;
    maxi = currMax = 0;

    for(int x : arr) {
        if(x == 1) {
            currMax++;
            maxi = max(maxi, currMax);
        }
        else currMax = 0;
    }

    return maxi;
}

int main() {
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int &i : arr) cin>>i;

    cout<<optimal(arr, n)<<endl;

    return 0;
}