class KthLargest {
public:
    int K;
    priority_queue< int, vector<int>, greater<int> > pq;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(auto i : nums) {
            int n = pq.size();
            if(n < K) {
                pq.push(i);
            }
            else {
                int top = pq.top();
                if(i > top) {
                    pq.pop();
                    pq.push(i);
                }
            }
        }
    }
    
    int add(int val) {
        int n = pq.size();
        if(n < K) {
            pq.push(val);
        }
        else {
            int top = pq.top();
            if(val > top) {
                pq.pop();
                pq.push(val);
            }
        }

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */