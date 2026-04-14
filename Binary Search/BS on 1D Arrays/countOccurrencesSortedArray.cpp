#include <iostream>
#include <vector>
using namespace std;


// Count Occurrences    ->      TC = O(2*logn)     SC = O(1)
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

int countOccurrences(vector<int> arr, int n, int target) {
    vector<int> r = range(arr, n, target);
    if(r[0] == -1) return 0;

    return r[1] - r[0] + 1;
}


int main() {
    int n, target;
    cin>>n>>target;

    vector<int> arr(n);
    for(int &i : arr) cin>>i;

    cout<<countOccurrences(arr, n, target);

    return 0;
}