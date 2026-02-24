#include <iostream>
#include <vector>
using namespace std;


// OPTIMAL        ->      TC = O(2n)     SC = O(n)
void optimal(vector<int> &arr, int n) {
    vector<int> pos, neg;

    for(int x : arr) {
        if(x > 0) pos.push_back(x);
        else neg.push_back(x);
    }

    int posSize = pos.size();
    int negSize = neg.size();

    if(posSize > negSize) {
        for(int i = 0; i < negSize; i++) {
            arr[2*i] = pos[i];
            arr[2*i + 1] = neg[i];  
        }
        int idx = negSize * 2;
        for(int i = negSize; i < posSize; i++) {
            arr[idx] = pos[i];
            idx++;
        }
    } else {
        for(int i = 0; i < posSize; i++) {
            arr[2*i] = pos[i];
            arr[2*i + 1] = neg[i];  
        }
        int idx = posSize * 2;
        for(int i = posSize; i < negSize; i++) {
            arr[idx] = neg[i];
            idx++;
        }
    }
}

int main() {
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int &i : arr) cin>>i;

    optimal(arr, n);

    for(int x : arr) cout<<x<<" ";

    return 0;
}