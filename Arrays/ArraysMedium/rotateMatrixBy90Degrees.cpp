#include <iostream>
#include <vector>
using namespace std;

// BRUTE        ->      TC = O(2*n^2)     SC = O(n^2)
void brute(vector<vector<int>> &matrix, int n) {
    vector<vector<int>> rotated(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            rotated[j][n-1-i] = matrix[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            matrix[i][j] = rotated[i][j];
        }
    }
}

int main() {
    int n;
    cin>>n;

    vector<vector<int>> matrix(n, vector<int>(n));
    for(vector<int> &row : matrix) {
        for(int &i : row) cin>>i;
    }

    brute(matrix, n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}