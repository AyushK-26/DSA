#include <iostream>
#include <vector>
#include <set>
using namespace std;


// BRUTE        ->      TC = O(n1*n2)       SC = O(n2) + O(min(n1, n2)) : visitedArr, storing ans.
vector<int> brute(vector<int> arr1, vector<int> arr2, int n1, int n2) {
    
    vector<int> intersectionArr;
    vector<int> visited(n2);

    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < n2; j++) {
            if(arr1[i] == arr2[j] && visited[j] != 1) {
                intersectionArr.push_back(arr1[i]);
                visited[j] = 1;
                break;
            }
            if(arr1[i] < arr2[j]) break;
        }
    }

    return intersectionArr;
}


// OPTIMAL      ->      TC = O(n1+n2)        SC = O(min(n1, n2))
vector<int> optimal(vector<int> arr1, vector<int> arr2, int n1, int n2) {
        
    vector<int> intersectionArr;

    int i, j;
    i = j = 0;

    while(i < n1 && j < n2) {
        if(arr1[i] < arr2[j]) i++;
        else if(arr1[i] > arr2[j]) j++;
        else {
            intersectionArr.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    return intersectionArr;

}

int main() {
    int n1, n2;
    cin>>n1>>n2;
    
    vector<int> arr1(n1);
    for(int &i : arr1) cin>>i;

    vector<int> arr2(n2);
    for(int &i : arr2) cin>>i;

    vector<int> bruteIntersection = brute(arr1, arr2, n1, n2);
    vector<int> optimalIntersection = optimal(arr1, arr2, n1, n2);

    for(int e : bruteIntersection) cout<<e<<" ";
    cout<<endl;
    for(int e : optimalIntersection) cout<<e<<" ";


    return 0;
}