#include <iostream>
#include <vector>
using namespace std;

// Approach 1        ->      TC = O(n! * n)     SC = O(3n) taken, permutation, depth of recursion
//                                                   O(n! * n) storing the answer.
void genPermutations1(vector<int> arr, vector<int> taken, vector<int> permutation, vector<vector<int>> &ans) {
    if(permutation.size() == arr.size()) {
        ans.push_back(permutation);
        return;
    }

    int n = arr.size();
    for(int i = 0; i < n; i++) {
        if(taken[i] != 1) {
            permutation.push_back(arr[i]);
            taken[i] = 1;
            genPermutations1(arr, taken, permutation, ans);
            permutation.pop_back();
            taken[i] = 0;
        }
    }
}


// Approach 2        ->      TC = O(n! * n)     SC = O(n) depth of recursion
//                                                   O(n! * n) storing the answer.
void genPermutations2(vector<int> arr, int pointer, vector<vector<int>> &ans) {
    if(pointer >= arr.size()) {
        ans.push_back(arr);
        return;
    }

    int n = arr.size();
    for(int i = pointer; i < n; i++) {
        swap(arr[pointer], arr[i]);
        genPermutations2(arr, pointer+1, ans);
        swap(arr[pointer], arr[i]);
    }
}

int main() {
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int &i : arr) cin>>i;


    //  Approach 1
    vector<int> taken(n);
    vector<int> permutation;
    vector<vector<int>> approachOneAns;

    genPermutations1(arr, taken, permutation, approachOneAns);

    for(vector<int> onePermutation : approachOneAns) {
        for(int x : onePermutation) {
            cout<<x<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    //  Approach 2
    int pointer = 0;
    vector<vector<int>> approachTwoAns;

    genPermutations2(arr, pointer, approachTwoAns);

    for(vector<int> onePermutation : approachTwoAns) {
        for(int x : onePermutation) {
            cout<<x<<" ";
        }
        cout<<endl;
    }

    return 0;
}