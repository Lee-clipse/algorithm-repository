answer = 0

def dfs(numbers, index, target):
    global answer
    if index == len(numbers) and target == 0:
        answer += 1
        return
    elif index == len(numbers) and target != 0:
        return 
    else:
        dfs(numbers, index+1, target-numbers[index])
        dfs(numbers, index+1, target+numbers[index])

def solution(numbers, target):
    global answer
    dfs(numbers, 0, target)
    return answer