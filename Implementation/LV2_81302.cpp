#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

// 9:15 ~ 9:54 (39)

int visited[5][5];

int dY[4] = {0, -1, 0, 1};
int dX[4] = {-1, 0, 1, 0};

bool BFS (vector<string> place, int y, int x) {
    memset(visited, -1, sizeof(visited));
    
    queue <pair<int, int>> Q;
    Q.push({y, x});
    visited[y][x] = 0;
    
    while (!Q.empty()) {
        int yy = Q.front().first;
        int xx = Q.front().second;
        Q.pop();
        
        for (int i = 0; i < 4; i++) {
            int ny = yy + dY[i];
            int nx = xx + dX[i];
            
            // 범위 내의 칸 중에서 방문하지 않은 X가 아닌 칸을 조사
            if (0 <= ny && ny < 5 && 0 <= nx && nx < 5 && visited[ny][nx] == -1 && place[ny][nx] != 'X') {

                // 맨해튼 거리가 2이하인데 사람이 있으면 거리두기 실패
                if (visited[yy][xx] <= 1 && place[ny][nx] == 'P') return false;
                    
                Q.push({ny, nx});
                visited[ny][nx] = visited[yy][xx] + 1;
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    // 대기실을 차례대로 조사
    for (int p = 0; p < places.size(); p++) {
        
        auto place = places[p];
        
        int result = 1;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                
                // 사람이 있는 칸을 중심으로 조사를 했는데 거리두기를 지키지 않은 경우
                if (place[i][j] == 'P' && !BFS(place, i, j)) {
                    result = 0;
                    break;
                }
            }
            if (!result) break;
        }
        answer.push_back(result);
    }
    
    
    return answer;
}
