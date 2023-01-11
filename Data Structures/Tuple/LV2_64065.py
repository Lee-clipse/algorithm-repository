from collections import Counter

def solution(s):
    s = s.replace('{', '').replace('}', '').split(',')
    return [int(c[0]) for c in sorted(Counter(s).items(), key=lambda x:x[1], reverse=True)]
