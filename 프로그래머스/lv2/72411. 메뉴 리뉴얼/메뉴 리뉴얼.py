from itertools import combinations
def solution(orders, course):
    answer = []
    for number in course:
        count_course = dict()
        for order in orders:
            make_course(count_course, order, number)
        count_course = {key: value for key, value in count_course.items() if value}
        count_course = sorted(count_course.items(),key=lambda x:x[1],reverse=True)
        if count_course:
            count_course = dict(count_course)
            pivot = list(count_course.values())[0]
            for key, value in count_course.items():
                if value == pivot:
                    answer.append("".join(sorted(key)))
                else:
                    break
        answer.sort()
    return answer

def make_course(course_dict, order, number):
    for comb in combinations(order, number):
        is_exist = course_dict.get(tuple(sorted(list(comb))))
        if is_exist is None:
            course_dict[tuple(sorted(list(comb)))] = 0
        else:
            course_dict[tuple(sorted(list(comb)))] += 1
            
    return course_dict