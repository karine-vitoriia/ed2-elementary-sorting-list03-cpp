

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

using ll = long long;

class Solution {

    bool shouldSwap(int a, int b) {
        bool a_par = (a % 2 == 0);
        bool b_par = (b % 2 == 0);

        if (a_par && !b_par) return false;      // par antes de ímpar: ok
        if (!a_par && b_par) return true;       // ímpar antes de par: trocar
        if (a_par && b_par) return a > b;       // ambos pares: trocar se 'a' for maior
        return a < b;                           // ambos ímpares: trocar se 'a' for menor
    }

public:
    vector<int> customParityBubbleSort(vector<int> nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (shouldSwap(nums[j], nums[j + 1])) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
        return nums;
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
        vector<int> result = sol.customParityBubbleSort(nums);

        for (int i = 0; i < n; ++i) {
            cout << result[i] << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}