class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in(n + 1, 0), out(n + 1, 0);

        for (auto& t : trust) {
            out[t[0]]++;   // t[0] trusts someone
            in[t[1]]++;    // t[1] is trusted
        }

        for (int i = 1; i <= n; i++) {
            if (in[i] == n - 1 && out[i] == 0)
                return i;
        }

        return -1;
    }
};
