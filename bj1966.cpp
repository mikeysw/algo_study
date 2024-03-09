#include <iostream>
#include <queue>

using namespace std;

int main(){
    int T;
    cin >> T;

    for(int i=0; i<T; i++){
        int N, M;
        cin >> N >> M;

        priority_queue<int>pq;
        queue<pair<int, int>> q;

        for(int j=0; j<N; j++){
            int temp;
            cin >> temp;
            q.push({j, temp});
            pq.push(temp);
        }

        int cnt = 0;
        while(!q.empty()){
            int idx = q.front().first;
            int imp = q.front().second;
            q.pop();

            if(pq.top() == imp){
                pq.pop();
                cnt++;
                if(idx == M){
                    cout << cnt << endl;
                    break;
                }
            }
            else q.push({idx, imp});
        }

    }
}