#include <iostream>
#include <vector>
using namespace std;


long long calculatePow(int base, int n, int m) {
        long long val = 1;

        for(int i = 1; i <= n; i++) {
            val = 1LL * val * base;
            if(val > m) break;
        }

        return val;
}

// BRUTE      ->      TC = O(n * m)    SC = O(1)
int brute(int n, int m) {
    for(int i = 1; i <= m; i++) {
        long long val = calculatePow(i, n, m);

        if(val == m) return i;
        else if(val > m) break;
    }

    return -1;
}


// OPTIMAL      ->      TC = O(n*log m)    SC = O(1)

int optimal(int n, int m) {
    if(m == 0) return 0;

    int low = 1, high = m;

    while(low <= high) {
        int mid = low+(high-low)/2;
        long long val = calculatePow(mid, n, m);

        if(val == m) return mid;
        else if(val < m) low = mid+1;
        else high = mid-1;
    }

    return -1;
}

int main() {
    int n, m;
    cin>>n>>m;

    cout<<brute(n, m)<<endl;
    cout<<optimal(n, m)<<endl;

    return 0;
}