#include <iostream>;
using namespace std;


// BRUTE        ->      TC = O(2n)     SC = O(n)
// Not suitable for large values:
// Factorials grow very fast → overflow even in long long
// Intermediate values exceed range before division

long long fact(int n) {
    if(n == 0 || n == 1) return 1;
    return n*fact(n-1);
}

int brute(int row, int col) {
    int n = row-1;
    int r = col-1;
    return fact(n)/(fact(r)*fact(n-r));
}


// OPTIMAL        ->      TC = O(min(r, n-r))     SC = O(1)
int optimal(int row, int col) {
    int n = row-1;
    int r = col-1;

    int mini = min(r, n-r);
    long long res = 1;
    for(int i = 0; i < mini; i++) {
        res = res*(n--)/(i+1);
    }

    return res;
}

int main() {
    int row, col;
    cin>>row>>col;

    cout<<brute(row, col)<<endl;
    cout<<optimal(row, col)<<endl;
}