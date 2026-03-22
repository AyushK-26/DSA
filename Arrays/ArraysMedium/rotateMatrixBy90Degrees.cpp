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


// OPTIMAL        ->      TC = O(n^2)     SC = O(1)
void reverse(vector<int> &row) {
    int n = row.size();
    for(int i = 0; i < n/2; i++) {
        int temp = row[i];
        row[i] = row[n-1-i];
        row[n-1-i] = temp;
    }
}

void optimal(vector<vector<int>> &matrix, int n) {

    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    for(int i = 0; i < n; i++) {
        reverse(matrix[i]);
    }
}

int main() {
    int n;
    cin>>n;

    vector<vector<int>> matrix(n, vector<int>(n));
    for(vector<int> &row : matrix) {
        for(int &i : row) cin>>i;
    }

    // brute(matrix, n);
    optimal(matrix, n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}