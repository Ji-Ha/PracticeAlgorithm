#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> lis;
    int n;
    int count = 0;
    cin >> n;

    lis.push_back(-1000000001);
    for(int i = 0; i < n; i++){
        int value;
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