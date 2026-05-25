#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


// BRUTE      ->      TC = O(k * n)    SC = O(1)
int brute(vector<int> piles, int n, int h) {
    int maxBananas = 0;
    int hoursTook = 0;

    for(int bananas : piles) maxBananas = max(maxBananas, bananas);

    for(int k = 1; k <= maxBananas; k++) {
        hoursTook = 0;
        for(int i = 0; i < n; i++) {
            hoursTook += ceil((double)piles[i]/k);
            if (hoursTook > h) break;
        }

        if (hoursTook <= h) return k; 
    }

    return -1;
}

// OPTIMAL      ->      TC = O(n*log(max(piles)))    SC = O(1)
int optimal(vector<int> piles, int n, int h) {
    int maxBananas = 0;
    for(int bananas : piles) maxBananas = max(maxBananas, bananas);

    int low = 1;
    int high = maxBananas;

    while(low <= high) {
        int mid = low+(high-low)/2;
        int hoursTook = 0;

        for(int i = 0; i < n; i++) {
            hoursTook += ceil((double)piles[i]/mid);
            if(hoursTook > h) break;
        }

        if(hoursTook <= h) high = mid-1;
        else low = mid+1;
    }

    return low;
}

int main() {
    int n, h;
    cin>>n>>h;

    vector<int> piles(n);
    for(int &i : piles) cin>>i;

    cout<<brute(piles, n, h)<<endl;
    cout<<optimal(piles, n, h)<<endl;

    return 0;
}