def solution(s):
    stack = []
    for ch in s:
        if len(stack) == 0:
            stack.append(ch)
            continue
        if stack[-1] != ch:
            stack.append(ch)
        else:
            stack.pop()
    return 1 if len(stack) == 0 else 0