#include <vector>
#include <string>
#include <cctype>

using namespace std;

class Solution {
private:
    void backtrack(string& s, int index, vector<string>& result) {
        if (index == s.length()) {
            result.push_back(s);
            return;
        }
        
        backtrack(s, index + 1, result);
        
        if (isalpha(s[index])) {
            s[index] ^= 32;
            backtrack(s, index + 1, result);
            s[index] ^= 32;
        }
    }

public:
    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        backtrack(s, 0, result);
        return result;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna