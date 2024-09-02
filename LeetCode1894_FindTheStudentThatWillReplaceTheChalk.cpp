// LeetCode Problem 1894 : Find the Student that will Replace the Chalk (Medium)

// T.C : O(n)
// S.C : O(1)

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        
        int n = chalk.size();
        long long totalChalk = 0;

        for(auto it: chalk){
            totalChalk += it; // we require totalChalk in full iteration
        }

        // In k/totalChalk full iteration will happen
        // remaining chalk
        int chalkRemain = k % totalChalk; 

        for(int i=0; i<n; i++){
            if(chalkRemain < chalk[i]){
                return i;
            }

            chalkRemain -= chalk[i];
        }

        return -1;

    }
};
