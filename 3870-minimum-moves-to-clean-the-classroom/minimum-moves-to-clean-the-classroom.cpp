class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int startX = -1, startY = -1;
        vector<pair<int, int>> litters;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    startX = i;
                    startY = j;
                } else if (classroom[i][j] == 'L') {
                    litters.push_back({i, j});
                }
            }
        }
        
        int numLitters = litters.size();
        int targetMask = (1 << numLitters) - 1;
  
        vector<vector<vector<vector<bool>>>> visited(
            m, vector<vector<vector<bool>>>(
                n, vector<vector<bool>>(
                    energy + 1, vector<bool>(1 << numLitters, false)
                )
            )
        );
        
        queue<tuple<int, int, int, int, int>> q;
        q.push({startX, startY, energy, 0, 0});
        visited[startX][startY][energy][0] = true;
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while (!q.empty()) {
            auto [x, y, curEnergy, mask, moves] = q.front();
            q.pop();
            
            if (mask == targetMask) return moves;

            if (curEnergy == 0) continue;
            
            for (int i = 0; i < 4; ++i) {
                int nx = x + dr[i];
                int ny = y + dc[i];
                
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if (classroom[nx][ny] == 'X') continue;
                
                int nEnergy = curEnergy - 1;
                
                if (classroom[nx][ny] == 'R') {
                    nEnergy = energy;
                }
                
                int nMask = mask;
                if (classroom[nx][ny] == 'L') {
                    for (int idx = 0; idx < numLitters; ++idx) {
                        if (litters[idx].first == nx && litters[idx].second == ny) {
                            nMask |= (1 << idx);
                            break;
                        }
                    }
                }
                
                if (!visited[nx][ny][nEnergy][nMask]) {
                    visited[nx][ny][nEnergy][nMask] = true;
                    q.push({nx, ny, nEnergy, nMask, moves + 1});
                }
            }
        }
        
        return -1;
    }
};