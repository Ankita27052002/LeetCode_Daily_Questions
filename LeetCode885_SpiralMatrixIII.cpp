// LeetCode Problem 885 : Spiral Matrix III 
// Asked by : Google, Meta
// T.C : O((max(rows, cols))^2) // as we are computing for more than the cells in the matrix
// S.C : O(1) // or we can say the size of the matrix

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> directions = {
            {0,1}, // east
            {1,0}, // south
            {0,-1}, // west
            {-1,0} // north
        };

        vector<vector<int>> result;

        int step = 0; // how many steps you will take
        int dirIndex = 0; // in which direction you will move

        // first cell(row,col) will be in the answer
        result.push_back({rStart, cStart});

        while(result.size() < rows * cols){
            // we noticed that when we move towards east or west we increase our step by 1
            if(dirIndex == 0 || dirIndex == 2){
                step++;
            }

            // now in each direction move forward step number of cells
            for(int count=0; count<step; count++){
                rStart += directions[dirIndex][0]; //row
                cStart += directions[dirIndex][1]; //col

                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) // check valid
                    result.push_back({rStart, cStart});

                
            }
            dirIndex = (dirIndex + 1) % 4; // for changing the direction
        }
         return result;
        
    }
};
