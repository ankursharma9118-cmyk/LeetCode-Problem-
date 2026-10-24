
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int passengers[1001] = {0};

        for (auto trip : trips) {
            passengers[trip[1]] += trip[0];
            passengers[trip[2]] -= trip[0];
        }



        int current = 0;


        for (int i = 0; i <= 1000; i++) {
            
            current += passengers[i];


            if (current > capacity) {
                return false;
            }
        }

        return true;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna