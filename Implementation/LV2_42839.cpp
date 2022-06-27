#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

// 1:43 ~ 2:01

// 소수면 1 반환, 아니면 0 반환
int isPrime (int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int solution(string numbers) {
    int answer = 0;
    
    // 종이 쪼가리 붙인거 저장할 set
    set <int> num_set;
    
    // 순열 생성을 위해 정렬
    sort(numbers.begin(), numbers.end());
    
    // 종이 붙여가며 중복 제거
    do {
        for (int i = 1; i <= numbers.size(); i++) {
            num_set.insert( stoi(numbers.substr(0, i)) );
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    // 0, 1은 버리기
    num_set.erase(0);
    num_set.erase(1);
    
    // 종이 쪼가리 붙여서 만든 숫자가 소수라면 카운팅
    for (auto s : num_set) {
        answer += isPrime(s);
    }
    
    return answer;
}
