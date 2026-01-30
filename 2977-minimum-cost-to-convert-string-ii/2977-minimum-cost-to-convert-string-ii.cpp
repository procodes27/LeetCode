class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        const long long INF = 1e18;
        unordered_map<string, int> id;
        int idx = 0;
        for (auto& s : original) if (!id.count(s)) id[s] = idx++;
        for (auto& s : changed) if (!id.count(s)) id[s] = idx++;
        int n = idx;
        vector<vector<long long>> dist(n, vector<long long>(n, INF));
        for (int i = 0; i < n; i++) dist[i][i] = 0;
        for (int i = 0; i < original.size(); i++) {
            int u = id[original[i]];
            int v = id[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        int m = source.size();
        vector<long long> dp(m + 1, INF);
        dp[m] = 0;
        for (int i = m - 1; i >= 0; i--) {
            if (source[i] == target[i]) dp[i] = dp[i + 1];
            for (auto& p : id) {
                const string& s1 = p.first;
                int len = s1.size();
                if (i + len > m) continue;
                if (source.compare(i, len, s1) != 0) continue;
                for (auto& q : id) {
                    const string& s2 = q.first;
                    if ((int)s2.size() != len) continue;
                    if (target.compare(i, len, s2) != 0) continue;
                    long long c = dist[p.second][q.second];
                    if (c < INF && dp[i + len] < INF)
                        dp[i] = min(dp[i], c + dp[i + len]);
                }
            }
        }
        return dp[0] >= INF ? -1 : dp[0];
    }
};
