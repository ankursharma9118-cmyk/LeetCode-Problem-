class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::unordered_map<int, int> prefix_counts;
      
        prefix_counts[0] = 1;
        
        int current_sum = 0;
        int total_subarrays = 0;
        
        for (int num : nums) {
            current_sum += num;

            
            int target = current_sum - k;
            if (prefix_counts.find(target) != prefix_counts.end()) {
                total_subarrays += prefix_counts[target];
            }
            
           
            prefix_counts[current_sum]++;
        }
        
        return total_subarrays;
        
            
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna