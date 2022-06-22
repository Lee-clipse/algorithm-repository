#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (auto command : commands) {
        
        // 임시 저장 배열
        vector <int> temp = array;
        
        // i, j, k 추출
        int i = command[0];
        int j = command[1];
        int k = command[2];
        
        // i ~ j 정렬
        sort(temp.begin() + i-1, temp.begin() + j);
        
        // 정답 저장
        answer.push_back(temp[i+k-2]);
    }
    
    return answer;
}
