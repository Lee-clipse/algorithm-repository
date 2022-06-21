#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

// 영단어 배열
string word_list[10] = 
{"zero", "one", "two", "three", "four", 
 "five", "six", "seven", "eight", "nine"};


int solution(string s) {
    int answer = 0;
    
    // 영단어와 숫자를 저장할 map
    map<string, int> str_to_num_map;
    
    // word_list를 바탕으로 map에 저장
    for (int i = 0; i < 10; i++) {
        str_to_num_map[word_list[i]] = i;
    }
    
    int num  = 0;
    string word = "";
    for (auto c : s) {
        
        // 숫자라면 num에 저장
        if (isdigit(c)) {
            num *= 10;
            num += (c - '0');
        }
        
        // 단어 저장
        else {
            word += c;
            
            // word가 완성되면 num에 갱신
            if (str_to_num_map.find(word) != str_to_num_map.end()) {
                int str_num = str_to_num_map[word];
                
                num *= 10;
                num += str_num;
                
                word = "";
            }
        }
    }
    
    answer = num;
    return answer;
}
