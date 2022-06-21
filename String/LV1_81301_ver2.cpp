#include <string>
#include <vector>
#include <regex>
#include <algorithm>

using namespace std;

// 영단어 리스트  
string word_list[10] = 
{"zero", "one", "two", "three", "four", 
 "five", "six", "seven", "eight", "nine"};


int solution(string s) {
    int answer = 0;
    
    // zero부터 nine까지 10번 돌며 해당 문자열을 찾아 대체한다
    for (int i = 0; i < 10; i++) {
        s = regex_replace(s, regex(word_list[i]), to_string(i));
    }
    
    answer = stoi(s);
    return answer;
}
