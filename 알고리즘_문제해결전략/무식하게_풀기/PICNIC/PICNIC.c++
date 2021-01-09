#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_VALUE = 10;
int n, m;
bool areFriends[MAX_VALUE][MAX_VALUE];
bool taken[MAX_VALUE];

int makePicnicMember(){
    int whoLeft = -1;
    for(int i = 0; i<n;i++){
        if(!taken[i]){
            whoLeft=i;
            break;
        }
    }
    if(whoLeft == -1) return 1;
    int ret = 0;

    for(int i = whoLeft+1;i<n;i++){
        if(!taken[i] && areFriends[whoLeft][i]){
            taken[whoLeft] = taken[i] = true;
            ret+=makePicnicMember();
            taken[whoLeft] = taken[i] = false;
        }
    }
    return ret;
}

void init(){
    for(int i = 0; i<n;i++){
        taken[i] = false;
        for(int j = 0; j<n;j++){
            areFriends[i][j] = false;
        }
    }
}

int main(){
    int testCase = 0;
    cin >> testCase;

    for(int i = 0; i<testCase ;i++){
        init();
        cin >> n >> m;
        for(int i = 0; i<m;i++){
            int a, b;
            cin >> a >> b;
            areFriends[a][b] = true;
            areFriends[b][a] = true;
        }
        cout << makePicnicMember() << "\n";
    }

    return 0;
}