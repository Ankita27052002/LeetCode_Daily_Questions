// LeetCode Problem 592 : Fraction and Substraction (Medium)

// T.C : O(n)
// S.C : O(1)

class Solution {
public:
    string fractionAddition(string expression) {
        int numerator = 0;
        int denominator = 1;

        int i=0;
        int n = expression.length();

        while(i<n){
            int currNume = 0;
            int currDeno = 0;

            bool isNeg = (expression[i] == '-');

            if(expression[i] == '-' || expression[i] == '+') i++;

            // fetching the current numerator
            while(i<n && isdigit(expression[i])){
                int val = expression[i] - '0';
                currNume = (currNume * 10) + val;
                i++;
            }
            i++; // skipping the divisor character '/'

            if(isNeg == true){
                currNume *= -1;
            }

            //fetching the current denominator
            while(i<n && isdigit(expression[i])){
                int val = expression[i] - '0';
                currDeno = (currDeno * 10) + val;
                i++;
            }

            numerator = numerator * currDeno + currNume * denominator;
            denominator = denominator * currDeno;

        }

        // make it simplified
        int GCD = abs(__gcd(numerator, denominator));

        // divide the numerator and denominator by GCD
        numerator /= GCD;
        denominator /= GCD;

        return to_string(numerator) + "/" + to_string(denominator);
    }
};
