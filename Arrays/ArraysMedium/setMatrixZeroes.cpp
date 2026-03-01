#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


// BRUTE        ->      TC = O(nm * (n+m)) + O(nm): cubic     SC = O(1)
void brute(vector<vector<int>> &arr, int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 0) {
                for(int col = 0; col < m; col++) {
                    if(arr[i][col] != 0) {
                        arr[i][col] = -1;
                    }
                }
                for(int row = 0; row < n; row++) {
                    if(arr[row][j] != 0) {
                        arr[row][j] = -1;
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == -1) arr[i][j] = 0;
        }
    }
}


// BETTER        ->      TC = O(2nm)     SC = O(n + m)
void better(vector<vector<int>> &arr, int n, int m) {
    vector<int> rows(n);
    vector<int> cols(m);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 0) {
                rows[i] = 1;
                cols[j] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(rows[i] == 1 || cols[j] == 1) {
                arr[i][j] = 0;
            }
        }
    }
}


// OPTIMAL        ->      TC = O(2nm)     SC = O(1)
void optimal(vector<vector<int>> &arr, int n, int m) {
    int row0 = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 0) {
                if(i == 0) 
                    row0 = 0;
                else
                    arr[i][0] = 0;

                arr[0][j] = 0;
            }
        }
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(arr[i][0] == 0 || arr[0][j] == 0) {
                arr[i][j] = 0;
            }
        }
    }
    
    if(arr[0][0] == 0) {
        for(int i = 0; i < n; i++) {
            arr[i][0] = 0;
        }
    }

    if(row0 == 0) {
        for(int j = 0; j < m; j++) {
            arr[0][j] = 0;
        }
    }
}

int main() {
    int n, m;
    cin>>n>>m;

    vector<vector<int>> arr(n, vector<int>(m));
    for(vector<int> &vec : arr) {
        for(int &i : vec) cin>>i;
    }

    // brute(arr, n, m);
    // better(arr, n, m);
    optimal(arr, n, m);

    for(vector<int> vec : arr) {
        for(int x : vec) {
            cout<<x<<" ";
        }
        cout<<endl;
    }

    return 0;
}