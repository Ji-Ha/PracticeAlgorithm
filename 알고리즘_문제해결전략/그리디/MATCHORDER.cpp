#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int order(const vector<int>& russian, const vector<int>& korean){
    int n = russian.size(), win = 0;
    multiset<int> ratings(korean.begin(), korean.end());
    for(int rus = 0; rus < n; rus++){
        if(*ratings.rbegin() < russian[rus])
            ratings.erase(ratings.begin());
        else{
            ratings.erase(ratings.lower_bound(russian[rus]));
            win++;
        }
    }
    return win;
}

int main(){
    int c;
    cin >> c;

    while(c--){
        int n;
        cin >> n;

        vector<int> russia;
        vector<int> korea;

        for(int i = 0; i < n; i++){
            int russ;
            cin >> russ;
            russia.push_back(russ);
        }
        
        for(int i = 0; i < n; i++){
            int kor;
            cin >> kor;
            korea.push_back(kor);
        }

        sort(korea.begin(), korea.end());
        
        cout << order(russia, korea) << "\n";
    }
    return 0;
}