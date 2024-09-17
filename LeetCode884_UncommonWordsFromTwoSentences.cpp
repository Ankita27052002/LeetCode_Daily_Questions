// LeetCode Problem 884 : Uncommon Words From Two Uncommon Sentences (Easy)

// T.C : O(total length of two sentences)
// S.C : O(n)

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string s = s1 + " " + s2;
        stringstream ss(s);

        unordered_map<string, int> mp;

        string temp;
        while(ss>>temp){
            mp[temp]++;
        }

        vector<string> ans;
        for(auto &val:mp){
            if(val.second == 1){
                ans.push_back(val.first);
            }
        }

        return ans;
    }
};
