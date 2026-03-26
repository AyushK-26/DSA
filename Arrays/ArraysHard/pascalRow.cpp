#include <iostream>
#include <vector>
using namespace std;


// BRUTE        ->      TC = O(row)*O(min(r, n-r))    SC = O(row)
int ncr(int n, int r) {
    int mini = min(r, n-r);

    long long res = 1;
    for(int i = 0; i < mini; i++) {
        res = res*(n--)/(i+1);
    }

    return res;
}

vector<int> brute(int row) {
    vector<int> ans;

    for(int col = 1; col <= row; col++) {
        ans.push_back(ncr(row-1, col-1));
    }

    return ans;
}

// BRUTE        ->      TC = O(row)    SC = O(row)
vector<int> optimal(int row) {
    vector<int> ans = {1};

    for(int i = 1; i < row; i++) {
        int value = ans.back()*(row-i)/i;
        ans.push_back(value);
    }

    return ans;
}

int main() {
    int row;
    cin>>row;

    vector<int> bruteAns = brute(row);
    for(int x : bruteAns) cout<<x<<" ";

    cout<<endl;

    vector<int> optimalAns = optimal(row);
    for(int x : optimalAns) cout<<x<<" ";

    return 0;
}