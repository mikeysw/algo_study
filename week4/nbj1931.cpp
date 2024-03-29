#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int N, start, end;
    vector<pair<int, int>> schedule;

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> start >> end;
        schedule.push_back(make_pair(end, start));
    }
    sort(schedule.begin(), schedule.end());

    int t = schedule[0].first;
    int cnt = 1;
    for(int i=1; i<N; i++){ // 위에서 0번째거는 할당했음
        if(t <= schedule[i].second){
            cnt++;
            t = schedule[i].first;
        }
    }
    cout << cnt;
}