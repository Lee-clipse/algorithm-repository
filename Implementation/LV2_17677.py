def solution(str1, str2):
    mod = 65536
    # 중복집합 구하기
    set1 = [str1[i:i+2].upper() for i in range(len(str1)-1) if str1[i:i+2].isalpha()]
    set2 = [str2[i:i+2].upper() for i in range(len(str2)-1) if str2[i:i+2].isalpha()]
    # 자카드 유사도 구하기
    g_set = set(set1) & set(set2)
    h_set = set(set1) | set(set2)
    g_count = sum([min(set1.count(el), set2.count(el)) for el in g_set])
    h_count = sum([max(set1.count(el), set2.count(el)) for el in h_set])
    
    answer = mod
    if g_count + h_count != 0:
        answer = int((g_count / h_count) * mod)
    return answer
    
    