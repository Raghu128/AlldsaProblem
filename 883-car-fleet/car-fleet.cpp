class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack< double > st;
        priority_queue< pair<double,double> > pq;

        int ans = 0;

        int n = position.size();
        for(int i = 0; i < n; i++) pq.push({position[i], speed[i]});

        while(!pq.empty()) {
            pair<double,double> top = pq.top(); pq.pop();
            cout << top.first << endl;

            double time = (target-top.first)/top.second*1.0;

            
            if(st.empty() || st.top() < time) st.push(time);
            
            ans = max(ans, (int)st.size()); 
        }

        return ans;
    }
};