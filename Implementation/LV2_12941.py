def solution(A,B):
    answer = 0
    answer = sum(a * b for a, b in zip(sorted(A), sorted(B, reverse=True)))
    return answer