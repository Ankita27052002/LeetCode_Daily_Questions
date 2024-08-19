// LeetCode Problem 650 : 2 Keys Keyboard (Medium)

// T.C : O(n^2)
// S.C : O(n^2)

class Solution {
public:
    int t[1001][1001];
    int solve(int currentA, int clipboardA, int n){
        if(currentA == n){
            return 0;
        }

        if(currentA > n){
            return 1000;
        }

        if(t[currentA][clipboardA] !=  -1){
            return t[currentA][clipboardA];
        }

        int copyAll = 1 + 1 + solve(currentA + currentA, currentA, n);

        int pasteA = 1 + solve(currentA + clipboardA, clipboardA, n);

        return t[currentA][clipboardA] = min(copyAll, pasteA);
    }
    int minSteps(int n) {
        if(n == 1) return 0;

        memset(t, -1, sizeof(t));
        return 1+solve(1, 1, n);
    }
};
