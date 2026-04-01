#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// BRUTE        ->      TC = O(n*logn) + O(2n)     SC = O(n)
vector<vector<int>> brute(vector<vector<int>> arr, int n) {
    vector<vector<int>> ans;

    sort(arr.begin(), arr.end());

    for(int i = 0; i < n; i++) {
        if(!ans.empty() && ans.back()[1] >= arr[i][1]) continue;
        else {
            ans.push_back(arr[i]);
            
            for(int j = i+1; j < n; j++) {
                if(arr[j][0] <= ans.back()[1]) {
                    ans.back()[1] = max(ans.back()[1], arr[j][1]);
                } else break;
            }
        }
    }

    return ans;
}


// OPTIMAL        ->      TC = O(n*logn) + O(n)     SC = O(n)
vector<vector<int>> optimal(vector<vector<int>> arr, int n) {
    vector<vector<int>> ans;

    sort(arr.begin(), arr.end());

    for(int i = 0; i < n; i++) {
        if(ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        } else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }

    return ans;
}


int main() {
    int n;
    cin>>n;

    vector<vector<int>> arr(n, vector<int>(2));
    for(auto &interval : arr) {
        for(int &i : interval) cin>>i;
    }

    vector<vector<int>> optimalAns = optimal(arr, n);
    for(auto interval : optimalAns) {
        for(int x : interval) cout<<x<<" ";
        cout<<endl;
    }

    cout<<endl;

    vector<vector<int>> bruteAns = brute(arr, n);
    for(auto interval : bruteAns) {
        for(int x : interval) cout<<x<<" ";
        cout<<endl;
    }

    return 0;
}