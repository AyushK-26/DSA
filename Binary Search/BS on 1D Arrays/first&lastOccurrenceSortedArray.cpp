#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Range    ->      TC = O(2*logn)     SC = O(1)
int firstOccurrence(vector<int> arr, int n, int target) {
    int ans = -1;
    int low = 0;
    int high = n-1;

    while(low <= high) {
        int mid = low+(high-low)/2;

        if(arr[mid] == target) {
            ans = mid;
            high = mid-1;
        }
        else if(arr[mid] < target) low = mid+1;
        else high = mid-1;
    }

    return ans;
}

int lastOccurrence(vector<int> arr, int n, int target) {
    int ans = -1;
    int low = 0;
    int high = n-1;

    while(low <= high) {
        int mid = low+(high-low)/2;

        if(arr[mid] == target) {
            ans = mid;
            low = mid+1;
        } 
        else if(arr[mid] < target) low = mid+1;
        else high = mid-1;
    }

    return ans;
}

vector<int> range(vector<int> arr, int n, int target) {
    int first = firstOccurrence(arr, n, target);
    if(first == -1) return {-1, -1};

    return {first, lastOccurrence(arr, n, target)};
}


// Range Using Bounds     ->      TC = O(2*logn)     SC = O(1)
vector<int> rangeUsingBounds(vector<int> arr, int n, int target) {
    int lb = lower_bound(arr.begin(), arr.end(), target) - arr.begin();

    if(lb == n || arr[lb] != target) return {-1, -1};

    int ub = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
    return {lb, ub-1};
}


int main() {
    int n, target;
    cin>>n>>target;

    vector<int> arr(n);
    for(int &i : arr) cin>>i;

    vector<int> ans1 = range(arr, n, target);
    cout<<ans1[0]<<endl;
    cout<<ans1[1]<<endl;

    vector<int> ans2 = rangeUsingBounds(arr, n, target);
    cout<<ans2[0]<<endl;
    cout<<ans2[1]<<endl;

    return 0;
}