#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include <algorithm>

using namespace std;

// 2:13 ~ 2:38 (25)

bool mySort (const pair<int, pair<string, int>>& a, const pair<int, pair<string, int>>& b) {
    if (a.second.first == b.second.first) {
        if (a.second.second == b.second.second) {
            return a.first < b.first;
        }
        else {
            return a.second.second < b.second.second;
        }
    }
    else {
        return a.second.first < b.second.first;
    }
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    // 인덱스, <HEAD, NUMBER>
    vector<pair<int, pair<string, int>>> file_list;
    
    for (int i = 0; i < files.size(); i++) {
        
        string head, num_str, tail;
        int idx = 0;
        
        // HEAD 소문자로 통일해서 만들기
        while (!isdigit(files[i][idx])) {
            head += tolower(files[i][idx++]);
        }
        
        // NUMBER 만들기
        while (isdigit(files[i][idx])) {
            num_str += files[i][idx++];
        }
        
        // TAIL 만들기
        tail = files[i].substr(idx);
        
        file_list.push_back({i, {head, stoi(num_str)}});
    }
    
    // HEAD - NUMBER - INDEX 순으로 정렬
    sort(file_list.begin(), file_list.end(), mySort);

    // 정렬된 file_list의 인덱스 순서 그대로 출력
    for (int i = 0; i < file_list.size(); i++) {
        answer.push_back(files[file_list[i].first]);
    }

    return answer;
}
