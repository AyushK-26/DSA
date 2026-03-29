#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


// BRUTE        ->      TC = O(n^3 * log(no. of unique triplets))
//                      SC = O(2*(No. of unique triplets))
vector<vector<int>> brute(vector<int> arr, int n) {
    set<vector<int>> uniqueTriplets;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            for(int k = j+1; k < n; k++) {
                if(arr[i] + arr[j] + arr[k] == 0) {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    uniqueTriplets.insert(temp);
                }
            }
        }
    }

    vector<vector<int>> triplets(uniqueTriplets.begin(), uniqueTriplets.end());

    return triplets;
}


// BETTER        ->      TC = O(n^2 * log n * log(no. of unique triplets))
//                       SC = O(n) + O(2*(No. of unique triplets))
vector<vector<int>> better(vector<int> arr, int n) {
    set<vector<int>> uniqueTriplets;

    for(int i = 0; i < n; i++) {
        set<int> hashSet;
        
        for(int j = i+1; j < n; j++) {
            int need = -(arr[i] + arr[j]);
            if(hashSet.find(need) != hashSet.end()) {
                vector<int> temp = {arr[i], arr[j], need};
                sort(temp.begin(), temp.end());
                uniqueTriplets.insert(temp);
            }
            hashSet.insert(arr[j]);
        }
    }

    vector<vector<int>> triplets(uniqueTriplets.begin(), uniqueTriplets.end());

    return triplets;
}


// OPTIMAL        ->      TC = O(n^2) + O(n*logn)    SC = O(No. of unique triplets)
vector<vector<int>> optimal(vector<int> arr, int n) {
    vector<vector<int>> triplets;

    sort(arr.begin(), arr.end());

    for(int i = 0; i < n; i++) {
        if(i == 0 || arr[i] != arr[i-1]) {
            int j = i+1, k = n-1;

            while(j < k) {
                int sum = arr[i] + arr[j] + arr[k];

                if(sum == 0) {
                    triplets.push_back({arr[i], arr[j], arr[k]});
                    
                    do j++;while(j < k && arr[j] == arr[j-1]);
                    do k--; while(j < k && arr[k] == arr[k+1]);
                } 
                else if(sum < 0) j++;
                else k--;
            }
        }
    }

    return triplets;
}

int main() {
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int &i : arr) cin>>i;

    vector<vector<int>> bruteAns = brute(arr, n);
    for(auto triplet : bruteAns) {
        for(int x : triplet) cout<<x<<" ";
        cout<<endl;
    }

    vector<vector<int>> betterAns = better(arr, n);
    for(auto triplet : betterAns) {
        for(int x : triplet) cout<<x<<" ";
        cout<<endl;
    }

    vector<vector<int>> optimalAns = optimal(arr, n);
    for(auto triplet : optimalAns) {
        for(int x : triplet) cout<<x<<" ";
        cout<<endl;
    }

    return 0;
}