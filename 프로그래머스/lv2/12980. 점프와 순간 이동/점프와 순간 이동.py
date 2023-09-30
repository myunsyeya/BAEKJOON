# 일단 dp네..
# 짝수면 무조건 2로 나누고, 홀수는 무조건 한 칸 이동.
# 아니. dp가 아닌가? 위에 로직으로 충분할지도.
def solution(n):
    ans = 0
    # [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    while(n):
        if n%2: 
            n -= 1
            ans += 1
        else:
            n /= 2
    return ans