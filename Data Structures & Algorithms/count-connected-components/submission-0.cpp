class Solution {
public:
    vector<int> parent, rankv;

    int findParent(int x) {
        if (parent[x] == x) return x;
        return parent[x] = findParent(parent[x]);
    }

    void unionSet(int a, int b, int &components) {
        int pa = findParent(a);
        int pb = findParent(b);

        if (pa == pb) return; 

        if (rankv[pa] < rankv[pb]) {
            parent[pa] = pb;
        } else if (rankv[pa] > rankv[pb]) {
            parent[pb] = pa;
        } else {
            parent[pb] = pa;
            rankv[pa]++;
        }

        components--;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rankv.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int components = n;

        for (auto &e : edges) {
            unionSet(e[0], e[1], components);
        }

        return components;
    }
};