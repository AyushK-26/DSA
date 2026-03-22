#include <iostream>
#include <vector>
using namespace std;

vector<int> optimal(vector<vector<int>> &matrix, int n, int m) {
    int top = 0, bottom = n-1;
    int left = 0, right = m-1;

    vector<int> spiralTraversalOrder;

    while(top <= bottom && left <= right) {
        for(int i = left; i <= right; i++) {
            spiralTraversalOrder.push_back(matrix[top][i]);
        }
        top++;

        for(int i = top; i <= bottom; i++) {
            spiralTraversalOrder.push_back(matrix[i][right]);
        }
        right--;

        if(top <= bottom) {
            for(int i = right; i >= left; i--) {
                spiralTraversalOrder.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        
        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                spiralTraversalOrder.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return spiralTraversalOrder;
}

int main() {
    int n, m;
    cin>>n>>m;

    vector<vector<int>> matrix(n, vector<int>(m));
    for(vector<int> &row : matrix) {
        for(int &i : row) cin>>i;
    }

    vector<int> optimalAns = optimal(matrix, n, m);

    for(int x : optimalAns) {
        cout<<x<<" ";
    }
}