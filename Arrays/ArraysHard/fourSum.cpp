#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


// BRUTE        ->      TC = O(n^4 * log(No. of unique quadruplets))
//                      SC = O(2*(No. of unique quadruplets))
vector<vector<int>> brute(vector<int> arr, int n, int target) {
    set<vector<int>> uniqueQuadruplets;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            for(int k = j+1; k < n; k++) {
                for(int l = k+1; l < n; l++) {
                    long long sum = arr[i] + arr[j];
                    sum += arr[k]; 
                    sum += arr[l];

                    if(sum == target) {
                        vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                        sort(temp.begin(), temp.end());
                        uniqueQuadruplets.insert(temp);
                    }
                }   
            }   
        }
    }

    vector<vector<int>> quadruplets(uniqueQuadruplets.begin(), uniqueQuadruplets.end());

    return quadruplets;
}


// BETTER        ->      TC = O(n^3 * log n * log(No. of unique quadruplets))
//                       SC = O(n) + O(2*(No. of unique quadruplets))
vector<vector<int>> better(vector<int> arr, int n, int target) {
    set<vector<int>> uniqueQuadruplets;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            set<int> hashSet;

            for(int k = j+1; k < n; k++) {
                int need = target - (arr[i] + arr[j] + arr[k]);
                if(hashSet.find(need) != hashSet.end()) {
                    vector<int> temp = {arr[i], arr[j], arr[k], need};
                    sort(temp.begin(), temp.end());
                    uniqueQuadruplets.insert(temp);
                }
                hashSet.insert(arr[k]);
            }
        }
    }

    vector<vector<int>> quadruplets(uniqueQuadruplets.begin(), uniqueQuadruplets.end());

    return quadruplets;
}


// OPTIMAL        ->      TC = O(n^3) + O(n*logn)    SC = O(No. of unique quadruplets)
vector<vector<int>> optimal(vector<int> arr, int n, int target) {
    vector<vector<int>> quadruplets;

    sort(arr.begin(), arr.end());

    for(int i = 0; i < n; i++) {
        if(i != 0 && arr[i] == arr[i-1]) continue;
        for(int j = i+1; j < n; j++) {
            if(j != i+1 && arr[j] == arr[j-1]) continue;

            int k = j+1;
            int l = n-1;

            while(k < l) {
                long long sum = arr[i] + arr[j];
                sum += arr[k];
                sum += arr[l];

                if(sum == target) {
                    vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                    quadruplets.push_back(temp);
                    k++; l--;
                    while(k < l && arr[k] == arr[k-1]) k++;
                    while(k < l && arr[l] == arr[l+1]) l--;
                } else if (sum < target) k++;
                else l--;
            }
        }
    }

    return quadruplets;
}


int main() {
    int n, target;
    cin>>n>>target;

    vector<int> arr(n);
    for(int &i : arr) cin>>i;

    vector<vector<int>> bruteAns = brute(arr, n, target);
    for(auto quadruplet : bruteAns) {
        for(int x : quadruplet) cout<<x<<" ";
        cout<<endl;
    }

    cout<<endl;

    vector<vector<int>> betterAns = better(arr, n, target);
    for(auto quadruplet : betterAns) {
        for(int x : quadruplet) cout<<x<<" ";
        cout<<endl;
    }

    cout<<endl;

    vector<vector<int>> optimalAns = optimal(arr, n, target);
    for(auto quadruplet : optimalAns) {
        for(int x : quadruplet) cout<<x<<" ";
        cout<<endl;
    }

    return 0;
}