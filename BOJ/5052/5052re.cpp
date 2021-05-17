#include <iostream>
#include <string>
#define LEN_MAX 11
using namespace std;

struct TRIE{
    TRIE* next[LEN_MAX];
    bool output;
    bool go;

    TRIE(){
        fill(next, next + LEN_MAX, nullptr);
        output = go = false;
    }
    ~TRIE(){
        for(int i = 0; i < LEN_MAX; i++)
            if(next[i]) delete next[i];
    }

    void insert(const char* value){
        if(*value == '\0') output = true;
        else{
            int n = *value - '0';
            if(!next[n]) next[n] = new TRIE;
            go = true;
            next[n] -> insert(value + 1);
        }
    }

    bool consistence(){
        if(go && output) return false;
        for(int i = 0; i < LEN_MAX; i++){
            if(next[i] && !next[i] -> consistence()) return false;
        }
        return true;
    }
};

int main(){
    int t, c;
    cin >> t;
    while(t--){
        cin >> c;
        TRIE* root = new TRIE;
        for(int i = 0; i < c; i++){
            char number[11];
            cin >> number;
            root -> insert(number);
        }
        puts(root->consistence() ? "YES" : "NO");
        delete(root);
    }
    return 0;
}