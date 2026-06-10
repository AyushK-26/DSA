#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


// BRUTE      ->      TC = O(nm) + O(nm log(n*m))       SC = O(n * m)
int brute(vector<vector<int>> matrix, int n, int m) {
    vector<int> flat;

    for(vector<int> row : matrix) {
        for(int x : row) flat.push_back(x);
    }

    sort(flat.begin(), flat.end());

    return flat[n*m/2];
}


// OPTIMAL      ->      TC = O(n) + O(nlogm * log(maxElement - minElement))
//                      SC = O(1)
int optimal(vector<vector<int>> matrix, int n, int m) {
    int low = INT_MAX, high = INT_MIN;
    int partitionAt = (n * m)/2;

    for(int i = 0; i < n; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][m-1]);
    }

    while(low <= high) {
        int mid = low+(high-low)/2;
        int count = 0;
        for(int i = 0; i < n; i++) {
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }

        if(count > partitionAt) high = mid-1;
        else low = mid+1;
    }

    return low;
}


int main() {
    int n, m;
    cin>>n>>m;

    vector<vector<int>> matrix(n, vector<int>(m));

    for(vector<int> &row : matrix) {
        for(int &i : row) cin>>i;
    }

    cout<<brute(matrix, n, m)<<endl;
    cout<<optimal(matrix, n, m)<<endl;

    return 0;
}