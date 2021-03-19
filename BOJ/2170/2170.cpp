#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int> > lines(n);

    for(int i = 0; i < n; i++){
        int start, end;
        cin >> start >> end;
        lines[i].first = start;
        lines[i].second = end;
    }

    sort(lines.begin(), lines.end());

    int res = 0;
    int start = lines[0].first, end = lines[0].second;

    for(int i = 1; i < n; i++){
        if(lines[i].first <= end) end = max(end, lines[i].second);
        else{
            res += end - start;
            start = lines[i].first;
            end = lines[i].second;
        }
    }
    res += end - start;
    cout << res << '\n';
    return 0;
}