#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


// BRUTE        ->      TC = O(n^2)     SC = O(1)
vector<int> brute(vector<int> arr, int n) {
    vector<int> ans;

    sort(arr.begin(), arr.end());

    for(int i = 0; i < n; i++) {
        if(ans.empty() || arr[i] != ans.back()) {
            int count = 0;

            for(int j = i; j < n; j++) {
                if(arr[i] == arr[j]) count++;
            }

            if(count > n/3) ans.push_back(arr[i]);
        }

        if(ans.size() == 2) break;
    }
    
    return ans;
}


// BETTER        ->      TC = O(n)     SC = O(n)
vector<int> better(vector<int> arr, int n) {
    vector<int> ans;
    
    map<int, int> frequency;
    
    for(int x : arr) {
        frequency[x]++;
        if(frequency[x] == (n/3)+1) ans.push_back(x);
        if(ans.size() == 2) break;
    }

    return ans;
}


// OPTIMAL        ->      TC = O(2n)     SC = O(1)
vector<int> optimal(vector<int> arr, int n) {
    vector<int> ans;

    int ele1 = INT_MIN, ele2 = INT_MIN;
    int cnt1 = 0, cnt2 = 0;

    for(int i = 0; i < n; i++) {
        if(cnt1 == 0 && ele2 != arr[i]) {
            cnt1 = 1;
            ele1 = arr[i]; 
        } else if(cnt2 == 0 && ele1 != arr[i]) {
            cnt2 = 1;
            ele2 = arr[i];
        }
        else if(ele1 == arr[i]) cnt1++;
        else if(ele2 == arr[i]) cnt2++;
        else {
            cnt1--; cnt2--;
        }
    }

    cnt1 = 0, cnt2 = 0;
    for(int x : arr) {
        if(ele1 == x) cnt1++;
        if(ele2 == x) cnt2++;
    }

    if(cnt1 > n/3) ans.push_back(ele1);
    if(cnt2 > n/3) ans.push_back(ele2);

    return ans;
}

int main() {
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int &i : arr) cin>>i;


    vector<int> bruteAns = brute(arr, n);
    for(int x : bruteAns) cout<<x<<" ";

    cout<<endl;

    vector<int> betterAns = better(arr, n);
    for(int x : betterAns) cout<<x<<" ";

    cout<<endl;

    vector<int> optimalAns = optimal(arr, n);
    for(int x : optimalAns) cout<<x<<" ";

    cout<<endl;

    return 0;
}