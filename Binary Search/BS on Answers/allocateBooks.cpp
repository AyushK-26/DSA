#include <iostream>
#include <vector>
using namespace std;


// OPTIMAL      ->      TC = O(n * log(sum(books) - max(books) + 1))    SC = O(1)
int countStudents(vector<int> books, int n, int pages) {
    int assignedPages = 0;
    int assignedStudents = 1;

    for(int i = 0; i < n; i++) {
        if(assignedPages + books[i] <= pages) {
            assignedPages += books[i];
        } else {
            assignedStudents++;
            assignedPages = books[i];
        }
    }

    return assignedStudents;
}

int optimal(vector<int> books, int n, int students) {
    if(students > n) return -1;

    int minPages = 0, maxPages = 0;
    for(int pages : books) {
        minPages = max(minPages, pages);
        maxPages += pages;
    }

    int low = minPages;
    int high = maxPages;

    while(low <= high) {
        int mid = low+(high-low)/2;
        int assignedStudents = countStudents(books, n, mid);

        if (assignedStudents <= students) high = mid-1;
        else low = mid+1;
    }

    return low;
}

int main() {
    int n, students;
    cin>>n>>students;

    vector<int> books(n);
    for(int &i : books) cin>>i;
    
    cout<<optimal(books, n, students)<<endl;

    return 0;
}