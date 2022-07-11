#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

// 09:20 ~ 10:05 (실패)

const int maxR = 51;

int R, C, T;

int dY[4] = {0, -1, 0, 1};
int dX[4] = {-1, 0, 1, 0};

vector<pair<int, int>> cleaner;

vector<vector<int>> empty_room;
vector<vector<int>> room;


void Dust(vector<vector<int>>& room) {
    vector<vector<int>> next_room = empty_room;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (room[i][j] > 0) {
                int count = 0;
                for (int k = 0; k < 4; k++) {
                    int ny = i + dY[k];
                    int nx = j + dX[k];

                    if (0 < ny && ny <= R && 0 < nx && nx <= C) {
                        if (room[ny][nx] != -1) {
                            next_room[ny][nx] += (int)(room[i][j] / 5);
                            count++;
                        }
                    }
                }
                next_room[i][j] += (room[i][j] - (int)(room[i][j] / 5) * count);
            }
        }
    }
    room = next_room;
}

void Clean(vector<vector<int>>& room) {
    // clean top
    auto top = cleaner.front();
    for (int i = top.first; i >= 2; i--) {
        room[i][1] = room[i-1][1];
    }
    for (int i = 1; i <= C-1; i++) {
        room[1][i] = room[1][i+1];
    }
    for (int i = 1; i <= top.first-1; i++) {
        room[i][C] = room[i+1][C];
    }
    for (int i = C; i >= 2; i--) {
        room[top.first][i] = room[top.first][i-1];
    }
    room[top.first][2] = 0;
    room[top.first][1] = -1;

    // clean bottom
    auto bottom = cleaner.back();
    for (int i = bottom.first; i >= R-1; i++) {
        room[i][1] = room[i+1][1];
    }
    for (int i = 1; i <= C-1; i++) {
        room[R][i] = room[R][i+1];
    }
    for (int i = R; i > bottom.first; i--) {
        room[i][C] = room[i-1][C];
    }
    for (int i = C; i >= 2; i--) {
        room[bottom.first][i] = room[bottom.first][i-1];
    }
    room[bottom.first][2] = 0;
    room[bottom.first][1] = -1;
}

void p() {
    cout << "\n";
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cout << room[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
	fastio;
    cin >> R >> C >> T;

    vector<vector<int>> first_room(maxR, vector<int>(maxR, 0));
    empty_room = first_room;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> first_room[i][j];
            if (first_room[i][j] == -1) {
                cleaner.push_back({i, j});
                empty_room[i][j] = -1;
            }
        }
    }

    room = first_room;
    while (T--) {
        Dust(room);
        //p();
        Clean(room);
        //p();
    }

    int answer = 2;
    for (auto iter : room) {
        for (auto in_iter : iter) {
            answer += in_iter;
        }
    }
    cout << answer << "\n";
}