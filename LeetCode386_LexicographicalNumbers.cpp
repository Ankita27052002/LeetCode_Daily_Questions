// LeetCode Problem 386 : Lexicographical Numbers (Medium)

// T.C : O(n)
// S.C : O(no. of bits in a number)

class Solution {
public:

    // as every num visited one time so T.c : O(n)
    void solve(int curr, int n, vector<int>& result){
        if(curr> n) return;

        result.push_back(curr);

        for(int append = 0; append<=9; append++){
            int newNum = curr * 10 + append;

            if(newNum > n) return;

            solve(newNum, n, result);
        }
    }
    vector<int> lexicalOrder(int n) {  // Solution using DFS
        vector<int> result;

        for(int startNum=1; startNum<= 9; startNum++){
            solve(startNum, n, result);
        }

        return result;
    }
};
