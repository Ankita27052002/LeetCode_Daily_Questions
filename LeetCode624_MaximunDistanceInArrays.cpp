// LeetCode Problem 624 : Maximum Distance in Arrays (Medium)

// T.C : O(m) -- no. of arrays 
// S.C : O(1)

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int MIN  = arrays[0].front();
        int MAX = arrays[0].back();
        int result = 0;

        for(int i=1;i<arrays.size();i++){
            int currMin = arrays[i].front();
            int currMax = arrays[i].back();

            result = max({result,abs(MIN - currMax), abs(currMin - MAX)});

            MIN = min(MIN, currMin);
            MAX = max(MAX, currMax);
        }

        return result;
    }
};
