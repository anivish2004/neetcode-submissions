class Solution {
   public:
    vector<int> parent, rankv;

    int findParent(int x) {
        if (parent[x] == x) return x;
        return parent[x] = findParent(parent[x]);
    }

    bool unionSet(int a, int b) {
        int pa = findParent(a);
        int pb = findParent(b);

        if (pa == pb) return false;  // cycle

        if (rankv[pa] < rankv[pb]) {
            parent[pa] = pb;
        } else if (rankv[pa] > rankv[pb]) {
            parent[pb] = pa;
        } else {
            parent[pb] = pa;
            rankv[pa]++;
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;

        parent.resize(n);
        rankv.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            if (!unionSet(u, v)) {
                return false;  // cycle found
            }
        }

        return true;
    }
};