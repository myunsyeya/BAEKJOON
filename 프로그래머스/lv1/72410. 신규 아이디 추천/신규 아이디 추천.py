# 1단계 lower()
# 2단계 int() ASCII 변환 후 condition..?
# 3단계 
# 4단계 strip('.')
# 5단계 not. = "a"
# 6단계 len() > 15 [:15] rstrip('.')
# 7단계 len() < 3 
# 너무 긴데.. regex로 간소화 가능한가?
import re
def solution(new_id):
    answer = ''
    new_id = new_id.lower()
    regex_2 = re.compile('[A-Za-z0-9-_.]+')
    new_id = ''.join(regex_2.findall(new_id))
    regex_3 = re.compile('[.]+|[^.]+')
    new_id = ''.join(map(lambda x: x if x[0] != '.' else '.',regex_3.findall(new_id)))
    new_id = new_id.strip('.')
    new_id = 'a' if not new_id else new_id
    # 사실 상 삼항 연산자는 불필요.
    new_id = new_id[:15] if len(new_id) > 15 else new_id
    new_id = new_id.strip('.')
    answer = ''.join([new_id,new_id[-1]*(3-len(new_id))]) if len(new_id) < 3 else new_id 
    return answer