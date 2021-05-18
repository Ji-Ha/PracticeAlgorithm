#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
vector<int> preorder;
vector<int> inorder;
vector<int> postorder;
int place[1001];
int n;

void mkpost(int pb, int pe, int ib, int ie){
    if(pe < pb || ie < ib) return;
    int root = preorder[pb];
    int target = place[root]; // inorder의 root 위치
    //postorder.push_back(root);
    mkpost(pb + 1, pb + (target - ib), ib, target - 1);
    mkpost(pb + (target - ib) + 1, pe, target + 1, ie);
    cout << root << " ";
}

int main(){
    int t, temp;
    cin >> t;
    while(t--){
        memset(place, 0, sizeof(place));
        preorder.clear();
        inorder.clear();
        postorder.clear();
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> temp;
            preorder.push_back(temp);
        }

        for(int i = 0; i < n; i++){
            cin >> temp;
            inorder.push_back(temp);
            place[temp] = i;
        }

        mkpost(0, n - 1, 0, n - 1);
        cout << '\n';
    }
    return 0;
}