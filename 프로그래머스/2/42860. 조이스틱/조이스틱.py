# 문자열을 순회해나가며, A가 아니면 커서를 해당 문자에 지목, 변경하는 과정이 필요.
# 커서를 움직이는데 드는 조작 횟수 + 이름을 바꾸는데 드는 조작 횟수
# 각각은 처음과 끝이 연결되어 있어, 수직선을 기준으로 증감 중 어느 게 더 빠른지 판단해야 한다.
# 고리 형태의 순환은 생각하기 어려우므로 고리를 풀어서 쭉 늘어뜨린다고 생각하면,
# name[0] ~ name[n-1], name[0] ~ name[cursor] ~ name[n-1], name[0] ~ name[n-1]
# 위와 같은 name이 3번 반복되는 리스트에서 커서가 목표와 어느 방향에서 더 가까운지 판단한다.
# 어..? 굳이 리스트로 안 만들고 수만 비교해도 되지 않나?
# 판단 이후 커서는 항상 원래 리스트 name의 현재 인덱스를 가리키고 있어야 한다.
# 이름을 바꾸는 방식도 위와 동일한 방식.
# //////// 어라?
# 순회순서도 고려해야 하지 않을까? 만약 ABAAAAAAB라면? 5여야 하는데?
# 이게... 그리디?
def solution(name):
    answer = 0
    cursor = 0
    name_ = [1 if i != 'A' else 0 for i in name]
    #null_ = [0] * len(name)
    answer += dfs(cursor, name_, 0)
    alphabet = 26
    for i in name:
        # 알파벳은 항상 처음이 A로 고정
        # 아래로 이동(name[i] = alphabet + 'A' - x)
        left = (alphabet + ord('A') - ord(i)) % alphabet
        # 위로 이동('A' + x = name[i])
        right = (alphabet + ord(i) - ord('A')) % alphabet
        answer += left if left < right else right
    return answer

def dfs(cursor, name_, s):
    n = s
    list_ = name_.copy()
    list_[cursor] = 0
    if list_ == [0]*len(list_):
        return n
    left = right = cursor
    left_count = right_count = 0
    while not list_[left]:
        left -= 1
        left_count += 1
    while not list_[right]:
        right += 1
        right_count += 1
    n = min(dfs(left, list_, s + left_count), dfs(right, list_, s + right_count))
    return n
    
#첫 번째 시도: 순차적 해석
#n = len(name)
#for i in range(len(name)):
#        if name[i] == 'A':
#            continue
#        # J A N(i) J(cursor) A N J A N
#        # 좌로 이동(i = n + cursor - x)
#        left = (n + cursor - i) % n
#        # 우로 이동(cursor + x = n + i)
#        right = (n + i - cursor) % n
#        answer += left if left < right else right
#        cursor = i
#두 번째 시도: 그리디하게 부분적 최적해 구하기
#    while name_ != null_:
#        left = right = cursor
#        left_count = right_count = 0
#        while(not name_[left]):
#            left -= 1
#            left_count += 1
#        while(not name_[right]):
#            right += 1
#            right_count += 1
#        answer += left_count if left_count < right_count else right_count
#        cursor = right
#        name_[cursor] = 0