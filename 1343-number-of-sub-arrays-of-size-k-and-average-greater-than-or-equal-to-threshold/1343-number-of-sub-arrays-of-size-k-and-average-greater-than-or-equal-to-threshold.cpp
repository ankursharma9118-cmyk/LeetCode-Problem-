class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int targetSum = k * threshold;
        int currentSum = 0;
        int count = 0;

        
        for (int i = 0; i < k; ++i) {
            currentSum += arr[i];
        }

      
        if (currentSum >= targetSum) {
            count++;
        }

       
        for (int i = k; i < arr.size(); ++i) {
            currentSum += arr[i] - arr[i - k];
            if (currentSum >= targetSum) {
                count++;
            }
        }

        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna