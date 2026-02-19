#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


// BRUTE        ->      TC = O(n^2)     SC = O(1)
int brute(vector<int> arr, int n) {
    for(int i = 0; i < n; i++) {
        int count = 0;
        for(int j = 0; j < n; j++) {
            if(arr[i] == arr[j]) count++;
        }
        if(count > n/2) return arr[i];
    }
    return -1;
}


// BETTER        ->      TC = O(2n)     SC = O(n)
int better(vector<int> arr, int n) {
    unordered_map<int, int> freq;
    
    for(int x : arr) freq[x]++;

    for(auto it : freq) {
        if(it.second > n/2) return it.first;
    }

    return -1;
}


// OPTIMAL        ->      TC = O(2n)     SC = O()
int optimal(vector<int> arr, int n) {
    int element;
    int currCount = 0;
    for(int x : arr) {
        if(currCount == 0) element = x;

        if(element == x) currCount++;
        else currCount--;
    }

    int totalOccurance = 0;
    for(int x : arr) {
        if(element == x) totalOccurance++;
    }

    if(totalOccurance > n/2) return element;
    
    return -1;
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