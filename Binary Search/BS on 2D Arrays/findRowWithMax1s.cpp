#include <iostream>
#include <vector>
using namespace std;


// BRUTE      ->      TC = O(n*m)       SC = O(1)
int brute(vector<vector<int>> matrix, int n, int m) {
    int rowIdx = -1;
    int maxCount = 0;
    for(int i = 0; i < n; i++) {
        int count = 0;
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == 1) count++;
        }
        if(count > maxCount) {
            maxCount = count;
            rowIdx = i;
        }
    }

    return rowIdx;
}


// OPTIMAL      ->      TC = O(n * logm)       SC = O(1)
int countOnes(vector<int> arr, int m) {
    int low = 0;
    int high = m-1;

    while(low <= high) {
        int mid = low+(high-low)/2;
        if(arr[mid] == 0) low = mid+1;
        else high = mid-1;
    }

    return m-low;
}

int optimal(vector<vector<int>> matrix, int n, int m) {
    int rowIdx = -1;
    int maxCount = 0;

    for(int i = 0; i < n; i++) {
        int count = countOnes(matrix[i], m);
        if(count > maxCount) {
            maxCount = count;
            rowIdx = i;
        }
    }

    return rowIdx;
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