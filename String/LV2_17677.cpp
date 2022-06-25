#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>

// 4:05 ~ 4:51

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    
    // str을 분해해서 2글자씩 저장할 vector    
    vector <string> list1, list2;
    
    // 소문자 변환 후 알파벳만 저장: str1
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    for (int i = 0; i < str1.size()-1; i++) {
        if (isalpha(str1[i]) && isalpha(str1[i+1])) {
            list1.push_back(str1.substr(i, 2));
        }
    }
    // 소문자 변환 후 알파벳만 저장: str2
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    for (int i = 0; i < str2.size()-1; i++) {
        if (isalpha(str2[i]) && isalpha(str2[i+1])) {
            list2.push_back(str2.substr(i, 2));
        }
    }
    
    // 교집합 찾아서 제거, count 증가
    int inter_count = 0;
    
    // list1을 기준으로 list2탐색
    for (auto it1 = list1.begin(); it1 != list1.end();) {
        
        // 교집합 찾기
        auto it2 = find(list2.begin(), list2.end(), *it1);
        
        // 교집합 찾으면 둘 다 삭제 후 교집합 카운트 증가
        if (list2.end() != it2) {
            
            // 찾으면 리스트 2개에서 모두 삭제
            list2.erase(it2);
            it1 = list1.erase(it1);
            
            // 교집합 카운트 증가
            inter_count++;
        }
        
        // 아니라면 계속 탐색
        else {
            it1++;
        }
    }

    // 합집합 구하기
    int union_count = inter_count + list1.size() + list2.size();
    
    // 문제 조건에 따라 교집합 또는 합집합이 없으면 1*65536 출력
    // 비트 연산 주의!
    if (!inter_count && !union_count) return 65536;
    
    // 유사도 구하기
    answer = (int)trunc(((double)inter_count / union_count) * 65536);
    
    return answer;
}
