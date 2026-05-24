#include <iostream>
#include <vector>
using namespace std;


// BRUTE      ->      TC = O(n)    SC = O(1)
int brute(int n) {
    int ans = 0;

    for(long long i = 1; i <= n; i++) {
        
        if(i*i <= n) ans = i;
        else break;
    }

    return ans;
}


// OPTIMAL      ->      TC = O(log n)    SC = O(1)
int optimal(int n) {
    int low = 0;
    int high = n;
    long long mid = 0;

    while(low <= high) {
        mid = low+(high-low)/2;

        if(1LL*mid*mid <= n) low = mid+1;
        else high = mid-1;
    }

    return high;
}

int main() {
    int n;
    cin>>n;

    cout<<brute(n)<<endl;
    cout<<optimal(n)<<endl;


    return 0;
}