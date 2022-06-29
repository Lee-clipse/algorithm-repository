#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

// 11:21 ~ 12:08 (47: 9번 테케만 틀림)
// 12:10 ('Z'도 입력으로 들어온다는 조건 다시 읽어 통과)

bool doErase(vector<string>& board) {
    
    // 지워질 블록이 있는지 판별하는 sign
    bool erase_sign = false;
    vector<string> temp = board;
    
    for (int i = 0; i < board.size()-1; i++) {
        for (int j = 0; j < board[i].size()-1; j++) {
            if (board[i][j] != '*' && board[i][j] == board[i][j+1] && board[i][j] == board[i+1][j] && board[i][j] == board[i+1][j+1]) {
                temp[i][j] = temp[i][j+1] = temp[i+1][j] = temp[i+1][j+1] = '*';
                erase_sign = true;
            }
        }
    }
    
    board = temp;
    return erase_sign;
}


int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    // 더이상 지워질 블럭이 없을 때까지 실행
    while (doErase(board)) {

        vector <string> temp(n);
        
        // 블럭이 지워진 후 위에 있는 블록이 아래로 떨어진다
        // 가로 - 세로를 뒤바꿔서 temp에 저장한다
        for (int i = m-1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != '*') {
                    temp[j] += board[i][j];
                }
                board[i][j] = '*';
            }
        }
        
        // 가로 - 세로가 뒤바뀐 temp를 다시 board에 올바르게 저장한다
        for (int i = 0; i < temp.size(); i++) {
            for (int j = 0; j < temp[i].size(); j++) {
                board[m-1-j][i] = temp[i][j];
            }
        }
    }
    
    // 지금까지 지워진 블록의 수를 카운팅
    for (auto iter : board) {
        for (auto in_iter : iter) {
            if (in_iter == '*') {
                answer++;
            }
        }
    }
    
    return answer;
}
