#include <iostream>
#include <string>
#include <vector>
using namespace std;
int smallalpha[26] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116,
                        117, 118, 119, 120, 121, 122};
int num[10] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57};
int line = 45;
int underline = 95;
int fullstop = 46;

bool check(int target){
    bool checker = false;
    for(int i = 0; i < 26; i++){
        if(smallalpha[i] == target){
            checker = true;
            break;
        } 
    }
    for(int i = 0; i < 10; i++){
        if(num[i] == target){
            checker = true;
            break;
        }
    }
    if(line == target) checker = true;
    if(underline == target) checker = true;
    if(fullstop == target) checker = true;
    return checker;
}

string fullstopchanger(string new_id){
    int count = 0;
    string res = "";
    for(int i = 0; i < new_id.length(); i++){
        if(new_id[i] == '.'){
            if(count == 0){
                count++;
                res += '.';
            }
        } 
        else{
            res += new_id[i];
            count = 0;
        }
        
    }
    return res;
}

string solution(string new_id){
    for(int i = 0; i < new_id.length(); i++)
        new_id[i] = tolower(new_id[i]);
    
    string temp = "";
    for(int i = 0; i < new_id.length(); i++){
        if(check(new_id[i])) temp += new_id[i];
    }
    new_id = temp;

    new_id = fullstopchanger(new_id);
    if(new_id[0] == '.') new_id = new_id.substr(1, 1 + new_id.length() - 1);
    if(new_id[new_id.length() - 1] == '.') new_id = new_id.substr(0, new_id.length() - 1);

    if(new_id.empty()) new_id = 'a';
    if(new_id.length() >= 16) new_id = new_id.substr(0, 15);
    if(new_id[new_id.length() - 1] == '.') new_id = new_id.substr(0, new_id.length() - 1);
    while(new_id.length() <= 2) new_id += new_id[new_id.length() - 1];
    
    return new_id;
}

int main(){
    string new_id;
    cin >> new_id;
    cout << solution(new_id) << '\n';
    return 0;
}