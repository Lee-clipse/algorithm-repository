#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

// 9:23 ~ 9:48 (25)

bool isOver(deque<int> d1, deque<int> d2, int K) {
    int count = 0;
    for (auto d : d1) {
        if (d == 0) count++;
    }
    for (auto d : d2) {
        if (d == 0) count++;
    }

    return (count >= K);
}

int main() {
	fastio;
    int N, K;
    cin >> N >> K;

    // 벨트 내구도
    deque<int> A_top, A_btm;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A_top.push_back(a);
    }
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A_btm.push_front(a);
    }

    // top의 로봇 상태 저장
    deque<int> robot(N, 0);

    int turn = 0;
    while (!isOver(A_top, A_btm, K)) {
        turn++;

        // 1
        A_top.push_front(A_btm.front());
        A_btm.push_back(A_top.back());
        A_top.pop_back();
        A_btm.pop_front();

        robot.push_front(robot.back());
        robot.pop_back();
        robot.back() = 0;

        // 2
        for (int i = N-1; i >= 0; i--) {
            if (robot[i] - robot[i+1] == 1 && A_top[i+1] >= 1) {
                robot[i+1] = 1;
                robot[i] = 0;
                A_top[i+1]--;
            }
        }
        robot.back() = 0;
        
        // 3
        if (A_top.front() != 0) {
            A_top.front()--;
            robot.front() = 1;
        }
    }

    cout << turn << "\n";
}