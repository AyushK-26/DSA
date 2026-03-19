#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


long long brute(vector<int> v, vector<int> d, int n, int m) {
    long long maxTastePoints = 0;

    vector<int> tastePoints;

    for(int i = 0; i < n; i++) {
        int count = 1;
        int currTastePoints = v[i];
        while(currTastePoints > 0 && count <= m) {
            tastePoints.push_back(currTastePoints);
            currTastePoints = v[i] - d[i]*count;
            count++;
        }
    }

    sort(tastePoints.begin(), tastePoints.end(), greater<int>());

    for(int i = 0; i < m; i++) {
        maxTastePoints += tastePoints[i];
    }

    return maxTastePoints;
}

long long optimal(vector<int> v, vector<int> d, int n, int m) {
    long long maxTastePoints = 0;

    priority_queue<pair<int, int>> pq;

    for(int i = 0; i < n; i++) {
        pq.push({v[i], d[i]});
    }

    while(m--) {
        pair<int, int> current = pq.top();
        maxTastePoints += current.first;

        pq.pop();
        int nextTastePoints = current.first - current.second;
        pq.push({nextTastePoints, current.second});
    }

    return maxTastePoints;
}

int main() {
    int n, m;
    cin>>n>>m;

    vector<int> v(n);
    vector<int> d(n);

    for(int &i : v) cin>>i;
    for(int &i : d) cin>>i;

    
    cout<<brute(v, d, n, m)<<endl;
    cout<<optimal(v, d, n, m)<<endl;

    return 0;
}