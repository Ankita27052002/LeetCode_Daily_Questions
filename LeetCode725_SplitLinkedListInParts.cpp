// LeetCode Problem 725 : Split Linked List in Parts (Medium) asked by [Amazon, Google]

// T.C : O(L+k) --You are traversing the input linkedlist only once and the array of size k only once
// or it can be O(k * L/k + x) -- each bucket will have L/k nodes
// S.C : O(1) -- Not considering the result vector

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr = head;
        int L= 0;

        while(curr){
            L++;
            curr = curr->next;
        }

        int mustNodesInBucket = L/k;
        int remainderNodes = L%k;

        vector<ListNode*> result(k, NULL);
        curr = head;
        ListNode* prev = NULL;

        for(int i=0; curr && i<k; i++){
            result[i] = curr;

            for(int count=1; count <= mustNodesInBucket + (remainderNodes > 0 ? 1:0); count++){
                prev = curr;
                curr = curr->next;

            }

            prev->next = NULL;
            remainderNodes--;
        }

        return result;
    }
};
