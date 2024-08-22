// LeetCode Problem 476 : Number Complement (Easy)

// T.C : O(log2(num))

class Solution {
public:
    int findComplement(int num) {
       // Find the length of the num
       int numOfBits = (int) (log2(num))+1;

       for(int i=0;i<numOfBits; i++){
        num = num ^ (1<<i); // do the xor operation 
       } 

       return num;
    }
};

//------------------------------------------------------------------------------------------
// Approach - 2

class Solution {
public:
    int findComplement(int num) {
        int numOfBits = (int)(log2(num))+1;

       unsigned int mask = (1U << numOfBits)-1;
        // 2^3 - 1 = 7
        // so mask will be 111

        return (num ^ mask);
    }
};

//-----------------------------------------------------------------------------------------
// Approach - 3
// T.C : O(log2(num))

class Solution {
public:
    int findComplement(int num) {
        int i = 0;
        int complement = 0;

        while(num){
            if(!(num & 1)){ // if it's not zero then filp it
                complement = complement | (1<<i);

            }
            num = num >> 1;
            i++;
        }
        return complement;
    }
};
