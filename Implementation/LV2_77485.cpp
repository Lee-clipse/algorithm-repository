#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 9:04 ~ 9:34 (30)

int arr[101][101];

int getRotate(vector<int> pos) {
    int y1 = pos[0], x1 = pos[1], y2 = pos[2], x2 = pos[3];

    // 100001보다 직관적이고 안전함
    int min_num = arr[y1][x1];
    int temp = arr[y1][x2];
    //cout << temp << " => (";
    
    for (int i = x2; i > x1; i--) {
        min_num = min(min_num, arr[y1][i]);
        arr[y1][i] = arr[y1][i-1];
    }
    for (int i = y1; i < y2; i++) {
        min_num = min(min_num, arr[i][x1]);
        arr[i][x1] = arr[i+1][x1];
    }
    for (int i = x1; i < x2; i++) {
        min_num = min(min_num, arr[y2][i]);
        arr[y2][i] = arr[y2][i+1];
    }
    for (int i = y2; i > y1; i--) {
        min_num = min(min_num, arr[i][x2]);
        arr[i][x2] = arr[i-1][x2];
    }
    //cout << y1+1 << ", " << x2 << ")\n";
    arr[y1+1][x2] = temp;
    
    return min_num;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    // i*row + j 이거말고 num++ 하니까 통과되네
    int num = 1;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            arr[i][j] = num++;
        }
    }

    // 회전 후 가장 작은 값을 담음
    for (int i = 0; i < queries.size(); i++) {
        answer.push_back(getRotate(queries[i]));
    }
    
    return answer;
}
