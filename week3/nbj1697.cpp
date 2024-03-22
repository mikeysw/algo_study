#include <iostream>
#include <queue>
using namespace std;

#define MAX 100001

int N, K;
bool visited[MAX] = {0, }; 

int bfs(int x){
    queue<int> q;
    q.push(x);
    visited[x] = true;
    int cnt = 0;

    while(!q.empty()){
        int qsize = q.size();
        for(int i = 0; i < qsize; i++){
            int now = q.front();
            q.pop();

            if(now == K){
                return cnt;
            }

            if(now - 1 >= 0 && !visited[now - 1]){
                q.push(now - 1);
                visited[now - 1] = true;
            }
            if(now + 1 < MAX && !visited[now + 1]){
                q.push(now + 1);
                visited[now + 1] = true;
            }
            if(now * 2 < MAX && !visited[now * 2]){
                q.push(now * 2);
                visited[now * 2] = true;
            }
        }
        cnt++;
    }
    return -1;
}

int main(){
    cin >> N >> K;
    cout << bfs(N);
    return 0;
}