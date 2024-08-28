// LeetCode Problem 1905 : Count Sub Islands (Medium)

// T.C : O(m*n)
// S.C : O(1) // only recursion stack space is used

class Solution {
public:
    bool checkIfSubIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j){
        if(i<0 || i>=grid1.size() || j<0 || j>=grid1[0].size()){
            return true;
        }

        if(grid2[i][j] != 1){
            return true;
        }

        grid2[i][j] = -1; // visited mark

        bool result = (grid1[i][j] == 1);

        result = result & checkIfSubIsland(grid1, grid2, i+1, j);
        result = result & checkIfSubIsland(grid1, grid2, i, j+1);
        result = result & checkIfSubIsland(grid1, grid2, i-1, j);
        result = result & checkIfSubIsland(grid1, grid2, i, j-1);

        return result;

    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        // using DFS
        int m = grid2.size();
        int n = grid2[0].size();
        int subIsland = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j] == 1 && checkIfSubIsland(grid1, grid2, i, j)){
                    subIsland++;
                }
            }
        }
        return subIsland;
    }
};
