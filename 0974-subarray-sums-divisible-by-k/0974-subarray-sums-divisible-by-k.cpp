class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        std::vector<int> remainder_counts(k, 0);
        remainder_counts[0] = 1; 
        
        int current_sum = 0;
        int total_subarrays = 0;
        
        for (int num : nums) {
            current_sum += num;
            
          
            int rem = ((current_sum % k) + k) % k;
            
            total_subarrays += remainder_counts[rem];
            remainder_counts[rem]++;
        }
        
        return total_subarrays;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna