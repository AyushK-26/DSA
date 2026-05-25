#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// OPTIMAL      ->      TC = O(n * logn) + O(n * log(maxCoordinate − minCoordinate))    SC = O(1)
bool isPossible(vector<int> coordinates, int n, int cows, int distance) {
    int cowsPlaced = 1;
    int lastCowPlaced = coordinates[0];

    for(int i = 1; i < n; i++) {
        if(coordinates[i]-lastCowPlaced >= distance) {
            cowsPlaced++;
            lastCowPlaced = coordinates[i];
        }

        if(cowsPlaced >= cows) break;
    }

    return cowsPlaced >= cows; 
}

int optimal(vector<int> coordinates, int n, int cows) {

    sort(coordinates.begin(), coordinates.end());

    int low = 1;
    int high = coordinates[n-1]-coordinates[0];

    while(low <= high) {
        //  mid -> minimum distance between each cow
        int mid = low+(high-low)/2;

        //  Can we place all cows while maintaining at least this distance?
        //  Place cows such that the minimum distance between them is maximized
        if(isPossible(coordinates, n, cows, mid)) low = mid+1;
        else high = mid-1;
    }

    return high;
}


int main () {
    int n, cows;
    cin>>n>>cows;

    vector<int> coordinates(n);
    for(int &i : coordinates) cin>>i;

    cout<<optimal(coordinates, n, cows)<<endl;

    return 0;
}