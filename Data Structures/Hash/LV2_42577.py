# N은 최대 1,000,000
# N + N-1 + N-2 이렇게 검사하는 건 불가능
# 접두어를 파싱해서 이를 저장 후 해시로 O(1) 조회해야함
# 1) N 돌며 하나씩 파싱 후 해시로 저장
#       유효하지 않은 방법
# 2) N 돌며 하나씩 온전히 해시로 저장
#    N 다시 돌며 파싱 후 해시 검사
#    => O(N) * 20 이므로 통과 가능
def solution(phone_book):
    answer = True
    hash = {}
    for number in phone_book:
        hash[number] = 1
    for number in phone_book:
        tmp = ''
        for n in number:
            tmp += n
            if tmp in hash and tmp != number:
                return False
    return answer