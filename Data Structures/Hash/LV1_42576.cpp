#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    // participant를 저장할 map
    // 일반 map보다 탐색이 빠르므로 hash 저장에 적합한 자료구조
    unordered_map <string, int> name_map;
    
    // participant를 map에 저장
    for (auto iter : participant) {
        auto it = name_map.find(iter);
        
        // participant 등록
        if (it == name_map.end()) {
            name_map[iter] = 1;
        }
        
        // 동명이인이라면 그 수를 저장
        else {
            name_map[iter]++;
        }
    }
    
    // completion을 map에서 체크
    for (auto iter : completion) {
        name_map[iter]--;
    }
    
    // map에 남은 participant가 완주하지 못한 사람
    for (auto iter : name_map) {
        if (iter.second > 0) {
            answer = iter.first;
            break;
        }
    }
    
    
    return answer;
}
