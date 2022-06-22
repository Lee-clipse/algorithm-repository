#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    // 해석한 지도
    vector <int> true_map;
    
    // 두 지도를 대조하여 해석
    for (int i = 0; i < n; i++) {
        true_map.push_back(arr1[i] | arr2[i]);   
    }
    
    // true_map에 '#', ' ' 로 표시
    for (int i = 0; i < n; i++) {
        stack <char> temp;
        
        int num = true_map[i];
        
        // 비트마스킹으로 켜진 비트 확인하여 변환
        for (int j = 0; j < n; j++) {
            if (num & 1) {
                temp.push('#');
            }
            else {
                temp.push(' ');
            }
            num = num >> 1;
        }
        
        // 스택에 저장한 '#', ' '을 뽑아서 answer에 저장
        string str = "";
        while (!temp.empty()) {
            str += temp.top();
            temp.pop();
        }
        
        answer.push_back(str);
    }
    
    return answer;
}
