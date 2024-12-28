class Solution {
private:
    int findParent(vector<int>& arr, int a) {
        if(arr[a] == a) return a;
        return findParent(arr, arr[a]);
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> parent(n+1), store(n+1, INT_MAX);
        for(int i = 0; i <= n; i++)  parent[i] = i;

        for(auto i : roads) {
            int a = min(i[0], i[1]), b = max(i[0], i[1]);
            int dis = i[2];
            int aParent = findParent(parent, a), bParent = findParent(parent, b);
            a = min(aParent, bParent), b = max(aParent, bParent);
            cout <<  a << " " << b << endl;
            parent[b] = a;
            store[a] = min(min(store[a], store[b]), dis);
        }

        return store[1];
    }
};