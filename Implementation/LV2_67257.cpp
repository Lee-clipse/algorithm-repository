#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cctype>

using namespace std;

// 11:31 ~ 12:12 포기

// 연산 함수
long long doCalculate(long long a, long long b, char op) {
    long long result;
    
    if (op == '*') result = a * b;
    if (op == '+') result = a + b;
    if (op == '-') result = a - b;
    
    return result;
}

long long calculateExpression(string expression, vector <char> oper) {
    
    // 피연산자, 연산자를 저장할 벡터
    vector <pair<long long, char>> V;
    
    // 벡터에 피연산자, 연산자를 저장
    long long num = 0;
    for (int i = 0; i < expression.size(); i++) {
        if (isdigit(expression[i])) {
            num = num * 10 + (expression[i] - '0');
        }
        else {
            V.push_back({num, expression[i]});
            num = 0;
        }
    }
    if (num != 0) V.push_back({num, ' '});
    
    // 우선순위에 따라 연산자 하나씩 총 3번 실행하여 벡터를 갱신함
    auto nV = V;
    for (int i = 0; i < oper.size(); i++) {
        
        // nV는 다음 식을 저장할 벡터
        V = nV; 
        nV.clear();
        
        // 원하는 연산자를 찾아서 연산중이고, 이제 저장해야 한다면 true
        bool flag = false;
        
        for (int j = 0; j < V.size(); j++) {
            long long cur = V[j].first;
            
            // 원하는 연산자를 찾음
            if (V[j].second == oper[i]) {
                
                // 이전에 연산한 값이 있다면 그 값과 현재 값을 연산
                if (flag) cur = num;
                
                // 원하는 연산자를 찾아 연산했으므로 flag를 true로 켬
                num = doCalculate(cur, V[j+1].first, oper[i]);
                flag = true;
            }
            
            // 다른 연산자를 찾았다면 pass
            else {
                
                // 이전에 연산하던 값이 있다면 그 값도 같이 nV에 넣음
                if (flag) cur = num;
                
                nV.push_back({cur, V[j].second});
                num = 0; flag = false;
            }
        }
    }
    
    return nV.front().first;
}

long long solution(string expression) {
    long long answer = 0;
    
    vector <char> oper = {'*', '+', '-'};
    
    // 우선순위를 순열로 돌려서 6가지 경우를 계산
    do {
        answer = max(answer, abs(calculateExpression(expression, oper)));
        
    } while (next_permutation(oper.begin(), oper.end()));
    
    return answer;
}
