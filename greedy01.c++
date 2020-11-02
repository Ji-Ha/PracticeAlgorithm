#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    //학생 vector 선언.
    vector <int> student(n);
    
    //student 초기화.
    for(int i = 0; i<student.size();i++)
        student[i] = 0;
    //잃어버린 사람?
    for(int i = 0 ; i<lost.size();i++)
        student[lost[i] - 1] -= 1;
    //더있는 사람?
    for(int i = 0 ; i <reserve.size(); i++)
        student[reserve[i] - 1] += 1;
    
    for(int i = 0 ; i<student.size()-1 ; i++){
        //옷 빌려야하는 사람은?
        if(student[i] == -1){
            //왼쪽 친구에게 빌려보세요.
            if(i>0 && student[i-1] == 1){
                student[i-1]--;
                student[i]++;
            }
            //오른쪽 친구는 있겠지ㅎㅎ
            else if(i < student.size()-1 && student[i+1] ==1){
                student[i+1]--;
                student[i]++;
            }
        }
    }
    
    for(int i = 0 ;i <student.size();i++){
        if(student[i] >= 0)
            answer++;
    }
    return answer;
}