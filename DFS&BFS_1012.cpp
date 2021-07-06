#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int maxN = 50;

int T, N, M, K;
int X, Y;
int map[maxN][maxN];
bool visited[maxN][maxN];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void Input ()
{
    memset(visited, 0, sizeof(visited));
    memset(map, 0, sizeof(map));

    cin >> M >> N >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> X >> Y;
        map[Y][X] = 1;
    }
}

void BFS (int y, int x)
{
    queue < pair <int, int> > q;

    visited[y][x] = true;
    q.push({y, x});

    while (!q.empty())
    {
        int yy = q.front().first;
        int xx = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = yy + dy[i];
            int nx = xx + dx[i];

            if (0<=ny && ny<N && 0<=nx && nx<M
                && map[ny][nx] == 1 && !visited[ny][nx])
            {
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }
}

void Solution ()
{
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == 1 && !visited[i][j])
            {
                BFS(i, j);
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}

void Solve ()
{
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        Input();
        Solution();
    }
}

int main ()
{
    Solve();

    return 0;
}
