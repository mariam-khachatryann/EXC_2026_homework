#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, int> counts;
    
    for (int num : nums) {
        if (counts.find(num) != counts.end()) {
            return true;
        }
        counts[num] = 1;
    }
    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    cout << containsDuplicate(nums);
    return 0;
}