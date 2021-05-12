#include <iostream>
using namespace std;

int inorder[100001];
int postorder[100001];
int find_root[100001];

void func(int is, int ie, int ps, int pe){
    if(is > ie) return ;
    int root = postorder[pe];
    cout << root << ' ';
    int pos = find_root[root];
    func(is, pos - 1, ps, ps + (pos - 1 - is));
    func(pos + 1, ie, ps + pos - is, pe - 1);
    return ;
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> inorder[i];
        find_root[inorder[i]] = i;
    }

    for(int i = 0; i < n; i++) cin >> postorder[i];
    func(0, n - 1, 0, n - 1);
    return 0;
}