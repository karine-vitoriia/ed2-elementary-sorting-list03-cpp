
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

using ll = long long;

class Solution {
public:

    pair<vector<int>, ll> bubbleSortSwapCount(vector<int> nums) {
        ll swaps = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                    swaps++;
                }
            }
        }
        return {nums, swaps};
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    if (cin >> n) {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }

        Solution sol;
        pair<vector<int>, ll> result = sol.bubbleSortSwapCount(nums);


        for (int i = 0; i < n; ++i) {
            cout << result.first[i] << (i == n - 1 ? "" : " ");
        }

        cout << "\n" << result.second << "\n";
    }

    return 0;
}