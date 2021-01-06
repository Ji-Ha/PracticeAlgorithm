 #C++로 참여했지만, python으로 푸는 게 빠르고 효율적.
#시간 부족으로 C++로 못풀어서 다시풀어보는 중.
#주어진 테스트 케이스는 다 풀었지만, 실행시간이 n의 3제곱으로 나와 시간 초과날 거 같음.

def solution(logs):
    answer = list()
    data = list()
    students = set()
    #마지막 log 값에 대한 수치들만 data에 삽입.
    for inform in logs:
        value = inform.split()
        students.add(value[0])
        for i in range(0, len(data)):
            if data[i][0] == value[0] and data[i][1] == value[1]:
                data.pop(i)
                break
        data.append(value)

    data.sort()

    #res에 학생에 맞는 문제와 점수 넣음.
    res = dict()
    for student in students:
        temp = list()
        for datum in data:
            if student == datum[0]:
                temp.append([datum[1], datum[2]])
        res.setdefault(student, temp)
    #print(res)
    #주어진 dict를 활용하여 부정행위자 검출
    for stu1, stuValue1 in res.items():
        
        for stu2, stuValue2 in res.items():
            count = 0
            if stu1 != stu2:
                for val in stuValue1:
                    if val in stuValue2:
                        count = count +1
                if count >= 5 :
                    answer.append(stu1)

    
    answer = list(set(answer))
    answer.sort()
    if len(answer) == 0:
        answer.append("None")
    return answer


def main():
    logs = ["1901 1 100", "1901 2 100", "1901 4 100", "1901 7 100", "1901 8 100", "1902 2 100", "1902 1 100", "1902 7 100", "1902 4 100", "1902 8 100", "1903 8 100", "1903 7 100", "1903 4 100", "1903 2 100", "1903 1 100", "2001 1 100", "2001 2 100", "2001 4 100", "2001 7 95", "2001 9 100", "2002 1 95", "2002 2 100", "2002 4 100", "2002 7 100", "2002 9 100"]




    print(solution(logs))


if __name__ == "__main__":
    main()
