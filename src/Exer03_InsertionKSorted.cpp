
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

using ll = long long;

class Solution {
public:
    pair<vector<int>, ll> insertionSortComparisons(vector<int> nums) {
        ll comparacoes = 0;
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            int key = nums[i];
            int j = i - 1;

            while (j >= 0) {
                comparacoes++;
                if (nums[j] > key) {
                    nums[j + 1] = nums[j];
                    j--;
                } else {
                    break;
                }
            }
            nums[j + 1] = key;
        }
        return {nums, comparacoes};
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
        pair<vector<int>, ll> result = sol.insertionSortComparisons(nums);

        for (int i = 0; i < n; ++i) {
            cout << result.first[i] << (i == n - 1 ? "" : " ");
        }
        cout << "\n" << result.second << "\n";
    }

    return 0;
}