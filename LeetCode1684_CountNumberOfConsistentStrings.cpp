// LeetCode Problem 1684 : Count the Number of Consistent Strings (Easy)

// T.C : O(n^2)
// S.C : O(26)

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bitset<26> st = 0;
        for(char ch: allowed){
            st[ch - 'a'] = 1;
        }

        int count = 0;
        for(string& s: words){
            bool consistent = 1;
            for(char c: s){
                if(st[c - 'a'] == 0){
                    consistent = 0;
                    break;
                }
            }
            count += consistent;
        }

        return count;
    }
};
