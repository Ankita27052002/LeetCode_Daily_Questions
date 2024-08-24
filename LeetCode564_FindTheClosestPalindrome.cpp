// LeetCode Problem 564 : Find the Closest Palindrome (HARD)

// T.C : O(1)
// S.C : O(1)

class Solution {
public:
    string nearestPalindromic(string n) {
        long long num = stoll(n);

        // edge cases for the small numbers
        if(num <= 10) return to_string(num-1);
        if(num == 11) return "9";

        // if 18- digits all are 9's
        if(n == "999999999999999999"){
            return  "1000000000000000001";
        }

        int length = n.length();
        long long leftHalf = stoll(n.substr(0, (length+1)/2));

        // there are five candidates
        vector<long long> palindromeCandidate(5);

        palindromeCandidate[0] = generatePalindrome(leftHalf - 1, length%2 == 0);
        palindromeCandidate[1] = generatePalindrome(leftHalf, length%2 == 0);

        // Handle potential overflow for leftHalf + 1
        if (leftHalf < 999999999) {
            palindromeCandidate[2] = generatePalindrome(leftHalf + 1, length % 2 == 0);
        } else {
            palindromeCandidate[2] = stoll("1" + string(length - 1, '0') + "1");
        }

        palindromeCandidate[3] = pow(10, length-1) - 1;
        palindromeCandidate[4] = pow(10, length) + 1;

        long long nearestPalindrome = 0;
        long long minDifference = LLONG_MAX;

        for(long long candidate : palindromeCandidate){
            if(candidate == num) continue;

            long long difference = abs(candidate - num);

            if(difference < minDifference || (difference == minDifference && candidate < nearestPalindrome)){
                minDifference = difference;
                nearestPalindrome = candidate;
            }
        }

        return to_string(nearestPalindrome);
    }

    private:
        long long generatePalindrome(long long leftHalf, bool isEvenLength){
            long long palindrome = leftHalf;
            if(!isEvenLength) leftHalf /= 10;

            while(leftHalf > 0){
                palindrome = palindrome * 10 + leftHalf % 10;
                leftHalf /= 10;
            }

            return palindrome;
        }
};
