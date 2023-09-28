def solution(n, arr1, arr2):
    answer = [bin(elm1|elm2)[2:].zfill(n).replace('1','#').replace('0',' ') for elm1, elm2 in zip(arr1, arr2)]
    return answer