#include <iostream>
#include <vector>
using namespace std;


// BRUTE        ->      TC = O(rows^2)*O(min(r, n-r))    SC = O(rows^2)
int ncr(int n, int r) {
    int mini = min(r, n-r);

    long long res = 1;
    for(int i = 0; i < mini; i++) {
        res = res*(n--)/(i+1);
    }

    return res;
}

vector<vector<int>> brute(int rows) {
    vector<vector<int>> pascalTriangle;

    for(int row = 1; row <= rows; row++) {
        vector<int> temp;
        for(int col = 1; col <= row; col++) {
            int res = ncr(row-1, col-1);
            temp.push_back(res);
        }
        pascalTriangle.push_back(temp);
    }

    return pascalTriangle;
}


// OPTIMAL 1        ->      TC = O(rows^2)   SC = O(rows^2)
vector<vector<int>> optimal1(int rows) {
   vector<vector<int>> pascalTriangle;

    for(int row = 0; row < rows; row++) {
        vector<int> temp = {1};
        for(int col = 1; col <= row; col++) {
            int value1 = 0;
            int value2 = pascalTriangle[row-1][col-1];
            if(col != row) value1 = pascalTriangle[row-1][col];

            temp.push_back(value1 + value2);
        }
        pascalTriangle.push_back(temp);
    }

    return pascalTriangle;
}


// OPTIMAL 2        ->      TC = O(rows^2)   SC = O(rows^2)
vector<int> pascalRow(int row) {
    vector<int> ans = {1};
    for(int col = 1; col < row; col++) {
        int res = ans.back()*(row-col)/col;
        ans.push_back(res);
    }
    return ans;
}

vector<vector<int>> optimal2(int rows) {
    vector<vector<int>> pascalTriangle;

    for(int row = 1; row <= rows; row++) {
        pascalTriangle.push_back(pascalRow(row));
    }
    return pascalTriangle;
}


int main() {
    int rows;
    cin>>rows;


    vector<vector<int>> bruteAns = brute(rows);
    for(vector<int> row : bruteAns) {
        for(int x : row) cout<<x<<" ";
        cout<<endl;
    }

    vector<vector<int>> optimal1Ans = optimal1(rows);
    for(vector<int> row : optimal1Ans) {
        for(int x : row) cout<<x<<" ";
        cout<<endl;
    }

    vector<vector<int>> optimal2Ans = optimal2(rows);
    for(vector<int> row : optimal2Ans) {
        for(int x : row) cout<<x<<" ";
        cout<<endl;
    }
}