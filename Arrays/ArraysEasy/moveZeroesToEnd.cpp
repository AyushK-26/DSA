#include <iostream>
#include <vector>
using namespace std;


// BRUTE      TC = O(2n)       SC = O(n)
void brute(vector<int> &arr, int n) {

    vector<int> temp;
    for(int x : arr) {
        if(x != 0) temp.push_back(x);
    }

    for(int i = 0; i < temp.size(); i++) {
        arr[i] = temp[i];
    }

    for(int i = temp.size(); i < n; i++) {
        arr[i] = 0;
    }
}


// BETTER      TC = O(2n)       SC = O(1)
void better(vector<int> &arr, int n) {

    int i = 0;
    for(int x : arr) {
        if(x != 0) {
            arr[i] = x;
            i++;
        }
    }

    while(i < n) {
        arr[i] = 0;
        i++;
    }
}


// OPTIMAL      TC = O(n)       SC = O(1)
void optimal(vector<int> &arr, int n) {

    int j = -1;
    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) {
            j = i;
            break;
        }
    }

    if(j != -1) {
        for(int i = j+1; i < n; i++) {
            if(arr[i] != 0) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                
                j++;
            }
        }
    }
}


int main() {
    int n;
    cin>>n;

    vector<int> arr(n);

    for(int &i : arr) cin>>i;

    // brute(arr, n);
    // better(arr, n);
    optimal(arr, n);

    for(int n : arr) {
        cout<<n<<" ";
    }

}