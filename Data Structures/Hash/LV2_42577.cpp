#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

// time over

// hash로 구현했으므로 1,000,000 * 20

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    // 번호의 존재 여부를 저장할 map
    unordered_map <string, int> phone_map;
    
    for (auto number : phone_book) {
        phone_map[number] = 1;
    }
    
    // 각 번호를 앞에서부터 parsing하여 다른 번호의 접두어가 있는지 확인
    for (int i = 0; i < phone_book.size(); i++) {
        
        // parsing한 번호를 저장할 문자열
        string number = "";
        for (int j = 0; j < phone_book[i].size(); j++) {
            
            number += phone_book[i][j];
            
            // 전체 map중 접두어가 있는지 hash로 확인, 자기 자신은 제외
            if (phone_map[number] && number != phone_book[i]) {
                return false;
            }
        }
    }
    
    return answer;
}
