#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    // 수포자의 정답 패턴
    int list_1[5] = {1, 2, 3, 4, 5};
    int list_2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int list_3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    // 수포자 정답 카운트 배열
    vector <int> correct_list = {0, 0, 0};
    
    // 정답 비교
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == list_1[i % 5]) {
            correct_list[0]++;
        }
        if (answers[i] == list_2[i % 8]) {
            correct_list[1]++;
        }
        if (answers[i] == list_3[i % 10]) {
            correct_list[2]++;
        }
    }
    
    // 최대 정답 수
    int max_correct = *max_element(correct_list.begin(), correct_list.end());
    
    // 정답 출력
    for (int i = 0; i < 3; i++) {
        if (max_correct == correct_list[i]) {
            answer.push_back(i+1);
        }
    }
    
    return answer;
}
