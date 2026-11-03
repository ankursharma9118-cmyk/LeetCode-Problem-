class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double currentSum = 0;



        for (int i = 0; i < k; ++i) {
            currentSum += nums[i];
        }
        

        double maxSum = currentSum;
        
        
        for (int i = k; i < nums.size(); ++i) {
            currentSum += nums[i] - nums[i - k];
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum / k;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna