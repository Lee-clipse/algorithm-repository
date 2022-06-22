#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    // 탐색을 위한 정렬
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    // 투 포인터 느낌으로 동시 탐색
    for (int i = 0; i < completion.size(); i++) {
        if (participant[i] != completion[i]) {
            answer = participant[i];
            break;
        }
    }
    
    // 마지막까지 봤는데 못찾았다면, 마지막 참가자가 정답
    if (answer == "") {
        answer = participant.back();
    }
    
    return answer;
}
