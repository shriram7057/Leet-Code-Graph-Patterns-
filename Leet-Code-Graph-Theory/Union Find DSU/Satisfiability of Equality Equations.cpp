class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py)
            parent[px] = py;
    }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        for (int i = 0; i < 26; i++)
            parent[i] = i;

        // Step 1: handle all equality equations
        for (auto &eq : equations) {
            if (eq[1] == '=') {
                int x = eq[0] - 'a';
                int y = eq[3] - 'a';
                unite(x, y);
            }
        }

        // Step 2: handle all inequality equations
        for (auto &eq : equations) {
            if (eq[1] == '!') {
                int x = eq[0] - 'a';
                int y = eq[3] - 'a';
                if (find(x) == find(y))
                    return false;
            }
        }

        return true;
    }
};
