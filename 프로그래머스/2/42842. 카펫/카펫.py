# brown + yellow = area
# divisor를 구해서 두 divisor(가로, 세로)-2의 area가 yellow와 같은지 확인하는 문제.
def solution(brown, yellow):
    answer = []
    area = brown + yellow
    divisor = []
    for i in range(2, int(area**(1/2))+1):
        if not area % i:
            divisor.append((i, area // i))
            
    for height, width in divisor:
        if yellow == (width-2)*(height-2):
            return [width, height]
    return answer