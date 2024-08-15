// LeetCode Problem 860 : Lemonade Change (Easy)
// T.C : O(n)
// S.C : O(1)

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveDollar = 0, tenDollar = 0;

        for(int it: bills){
            if(it == 5){
                fiveDollar++;
            }
            else if(it == 10){
                if(fiveDollar > 0){
                    fiveDollar--;
                    tenDollar++;
                } else{
                    return false;
                }
            }
            else{
                if(fiveDollar > 0 && tenDollar > 0){
                    fiveDollar--;
                    tenDollar--;
                }
                else if(fiveDollar > 2){
                    fiveDollar -= 3;
                }
                else{
                    // if we have no five dollar and ten dollar
                    return false;
                }
            }
        }
        return true;
    }
};
