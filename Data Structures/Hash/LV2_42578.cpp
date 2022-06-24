#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>

// 7:25 ~ 7:34

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    // (의상의 종류 - 의상)을 저장할 map
    map <string, set<string>> closet;
    
    // 의상을 종류별로 map의 set에 저장
    for (auto costume : clothes) {
        closet[costume[1]].insert(costume[0]);
    }
    
    // 서로 다른 의상의 경우의 수 구하기
    for (auto dress : closet) {
        answer *= (dress.second.size() + 1);
    }
    
    answer--;
    
    return answer;
}
