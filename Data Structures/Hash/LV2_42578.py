def solution(clothes):
    # 해시 풀이
    answer = 1
    clothes_list = {}
    for c, t in clothes:
        if t not in clothes_list:
            clothes_list[t] = 2
        else:
            clothes_list[t] += 1
    for p in clothes_list.values():
        answer *= p
    return answer - 1
    
    # pythonic 풀이
    from collections import Counter
    from functools import reduce
    clothes_count = Counter([kind for cloth, kind in clothes])
    answer = reduce(lambda x, y : x * (y+1), clothes_count.values(), 1) - 1
    return answer
