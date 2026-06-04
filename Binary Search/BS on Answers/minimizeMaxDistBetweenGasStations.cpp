#include <iostream>
#include <vector>
#include <queue>
using namespace std;


// BRUTE      ->      TC = O(kn + n)    SC = O(n-1)
long double brute(vector<int> coordinates, int n, int k) {
    vector<int> stationsPlaced(n-1);
    while(k--) {
        long double maxVal = -1;
        int maxIdx = -1;
        for(int i = 0; i < n-1; i++) {
            long double diff = coordinates[i+1]-coordinates[i];

            //how much gap is there after currently placed stations
            long double sectionLength = diff/(long double)(stationsPlaced[i]+1);

            //figure out max length between consecutive stations
            if(sectionLength > maxVal) {
                maxVal = sectionLength;
                maxIdx = i;
            }
        }

        // place one station where distance is max
        stationsPlaced[maxIdx]++;
    }

    long double maxDist = -1;
    for(int i = 0; i < n-1; i++) {
        long double diff = coordinates[i+1] - coordinates[i];
        long double sectionLength = diff/(long double)(stationsPlaced[i]+1);

        //how much each gap from intial gap is divided into after placing gas stations
        maxDist = max(maxDist, sectionLength);
    }

    return maxDist;
}


// BETTER      ->      TC = O((n + k) * logn)    SC = O(n-1)
double better(vector<int> coordinates, int n, int k) {
    vector<int> stationsPlaced(n-1);
    priority_queue<pair<long double, int>> pq; 

    for(int i = 0; i < n-1; i++) {
        pq.push({(long double)coordinates[i+1] - coordinates[i], i});
    }

    while(k--) {
        // Instead of finding max linearly, use PQ. Which returns max in log n
        pair<long double, int> maxSection = pq.top();
        pq.pop();

        int idx = maxSection.second;
        stationsPlaced[idx]++;
        long double initialDist = coordinates[idx+1]-coordinates[idx];
        long double newSectionLength = initialDist/(long double)(stationsPlaced[idx]+1);

        pq.push({newSectionLength, idx});
    }

    return pq.top().first;
}


// OPTIMAL      ->      TC = O(n * log(maxDist * 1e6)): 1e6 is constant        SC = O(1)
int gasStationsRequired(vector<int> coordinates, int n, long double mid) {
    int reqStations = 0;

    for(int i = 0; i < n-1; i++) {
        int placedInBetween = (coordinates[i+1] - coordinates[i])/mid;
        if((coordinates[i+1]-coordinates[i]) == placedInBetween*mid) {
            placedInBetween--;
        }

        reqStations += placedInBetween;
    }

    return reqStations;
}

long double optimal(vector<int> coordinates, int n, int k) {
    long double low = 0;
    long double high = -1;
    for(int i = 0; i < n-1; i++) {
        high = max(high, (long double)coordinates[i+1] - coordinates[i]);
    }

    // run loop till the diff gets smaller than 10^-6 to precise the answer till 6 decimal points
    while(high - low > 1e-6) {
        long double mid = low+(high-low)/2.0;

        if(gasStationsRequired(coordinates, n, mid) <= k) {
            high = mid;
        } else {
            low = mid;
        }
    }

    return high;
}


int main() {
    int n, k;
    cin>>n>>k;

    vector<int> coordinates(n);
    for(int &i : coordinates) cin>>i;

    cout<<brute(coordinates, n, k)<<endl;
    cout<<better(coordinates, n, k)<<endl;
    cout<<optimal(coordinates, n, k)<<endl;
    
    return 0;
}