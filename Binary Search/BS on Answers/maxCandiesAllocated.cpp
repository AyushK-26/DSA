#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;


// BRUTE      ->      TC = O(n * max(candies))    SC = O(1)
int brute(vector<int> candies, int n, int k) {
    int maxCandies = 0, totalCandies = 0;
    int ans = 0;
    
    for(int x : candies) {
        maxCandies = max(maxCandies, x);
        totalCandies += x;
    }

    if(totalCandies < k) return 0;
    
    for(int candiesPerChild = 1; candiesPerChild <= maxCandies; candiesPerChild++) {
        int childrenServed = 0;
        for(int i = 0; i < n; i++) {
            childrenServed += candies[i]/candiesPerChild;
            if(childrenServed > k) break;
        }
    
        if(childrenServed >= k) ans = candiesPerChild;
        else break;
    }

    return ans;
}


// OPTIMAL      ->      TC = O(n * log(max(candies)))    SC = O(1)
int optimal(vector<int> candies, int n, int k) {
    int maxCandies = 0;

    for(int x : candies) maxCandies = max(maxCandies, x);

    int low = 1;
    int high = maxCandies;

    while(low <= high) {
        int mid = low+(high-low)/2;

        int childrenServed = 0;
        for(int i = 0; i < n; i++) {
            childrenServed += candies[i]/mid;
            if(childrenServed > k) break;
        }

        if(childrenServed >= k) low = mid+1;
        else high = mid-1;
    }
    
    return high;
}

int main() {
    int n, k;
    cin>>n>>k;

    vector<int> candies(n);
    for(int &i : candies) cin>>i;

    cout<<brute(candies, n, k)<<endl;
    cout<<optimal(candies, n, k)<<endl;

    return 0;
}