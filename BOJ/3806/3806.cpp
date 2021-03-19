#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solution(string first, string second){
}

int main(){
    int c;
    cin >> c;
    
    for(int i = 1; i <= c; i++){
        string first;
        string second;

        cin >> first;
        cin >> second;

        cout << "Case " << i << ": " << solution(first, second) << '\n';
    }
    return 0;
}