#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// BRUTE        TC = O(n*logn + n)      SC = O(n) MS / O(1) QS
int brute(vector<int> &arr, int n) {

    sort(arr.begin(), arr.end());
    int largest = arr[n-1];
    int sLargest = -1;
    for(int i = n-2; i >= 0; i--) {
        if(arr[i] != largest) {
            sLargest = arr[i];
            break;
        }
    }

    return sLargest;
}


// BETTER       TC = O(2n)       SC = O(1)
int better(vector<int> &arr, int n) {

    int largest = arr[0];
    int sLargest = -1;
    for(int n : arr) {
        if(n > largest) largest = n;
    }
    
    for(int n : arr) {
        if(n > sLargest && n != largest) {
            sLargest = n;
        }
    }
    
    return sLargest;
}


// OPTIMAL      TC = O(n)       SC = O(1)
int optimal(vector<int> arr, int n) {

    int largest = arr[0];
    int sLargest = -1;
    for(int n : arr) {
        if(n > largest) {
            sLargest = largest;
            largest = n;
        } else if(n > sLargest && n < largest) {
            sLargest = n;
        }
    }

    return sLargest;
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