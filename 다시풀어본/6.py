#C++로 참여했지만, python으로 푸는 게 빠르고 효율적.
#시간 부족으로 C++로 못풀어서 다시풀어보는 중.
def solution(logs):
    answer = ""
    data = list()
    #마지막 log 값에 대한 수치들만 data에 삽입.
    for inform in logs:
        value = inform.split()
        for i in range(0, len(data)):
            if data[i][0] == value[0] and data[i][1] == value[1]:
                data.pop(i)
                break
        data.append(value)

    data.sort()
    
    

    return answer


def main():
    logs = ["0001 3 95", "0001 5 90", "0001 5 100", "0002 3 95", "0001 7 80", "0001 8 80", "0001 10 90", "0002 10 90", "0002 7 80", "0002 8 80", "0002 5 100", "0003 99 90"]
    print(solution(logs))


if __name__ == "__main__":
    main()
