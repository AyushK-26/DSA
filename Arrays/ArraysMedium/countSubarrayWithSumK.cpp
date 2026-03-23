#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


// BRUTE        ->      TC = O(n^2)     SC = O(1)
int brute(vector<int> arr, int n, int k) {
    int count = 0;

    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            if(sum == k) count++;
        }
    }

    return count;
}


// OPTIMAL        ->      TC = O(n)     SC = O(n)
int optimal(vector<int> arr, int n, int k) {
    unordered_map<int, int> presumFreq;

    int presum = 0;
    int count = 0;

    for(int i = 0; i < n; i++) {
        presum += arr[i];
        
        if(presum == k) count++;
    
        if(presumFreq.find(presum-k) != presumFreq.end()) {
            count += presumFreq[presum-k];
        }
        
        presumFreq[presum]++;
    }

    return count;

}

int main() {
    int n, k;
    cin>>n>>k;

    vector<int> arr(n);
    for(int &i : arr) cin>>i;

    cout<<brute(arr, n, k)<<endl;
    cout<<optimal(arr, n, k)<<endl;

}