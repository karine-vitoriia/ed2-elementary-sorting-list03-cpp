
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

using ll = long long;

class Solution {
public:
    ll countInversions(vector<int> nums) {
        ll inversoes = 0;
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            int key = nums[i];
            int j = i - 1;

            while (j >= 0 && nums[j] > key) {
                nums[j + 1] = nums[j];
                j--;
                inversoes++;
            }
            nums[j + 1] = key;
        }
        return inversoes;
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
        ll total_inversoes = sol.countInversions(nums);

        cout << total_inversoes << "\n";
    }

    return 0;
}