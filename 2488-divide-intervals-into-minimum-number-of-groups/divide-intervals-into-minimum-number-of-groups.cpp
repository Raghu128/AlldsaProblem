class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        priority_queue< int , vector<int>, greater<int> > minHeap;

        minHeap.push(0);
        for(auto i : intervals) {
            auto top = minHeap.top(); minHeap.pop();
            auto start = i[0], end = i[1];

            if(top >= start) {
                minHeap.push(top);
            }

            minHeap.push(end);
            
        }

        return minHeap.size();
    }
};