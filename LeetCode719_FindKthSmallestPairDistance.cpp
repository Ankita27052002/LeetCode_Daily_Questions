// LeetCode Problem 719 : Find Kth Smallest Pair Distance (Hard)

// T.C : O(n^2)
// S.C : O(max_element)

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = *max_element(begin(nums), end(nums));
        vector<int> dist(maxi+1, 0);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int d = abs(nums[i] - nums[j]);
                dist[d]++;
            }
        }

        for(int d=0; d<=maxi; d++){
            k = k - dist[d];
            if(k <= 0) return d;
        }

        return -1;
    }
};
