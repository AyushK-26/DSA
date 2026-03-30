#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


// BRUTE        ->      TC = O(n^2)     SC = O(1)
int brute(vector<int> arr, int n) {
    int largest = 0;

    for(int i = 0; i < n; i++) {
        int sum = 0;

        for(int j = i; j < n; j++) {
            sum += arr[j];

            if(sum == 0) {
                largest = max(largest, j-i+1);
            }
        }
    }

    return largest;
}


// OPTIMAL        ->      TC = O(n)     SC = O(n)
int optimal(vector<int> arr, int n) {
    int largest = 0;

    unordered_map<int, int> hashmap;
    int presum = 0;

    for(int i = 0; i < n; i++) {
        presum += arr[i];

        if(hashmap.find(presum) != hashmap.end()) {
            largest = max(largest, i-hashmap[presum]);
        } 
        else hashmap[presum] = i;
    }

    return largest;
}


int main() {
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int &i : arr) cin>>i;

    cout<<brute(arr, n)<<endl;
    cout<<optimal(arr, n)<<endl;

    return 0;
}