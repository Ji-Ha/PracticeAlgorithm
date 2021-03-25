#include <iostream>
#include <vector>
using namespace std;
int value[1000001];

int main(){
    vector<int> lis;
    vector<int> staack;
    vector<int> ans;
    int count = 0;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> value[i];
        if(i == 0 || lis.back() < value[i]){
            lis.push_back(value[i]);
            staack.push_back(count);
            count++;
        }
        else{
            vector<int>:: iterator low = lower_bound(lis.begin(), lis.end(), value[i]);
            *low = value[i];
            staack.push_back(count);
        }

    }
    cout << count << '\n';
    
    count--;
    for(int i = n - 1; i >= 0; i--){
        if(count == staack[i]){
            ans.push_back(value[i]);
            count--;
        }
    }

    while(!ans.empty()){
        cout << ans.back() << ' ';
        ans.pop_back();
    }
    return 0;
}