class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size(), Q = queries.size();
        vector<int> result(Q, 0);
        vector<pair<int, int>> sortedQ; 

        for (int i = 0; i < Q; i++)
            sortedQ.emplace_back(queries[i], i);

        sort(sortedQ.begin(), sortedQ.end());  
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        int points = 0;

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (auto &[queryValue, idx] : sortedQ) {
            while (!pq.empty() && pq.top()[0] < queryValue) {
                auto top = pq.top();
                pq.pop();
                int x = top[1], y = top[2];
                points++;

                for (auto &[dx, dy] : directions) {
                    int i_ = x + dx, j_ = y + dy;
                    if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_]) {
                        pq.push({grid[i_][j_], i_, j_});
                        visited[i_][j_] = true;
                    }
                }
            }
            result[idx] = points;
        }

        return result;
    }
};