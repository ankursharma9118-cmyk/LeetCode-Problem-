class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum = 0;
        long long currentSum = 0;
        unordered_map<int, int> freq;

        for (int i = 0; i < nums.size(); ++i) {
           
            currentSum += nums[i];
            freq[nums[i]]++;

        
            if (i >= k) {
                int leftVal = nums[i - k];
                currentSum -= leftVal;
                freq[leftVal]--;
                if (freq[leftVal] == 0) {
                    freq.erase(leftVal);
                }
            }

            // When the window is exactly size k and all elements are distinct
            if (i >= k - 1 && freq.size() == k) {
                maxSum = max(maxSum, currentSum);
            }
        }

        return maxSum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna