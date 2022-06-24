#include <string>
#include <vector>
#include <iostream>

// 8:05 ~ 8:14

using namespace std;

int N, T;
int count = 0;
vector <int> tree;

void makeTarget(int pos, int num) {
    
    // 끝까지 돌았을 때
    if (pos == N) {
        if (num == T) count++;
        return ;
    }
    
    // 빼기
    makeTarget(pos+1, num + tree[pos]);
    
    // 더하기
    makeTarget(pos+1, num - tree[pos]);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    // 전역변수
    N = numbers.size();
    T = target;
    tree = numbers;
    
    // 메인 함수
    makeTarget(0, 0);
    
    answer = count;
    return answer;
}
