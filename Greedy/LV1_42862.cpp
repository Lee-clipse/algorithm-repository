#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void p() {
    
}

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    // 체육복 보유 현황
    vector <int> students (n+1, 1);
    
    // 도난 발생
    for (auto iter : lost) {
        students[iter]--;
    }
    
    // 여분 체육복 찾음
    for (auto iter : reserve) {
        students[iter]++;
    }
    
    // 체육복 나눠주기
    for (int i = 1; i <= n; i++) {
        
        // 체육복이 없으면 양 옆을 조사
        if (students[i] == 0) {
            if (students[i-1] > 1) {
                students[i-1]--;
                students[i]++;
            }
            else if (i+1 <= n && students[i+1] > 1) {
                students[i+1]--;
                students[i]++;
            }
        }
    }

    // 체육수업 가능 인원 조사
    answer = count_if(students.begin()+1, students.end(), [](int i) { return i >= 1; });
    
    
    return answer;
}
