// LeetCode Problem 1310 : XOR Queries of a Subarray (Medium)

// T.C : O(n+q) --- n for processing the whole length array and q for queries
// S.C : O(n+q)

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        // storing precomputaion of XORs
        vector<int> pre(n);
        pre[0] = arr[0];

        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] ^ arr[i];
        }

        int m = queries.size();
        vector<int> ans(m);

        // compute for each query and store it
        for(int i=0;i<m;i++){
            int p = queries[i][0];
            int q = queries[i][1];

            if(p == 0){ //(p,q)---(0,q)
                ans[i] = pre[q];

            }
            else{
                ans[i] = pre[q] ^ pre[p-1];
            }
        }

        return ans;
    }
};
