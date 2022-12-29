def getOneCount(n):
    return bin(n).count("1")

def solution(n):
    answer = 0
    max_n = 1000001
    one_count = getOneCount(n)
    for next_n in range(n+1, max_n):
        if getOneCount(next_n) == one_count:
            answer = next_n
            break
    return answer