#C++로 참여했지만, python으로 푸는 게 빠르고 효율적.
#시간 부족으로 C++로 못풀어서 다시풀어보는 중.
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

    res = list()
    for i in range(0, len(data)):
        for j in range(0, len(data)):
            if data[i][1] == data[j][1] and data[i][2] == data[j][2] and data[i][0] != data[j][0]:
                res.append(data[i][0])

    print(res)
    for student in students:
        count = 0
        for i in range(0, len(res)):
            if student == res[i]:
                count= count +1
                
        if count >=5:
            answer.append(student)
    answer.sort()
    return answer


def main():
    logs = ["1901 1 100", "1901 2 100", "1901 4 100", "1901 7 100", "1901 8 100", "1902 2 100", "1902 1 100", "1902 7 100", "1902 4 100", "1902 8 100", "1903 8 100", "1903 7 100", "1903 4 100", "1903 2 100", "1903 1 100", "2001 1 100", "2001 2 100", "2001 4 100", "2001 7 95", "2001 9 100", "2002 1 95", "2002 2 100", "2002 4 100", "2002 7 100", "2002 9 100"]
    print(solution(logs))


if __name__ == "__main__":
    main()
