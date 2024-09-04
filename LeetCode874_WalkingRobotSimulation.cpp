// LeetCode Problem 874 : Walking Robot Simulation (Medium)

// T.C : O(m + n*maxVal)
// S.C : O(m)

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> st;

        for(vector<int>& obs: obstacles){
            string key = (to_string(obs[0]) + "_" + to_string(obs[1]));
            st.insert(key);
        }

        int x = 0;
        int y = 0;
        int maxDistance = 0;

        // at first pointing to the north
        pair<int, int> dir = {0, 1};


        for(int i=0; i<commands.size(); i++){
            if(commands[i] == -2){ // turn left 90 degrees
                dir = {-dir.second, dir.first}; // (-y, x)
            }
            else if(commands[i] == -1){ // turn right 90 degrees
                dir = {dir.second, -dir.first};
            }
            else{
                for(int step=0; step < commands[i]; step++){
                    int newX = x + dir.first;
                    int newY = y + dir.second;

                    string newKey = to_string(newX) + "_" + to_string(newY);

                    if(st.find(newKey) != st.end()){
                        break;
                    }

                    x = newX;
                    y = newY;
                }
            }

            maxDistance  = max(maxDistance, x*x + y*y);
        }
        return maxDistance;

    }
};
