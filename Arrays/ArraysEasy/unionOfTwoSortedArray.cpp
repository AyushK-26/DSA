#include <iostream>
#include <vector>
#include <set>
using namespace std;


// BRUTE        ->      TC = O(n1*logn + n2*logn) + O(n1+n2)        SC = O(n1+n2)
vector<int> brute(vector<int> arr1, vector<int> arr2, int n1, int n2) {
    
    set<int> unionSet;
    vector<int> unionArr;
    
    for(int x : arr1) unionSet.insert(x);
    for(int x : arr2) unionSet.insert(x);

    for(int e : unionSet) unionArr.push_back(e);
    
    return unionArr;
}


// OPTIMAL      ->      TC = O(n1+n2)       SC = O(n1+n2) : In order to store the answer.
vector<int> optimal(vector<int> arr1, vector<int> arr2, int n1, int n2) {

    vector<int> unionArr;

    int i, j;
    i = j = 0;
    while(i < n1 && j < n2) {
        if(arr1[i] < arr2[j]) {
            if(unionArr.empty() || unionArr.back() != arr1[i]) {
                unionArr.push_back(arr1[i]);
            } 
            i++;
        } else if(arr1[i] > arr2[j]) {
            if(unionArr.empty() || unionArr.back() != arr2[j]) {
                unionArr.push_back(arr2[j]);
            }
            j++;
        } else {
            if(unionArr.empty() || unionArr.back() != arr1[i]) {
                unionArr.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }

    while(i < n1) {
        if(unionArr.empty() || unionArr.back() != arr1[i]) {
            unionArr.push_back(arr1[i]);
        }
        i++;
    }

    while(j < n2) {
        if(unionArr.empty() || unionArr.back() != arr2[j]) {
            unionArr.push_back(arr2[j]);
        }
        j++;
    }

    return unionArr;
}

int main() {
    int n1, n2;
    cin>>n1>>n2;
    
    vector<int> arr1(n1);
    for(int &i : arr1) cin>>i;

    vector<int> arr2(n2);
    for(int &i : arr2) cin>>i;

    vector<int> bruteUnion = brute(arr1, arr2, n1, n2);
    vector<int> optimalUnion = optimal(arr1, arr2, n1, n2);

    for(int e : bruteUnion) cout<<e<<" ";
    cout<<endl;
    for(int e : optimalUnion) cout<<e<<" ";

}