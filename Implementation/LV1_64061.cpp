#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    int N = board[0].size();
    
    // 바구니를 stack으로 구현
    stack<int> basket;
    
    for (auto pos : moves) {
        
        // 집게에 잡힌 인형
        int picked = 0;
        
        // 집게로 집기        
        for (int i = 0; i < N; i++) {
            if (board[i][pos-1] != 0) {
                picked = board[i][pos-1];
                board[i][pos-1] = 0;
                break;
            }
        }
        
        // 집은 것과 바구니의 맨 위의 것을 비교하여 같다면
        if (!basket.empty() && picked == basket.top()) {
            basket.pop();
            answer += 2;
        }
        
        // 바구니에 담기
        else {
            
            // 0이 아닌 인형만 바구니에 담기
            if (picked != 0) {
                basket.push(picked);   
            }
        }
    }
    
    return answer;
}
