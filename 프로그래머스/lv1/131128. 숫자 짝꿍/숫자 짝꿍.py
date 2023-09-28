# 짝꿍: 두 문자열의 longest common subsequence를 구한 후 descending 정렬
# O(#X#Y) 이상 넘어가면 worst case: 3*3*10^12 --> 시간 초과!
# O(#X+#Y)이 될 수 있는 방법은? 몇 번 숫자를 썼는지 counting하여 저장!
# 두 dictionary의 min값을 저장 후에 높은 숫자부터 적어내리면 not necessary sorting!

def solution(X, Y):
    answer = ''
    min_ = dict.fromkeys([str(i) for i in range(10)], 0)
    X_ = min_.copy()
    Y_ = min_.copy()
    
    # counting
    for i in X:
        X_[i] += 1
    for i in Y:
        Y_[i] += 1
    # select minimum value
    for key in min_:
        min_[key] = X_[key] if X_[key] < Y_[key] else Y_[key]
    # make list
    answer_list = []
    for key in reversed(min_):
        unit = [key]
        answer_list += min_[key] * unit
    answer = ''.join(s for s in answer_list)
    # 예외처리
    if answer == '':
        answer = '-1'
    elif answer[0] == '0':
        answer = '0'
    
    return answer

