#include <iostream>
#include <vector>
#include <climits>
using namespace std;


// OPTIMAL      ->      TC = O(log(min(k, n) - max(0, k-m) + 1))       SC = O(1)
int optimal(vector<int> a, vector<int> b, int n, int m, int k) {
    if(n > m) return optimal(b, a, m, n, k);
    int low = max(0, k-m);
    int high = min(k, n);

    while(low <= high) {
        int mid1 = low + (high-low)/2;
        int mid2 = k-mid1;

        int l1 = (mid1-1 >= 0) ? a[mid1-1] : INT_MIN; 
        int l2 = (mid2-1 >= 0) ? b[mid2-1] : INT_MIN; 
        int r1 = (mid1 < n) ? a[mid1] : INT_MAX; 
        int r2 = (mid2 < m) ? b[mid2] : INT_MAX;

        if(l1 > r2) high = mid1-1;
        else if(l2 > r1) low = mid1+1;
        else return max(l1, l2);
    }

    return 0;
}

int main() {
    int n, m, k;
    cin>>n>>m>>k;

    vector<int> a(n);
    vector<int> b(m);
    for(int &i : a) cin>>i;
    for(int &i : b) cin>>i;

    cout<<optimal(a, b, n, m, k)<<endl;
    
    return 0;
}