// LeetCode Problem 2028 : Find Missing Observations (Medium) [ Basic Maths ]

// T.C : O(m+n)
// S.C : O(1)

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = 0;
        for(auto it: rolls){ // sum of the m rolls
            sum += it;
        }

        int leftSum =(mean * (n + m)) - sum ;
        // leftSum must be in the range of 1n to 6n

        if(leftSum < n || leftSum > 6*n) return {};

        //find the mean of the n missing rolls
        int p = leftSum / n; 
        int rem = leftSum % n;

        vector<int> ans(n, p);

        //distribute the rem (remainder) to each element one by one
        for(int i=1;i<= rem;i++){
            ans[i]++;
        }

        return ans;
    }
};
