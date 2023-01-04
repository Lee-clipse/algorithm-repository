def solution(people, limit):
    answer = 0
    people.sort()
    # 투 포인터 접근
    left = 0
    right = len(people) - 1
    while left <= right:
        # 마지막 한 쌍에 대한 처리
        if left == right:
            answer += 1
            break
        if people[left] + people[right] <= limit:
            left += 1
        right -= 1
        answer += 1
    return answer