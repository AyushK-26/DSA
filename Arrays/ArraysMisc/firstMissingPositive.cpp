#include <iostream>
#include <vector>
using namespace std;


// OPTIMAL        ->      TC = O(2n) + O(n)     SC = O(1)
int optimal(vector<int> nums, int n) {
    for(int i = 0; i < n; i++) {
        if(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i]-1]) {
            int temp = nums[i];
            nums[i] = nums[nums[i]-1];
            nums[temp-1] = temp;

            i--;
        }
    }

    for(int i = 0; i < n; i++) {
        if(nums[i] != i+1) return i+1;
    }

    return n+1;
}

int main() {
    int n;
    cin>>n;

    vector<int> nums(n);
    for(int &i : nums) cin>>i;

    cout<<optimal(nums, n);

    return 0;
}