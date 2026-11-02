class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
      
        std::vector<int> lastIndex(128, 0);
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.length(); ++right) {
            unsigned char c = s[right];

         
            left = std::max(left, lastIndex[c]);

           
            maxLength = std::max(maxLength, right - left + 1);

          
            lastIndex[c] = right + 1;
        }

        return maxLength;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna