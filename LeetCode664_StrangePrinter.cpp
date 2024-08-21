// LeetCode Problem 664 : Strange Printer (Hard) ---- asked by NetEase Games

// T.C : O(n^2)
// S.C : O(n^3)


class Solution {
public:
int n;
    vector<vector<int>> t;
    
    int solve(int l, int r, string& s){
        if(l == r)
            return 1;
        
        else if(l > r)
            return 0;
        
        if(t[l][r] != -1)
            return t[l][r];


        int i = l+1;
        while(i <= r && s[i] == s[l])
            i++;

        if(i == r+1)
            return 1;

        int normal = 1 + solve(i,r,s);

        int ans = INT_MAX;

        for(int j = i; j <= r; j++){
            if(s[l] == s[j]){
                
                int x = solve(i,j-1,s) + solve(j,r,s);
                
                ans = min(ans, x);
            }
        }

        return t[l][r] = min(ans, normal);
    }

    int strangePrinter(string s) {
        n = s.length() ;
        
        t.resize(n,vector<int>(n+1, -1));
        
        return solve(0, n-1, s); 
    }
};
