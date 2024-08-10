// LeetCode Problem 959: Regions Cut By Slashes  asked by Google
// T.C : O(rowls * cols)
// S.C : O(rowls * cols)

class Solution {
public:

    void numberOfIslandsDFS(vector<vector<int>>& matrix, int i, int j){
        if(i<0 || i>=matrix.size() || j<0 || j>=matrix[0].size() || matrix[i][j] == 1){
            return;
        }

        matrix[i][j] = 1; // visited mark

        numberOfIslandsDFS(matrix, i, j+1);
        numberOfIslandsDFS(matrix, i, j-1);
        numberOfIslandsDFS(matrix, i+1, j);
        numberOfIslandsDFS(matrix, i-1, j);
        

    }
    int regionsBySlashes(vector<string>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int regions = 0;

        vector<vector<int>> matrix(rows*3, vector<int>(cols*3, 0)); //M*N

        //  if '/' then represent it like -   0 0 1
        //                                    0 1 0
        //                                    1 0 0
        
        //  if '\' then reperesent it like-   1 0 0
        //                                    0 1 0
        //                                    0 0 1

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == '/'){
                    matrix[i*3][j*3+2] = 1;
                    matrix[i*3+1][j*3+1] = 1;
                    matrix[i*3+2][j*3] = 1;
                }
                else if(grid[i][j] == '\\'){
                    matrix[i*3][j*3] = 1;
                    matrix[i*3+1][j*3+1] = 1;
                    matrix[i*3+2][j*3+2] = 1;
                }
            }
        }

        // Now apply the concept of "Number of Islands"
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j] == 0){
                    numberOfIslandsDFS(matrix, i, j);
                    regions += 1;
                }
            }
        }

        return regions;
    }
};
