#include <vector>
#include <queue>
#include <cstring>
#include <iostream>

#define maxN 101

using namespace std;

vector <vector<int>> book;

bool visited[maxN][maxN];

int dY[4] = {0, -1, 0, 1};
int dX[4] = {-1, 0, 1, 0};

int N, M;


int BFS(int y, int x, int color) {
    queue <pair<int, int>> Q;
    
    visited[y][x] = true;
    Q.push({y, x});
    
    int count = 1;
    
    while (!Q.empty()) {
        int yy = Q.front().first;
        int xx = Q.front().second;
        
        Q.pop();
        
        for (int i = 0; i < 4; i++) {
            int ny = yy + dY[i];
            int nx = xx + dX[i];
            
            if (0 <= ny && ny < M && 0 <= nx && nx < N && !visited[ny][nx] && book[ny][nx] == color) {
                Q.push({ny, nx});
                visited[ny][nx] = true;
                count++;
            }
        }
    }
    
    return count;
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    book = picture;
    memset(visited, 0, sizeof(visited));
    N = n, M = m;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && picture[i][j] != 0) {
                max_size_of_one_area = max(max_size_of_one_area, BFS(i, j, picture[i][j]));
                number_of_area++;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
