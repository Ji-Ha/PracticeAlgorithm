#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;
int n;
int value;
vector<int> lis;

int main(){
    int count = 0;
    cin >> n;
    lis.push_back(0);
    
    for(int i = 0; i < n; i++){
        cin >> value;
        if(value > lis.back()){
            lis.push_back(value);
            count++;
        }
        else{
            vector<int>:: iterator low = lower_bound(lis.begin(), lis.end(), value);
            *low = value;
        }
    }

    cout << count << '\n';
    return 0;
}