class Solution {
public:
    int numSubseq(std::vector<int>& nums, int target) {
        int n = nums.size();
        int mod = 1e9 + 7;

      
        std::sort(nums.begin(), nums.end());

       
        std::vector<int> power(n, 1);
        for (int i = 1; i < n; ++i) {
            power[i] = (power[i - 1] * 2) % mod;
        }

        int left = 0;
        int right = n - 1;
        int ans = 0;

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
               
                ans = (ans + power[right - left]) % mod;
                left++;
            } else {
                right--;
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna