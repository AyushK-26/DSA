#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// BETTER        ->      TC = O(n^3)     SC = O(1)
bool linearSearch(vector<int> arr, int n, int target) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == target) {
            return true;
        }
    }

    return false;
}

int brute(vector<int> arr, int n) {
    int maxSeq = 0;

    for(int i = 0; i < n; i++) {
        int x = arr[i];
        int currSeqLen = 1;

        while(linearSearch(arr, n, ++x)) {
            currSeqLen++;
            maxSeq = max(maxSeq, currSeqLen);
        }
    }

    return maxSeq;
}


// BETTER        ->      TC = O(nlogn) + O(n)     SC = O(1)
int better(vector<int> arr, int n) {
    sort(arr.begin(), arr.end());

    int maxSeq = 0, currSeqLen = 0;
    
    for(int i = 0; i < n-1; i++) {
        if(currSeqLen == 0) currSeqLen = 1;

        while(arr[i] == arr[i+1]) i++;
    
        if(arr[i] + 1 == arr[i+1]) {
            currSeqLen++;
            maxSeq = max(maxSeq, currSeqLen);
        } else currSeqLen = 1;
    }

    return maxSeq;
}


// OPTIMAL        ->      TC = O(3n)     SC = O(n)
int optimal(vector<int> arr, int n) {
    unordered_set<int> u_set;
    for(int x : arr) u_set.insert(x);

    int maxSeq = 0;

    for(int x : u_set) {
        if(u_set.find(x-1) == u_set.end()) {
            int currEle = x;
            int currSeqLen = 1;
            while(u_set.find(++currEle) != u_set.end()) {
                currSeqLen++;
            }
            maxSeq = max(maxSeq, currSeqLen);
        }
    }

    return maxSeq;
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