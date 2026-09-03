
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

using ll = long long;

class Solution {
public:

    vector<int> selectionSortKElements(vector<int> nums, int k) {
        int n = nums.size();
        for (int i = 0; i < k; ++i) {
            int min_idx = i;
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] < nums[min_idx]) {
                    min_idx = j;
                }
            }
            swap(nums[i], nums[min_idx]);
        }

        return vector<int>(nums.begin(), nums.begin() + k);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, k;
    if (cin >> n >> k) {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }

        Solution sol;
        vector<int> result = sol.selectionSortKElements(nums, k);

        for (int i = 0; i < k; ++i) {
            cout << result[i] << (i == k - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}