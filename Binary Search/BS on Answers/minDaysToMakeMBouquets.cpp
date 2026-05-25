#include <iostream>
#include <vector>
using namespace std;


// BRUTE      ->      TC = O(n * max(bloomDay))    SC = O(1)
int brute(vector<int> bloomDay, int n, int m, int k) {
    int maxDays = 0;
    for(int day : bloomDay) maxDays = max(maxDays, day);

    for(int currentDay = 1; currentDay <= maxDays; currentDay++) {

        int pickedFlowers = 0;
        int bouquetsMade = 0;

        for(int i = 0; i < n; i++) {
            if(bloomDay[i] <= currentDay) pickedFlowers++;
            else if(bloomDay[i] > currentDay) pickedFlowers = 0;
            
            if(pickedFlowers == k) {
                bouquetsMade++; 
                pickedFlowers = 0;
            }

            if(bouquetsMade == m) return currentDay; 
        }
    }

    return -1;
}


// OPTIMAL      ->      TC = O(n * log(max(bloomDay)))    SC = O(1)
int optimal(vector<int> bloomDay, int n, int m, int k) {
    int maxDays = 0;
    for(int x : bloomDay) maxDays = max(maxDays, x);

    if(n < m*k) return -1;

    int low = 1;
    int high = maxDays;

    while(low <= high) {
        int mid = low+(high-low)/2;

        int flowersPicked = 0;
        int bouquetsMade = 0;
        for(int i = 0; i < n; i++) {
            if(bloomDay[i] <= mid) flowersPicked++;
            else flowersPicked = 0; 

            if(flowersPicked == k) {
                bouquetsMade++;
                flowersPicked = 0;
            }

            if(bouquetsMade >= m) break;
        }

        if(bouquetsMade >= m) high = mid-1;
        else low = mid+1;
    }

    return low;
}

int main () {
    int n, m, k;
    cin>>n>>m>>k;

    vector<int> bloomDay(n);
    for(int &i : bloomDay) cin>>i;

    cout<<brute(bloomDay, n, m, k)<<endl;
    cout<<optimal(bloomDay, n, m, k)<<endl;

    return 0;
}