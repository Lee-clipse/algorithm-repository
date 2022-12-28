def solution(s):
    transfer_count = 0
    zero_count = 0
    while s != '1':
        transfer_count += 1
        # 어차피 1의 개수만 필요하니 한 번만 연산 후 바인딩
        one_count = s.count('1')
        zero_count += len(s) - one_count
        # bin() 결과가 0b~~ 이니 인덱스 2부터 슬라이싱
        s = bin(one_count)[2:]
    return [transfer_count, zero_count]