class Solution {
public:

    int findParent(int node, vector<int>& parent) {
        if(node == parent[node])
            return node;

        return parent[node] = findParent(parent[node], parent);
    }

    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {

        int pu = findParent(u, parent);
        int pv = findParent(v, parent);

        if(rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else if(rank[pv] < rank[pu]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        vector<int> parent(n + 1);
        vector<int> rank(n + 1, 0);

        for(int i = 1; i <= n; i++)
            parent[i] = i;

        for(auto &e : edges) {

            int u = e[0];
            int v = e[1];

            int pu = findParent(u, parent);
            int pv = findParent(v, parent);

            if(pu == pv)
                return e;

            unionSet(u, v, parent, rank);
        }

        return {};
    }
};