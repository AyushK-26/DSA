#include <iostream>
#include <vector>
using namespace std;


// BRUTE        ->      TC = O(n^2)     SC = O(1)
vector<int> brute(vector<int> arr, int n) {
    int missing = -1, repeating = -1;
    
    for(int i = 1; i <= n; i++) {
        int count = 0;
        for(int j = 0; j < n; j++) {
            if(i == arr[j]) count++;
        }
        if(count == 0) missing = i;
        else if(count == 2) repeating = i;

        if(missing != -1 && repeating != -1) break;
    }

    return {missing, repeating};
}


// BETTER        ->      TC = O(2n)     SC = O(n)
vector<int> better(vector<int> arr, int n) {
    int missing = -1, repeating = -1;

    vector<int> hash(n+1);
    for(int x : arr) hash[x]++;

    for(int i = 1; i <= n; i++) {
        if(hash[i] == 0) missing = i;
        else if(hash[i] == 2) repeating = i;

        if(missing != -1 && repeating != -1) break;
    }

    return {missing, repeating};
}


// OPTIMAL 1        ->      TC = O(n)     SC = O(1)
vector<int> optimal1(vector<int> arr, int n) {
    int missing = -1, repeating = -1;

    long long totalSum = n*(n+1)/2;
    long long sq_totalSum = n*(n+1)*(2*n+1)/6;

    long long sum = 0, sq_sum = 0;
    for(int x : arr) {
        sum += x;
        sq_sum += (long long)x * (long long)x;
    }

    int equation1 = sum-totalSum;
    int equation2 = (sq_sum-sq_totalSum)/equation1;

    repeating = (equation2+equation1)/2;
    missing = equation2-repeating;

    return{missing, repeating};
}


// OPTIMAL 2        ->      TC = O(n)     SC = O(1)
vector<int> optimal2(vector<int> arr, int n) {
    int xorr = 0;
    for(int i = 0; i < n; i++) {
        xorr ^= arr[i];
        xorr ^= i+1;
    }

    // int bitNo = 0;
    // while(1) {
    //     if((xorr & (1<<bitNo)) != 0) break;
    //     bitNo++;
    // }

    // extracts the rightmost set bit (LSB) of xorr
    int number = xorr & ~(xorr-1);

    int zero = 0;
    int one = 0;
    for(int i = 0; i < n; i++) {
        //part of 0 bit club
        if((arr[i] & number) == 0) zero ^= arr[i];
        //part of 1 bit club
        else one ^= arr[i];

        //part of 0 bit club
        if((i+1 & number) == 0) zero ^= i+1;
        //part of 1 bit club
        else one ^= i+1;
    }

    int count = 0;
    for(int x : arr) {
        if(x == zero) count++;
    }

    if(count == 2) return{one, zero};
    return{zero, one};
}


int main() {
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int &i : arr) cin>>i;

    vector<int> bruteAns = brute(arr, n);
    for(int x : bruteAns) cout<<x<<" ";

    cout<<endl;

    vector<int> betterAns = better(arr, n);
    for(int x : betterAns) cout<<x<<" ";

    cout<<endl;

    vector<int> optimalAns1 = optimal1(arr, n);
    for(int x : optimalAns1) cout<<x<<" ";

    cout<<endl;

    vector<int> optimalAns2 = optimal2(arr, n);
    for(int x : optimalAns2) cout<<x<<" ";

    return 0;
}