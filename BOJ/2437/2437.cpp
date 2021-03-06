#include <iostream>
#include <algorithm>
using namespace std;
int sinker[1000];


int main(){
    int n;
    
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> sinker[i];
    
    sort(sinker, sinker + n);

    int sum = sinker[0];
    int res = 0;
    for(int i = 1; i < n; i++){
        if(sum + 1 < sinker[i]) {
            res = sum + 1;
            break;
        }
        sum += sinker[i];
    }
    cout << sum + 1 << '\n';
    return 0;
}