// LeetCode Problem 703 : Kth Largest Element in a Stream  (Easy)

// T.C : O(n log n)  --- For KthLargest insertion take O(log k) time each time to build the heap and we do it for n times
//                       each call to add takes O(log k)

class KthLargest {
    int num;
    priority_queue<int, vector<int>, greater<int>> pq;
        
public:
    KthLargest(int k, vector<int>& nums) {
        num = k;
        for(auto it: nums){
            pq.push(it);
            if(pq.size() > k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > num) pq.pop();
        return pq.top();
    }
};
