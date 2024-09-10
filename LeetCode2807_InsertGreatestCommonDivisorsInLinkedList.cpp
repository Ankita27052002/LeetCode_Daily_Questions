// LeetCode Problem 2807 : Insert Greatest Common Divisors in Linked List (Medium)

// Approach 1 : Iterative
// T.C : O(n)
// S.C : O(1)

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* currNode = head;
        ListNode* nextNode = head->next;

        while(nextNode){
            ListNode* temp = new ListNode(__gcd(currNode->val, nextNode->val ));

            currNode->next = temp;
            temp->next = nextNode;

            currNode = nextNode;
            nextNode = nextNode->next;
        }

        return head;

    }
};


//------------------------------------------------------------------------------------------------------------------------

// Approach 2 : Recursive
// T.C : O(n)
// T.C : O(1) -- not considering the recursion stack space

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        
        ListNode* temp = insertGreatestCommonDivisors(head->next); // have faith that it will return the answer of rset part

        // Create a new node with the GCD of current and next node values
        ListNode* gcdNode = new ListNode(__gcd(head->val, head->next->val));

         // Insert the new node between the current node and the next node
         gcdNode->next = temp;
         head->next = gcdNode;

         return head;



    }
};
 
