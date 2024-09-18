// LeetCode Problem 179 : Largest Number (Medium)

// T.C : O(nlogn)
// S.C : O(ans.size)

 bool compare(int a, int b){
        string stra = to_string(a);
        string strb = to_string(b);

        if((stra + strb) > (strb + stra)){
            return true;
        }
        return false;
    }
class Solution {
public:
   
    string largestNumber(vector<int>& nums) {
        // sort nums using custome comapre function
        sort(nums.begin(), nums.end(), compare);

        if(nums[0] == 0) return "0";

        string ans = "";
        for(int num: nums){
            ans += to_string(num);
        }

        return ans;

    }
};
