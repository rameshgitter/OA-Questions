#include <vector>
#include <queue>

using namespace std;

int getMinimumMoves(vector<vector<int>> maze, int k) {
    if (maze.empty() || maze[0][0] == 1) return -1;
    
    int n = maze.size();
    int m = maze[0].size();
    
    if (n == 1 && m == 1) return 0;

    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;

    q.push({0, 0});
    dist[0][0] = 0;

    int dr[] = {0, 0, 1, -1};
    int dc[] = {1, -1, 0, 0};

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        int r = cur.first;
        int c = cur.second;

        for (int i = 0; i < 4; i++) {
            for (int step = 1; step <= k; step++) {
                int nr = r + dr[i] * step;
                int nc = c + dc[i] * step;

                if (nr < 0 || nr >= n || nc < 0 || nc >= m || maze[nr][nc] == 1) {
                    break;
                }

                if (dist[nr][nc] != -1 && dist[nr][nc] <= dist[r][c]) {
                    break;
                }

                if (dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                    if (nr == n - 1 && nc == m - 1) return dist[nr][nc];
                }
            }
        }
    }

    return dist[n - 1][m - 1];
}
