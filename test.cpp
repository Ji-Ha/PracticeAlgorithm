#include <iostream>
#include <string>
using namespace std;

string fight(string razer){
    int hero = 0;
    int villain = 0;
    for(int i = 0; i < razer.length(); i++){
        if(razer[i] == ')') hero++;
        if(razer[i] == '(') villain++;
    }
    return hero >= villain ? "YES" : "NO";
}

int main() {
    string razer;
    cin >> razer;
    
    cout << fight(razer) << '\n';
    return 0;
}