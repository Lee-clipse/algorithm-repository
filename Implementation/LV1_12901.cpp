#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 4:27 ~ 4:41

string solution(int a, int b) {
    string answer = "";
    
    // 월 별 날짜수
    int days[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    string week[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    
    // 일 + 1월부터 a월까지 월 별 날짜수
    int day_sum = b-1;
    for (int i = 1; i < a; i++) {
        day_sum += days[i];
    }
    
    answer = week[(day_sum + 5) % 7];
    
    return answer;
}
