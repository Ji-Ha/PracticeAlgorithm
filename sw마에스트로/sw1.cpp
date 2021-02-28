#include <iostream>
#include <vector>
using namespace std;

int main(){
    int k;
    int treeSize;
    char skill[100];
    vector <vector <char> > skillTree;

    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> skill[i];
        skillTree.push_back(skill[i]);
    }


    cin >> treeSize;
    for(int i = 0; i < treeSize; i++){
        int a, b;
        cin >> a >> b;

        skillTree(a).push_back(b);
    }
    return 0;
}