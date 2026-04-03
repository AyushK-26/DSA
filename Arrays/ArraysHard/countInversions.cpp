#include <iostream>
#include <vector>
using namespace std;

// BRUTE        ->      TC = O(n^2)     SC = O(1)
int brute(vector<int> arr, int n) {
    int count = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] > arr[j]) count++;
        }
    }

    return count;
}


// OPTIMAL        ->      TC = O(n*logn)     SC = O(n): temp vector + O(logn): depth of recursion 
void merge(vector<int> &arr, int low, int mid, int high, int &count) {
    vector<int> temp;
    int left = low;
    int right = mid+1;

    while(left <= mid && right <= high) {
        if(arr[left] <= arr[right]) {
            temp.push_back(arr[left++]);
        } else {
            count += mid-left+1;
            temp.push_back(arr[right++]);
        }
    }
    while(left <= mid) {
        temp.push_back(arr[left++]);
    }
    while(right <= high) {
        temp.push_back(arr[right++]);
    }

    for(int i = 0; i < temp.size(); i++) {
        arr[low+i] = temp[i];
    }
}

void ms(vector<int> &arr, int low, int high, int &count) {
    if(low >= high) return;
    int mid = ((high-low)/2)+low;

    ms(arr, low, mid, count);
    ms(arr, mid+1, high, count);

    merge(arr, low, mid, high, count);
}


int optimal(vector<int> arr, int n) {
    int count = 0;
    ms(arr, 0, n-1, count);
    return count;
}


int main () {
    int n;
    cin>>n;
    
    vector<int> arr(n);
    for(int &i : arr) cin>>i;

   cout<<brute(arr, n)<<endl;
   cout<<optimal(arr, n)<<endl;

    return 0;
}