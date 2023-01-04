def solution(n, words):
    prev = words[0][0]
    for index, word in enumerate(words):
        if (prev != word[0]) or (word in words[:index]):
            return [(index % n) + 1, (index // n) + 1]
        prev = word[-1]
    return [0, 0]