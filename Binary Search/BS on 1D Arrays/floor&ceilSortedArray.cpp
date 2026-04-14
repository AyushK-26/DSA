#include <iostream>
#include <vector>
using namespace std;


int floor(vector<int> arr, int n, int target) {
    int ans = -1;
    int low = 0, high = n-1;

    while(low <= high) {
        int mid = low+(high-low)/2;
        if(arr[mid] <= target) {
            ans = arr[mid];
            low = mid+1;
        } else high = mid-1;
    }

    return ans;
}

int ceil(vector<int> arr, int n, int target) {
    int ans = -1;
    int low = 0, high = n-1;

    while(low <= high) {
        int mid = low+(high-low)/2;
        if(arr[mid] >= target) {
            ans = arr[mid];
            high = mid-1;
        } else low = mid+1;
    }

    return ans;
}

int main() {
    int n, target;
    cin>>n>>target;

    vector<int> arr(n);
    for(int &i : arr) cin>>i;

    cout<<floor(arr, n, target)<<endl;
    cout<<ceil(arr, n, target)<<endl;

    return 0;
}