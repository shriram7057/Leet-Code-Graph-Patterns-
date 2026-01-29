class Solution {
public:
    unordered_map<string, string> parent;

    string find(string x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(string a, string b) {
        string pa = find(a);
        string pb = find(b);
        if (pa != pb)
            parent[pb] = pa;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> emailToName;

        // 1️⃣ Initialize DSU
        for (auto& acc : accounts) {
            string name = acc[0];
            for (int i = 1; i < acc.size(); i++) {
                string email = acc[i];
                if (!parent.count(email))
                    parent[email] = email;
                emailToName[email] = name;
            }
        }

        // 2️⃣ Union emails within same account
        for (auto& acc : accounts) {
            string firstEmail = acc[1];
            for (int i = 2; i < acc.size(); i++) {
                unite(firstEmail, acc[i]);
            }
        }

        // 3️⃣ Group emails by root
        unordered_map<string, vector<string>> groups;
        for (auto& [email, _] : parent) {
            groups[find(email)].push_back(email);
        }

        // 4️⃣ Build result
        vector<vector<string>> res;
        for (auto& [root, emails] : groups) {
            sort(emails.begin(), emails.end());
            vector<string> account;
            account.push_back(emailToName[root]);
            account.insert(account.end(), emails.begin(), emails.end());
            res.push_back(account);
        }

        return res;
    }
};
