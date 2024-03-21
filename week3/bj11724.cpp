#include <iostream>
#include <queue>

using namespace std;

int N, M;
int graph[1001][1001];
int visited[1001] = {0, };
queue<int> q;

void bfs(int v){
    q.push(v);
    visited[v] = 1;

    while(!q.empty()){
        v = q.front();
        q.pop();

        for(int i=1; i<1001; i++){
            if(graph[v][i] == 1 && visited[i] == 2){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}


int main(){
    cin >> N >> M;

    int u, v;
    for(int i=0; i<M; i++){
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    for(int i=1; i<N+1; i++){
        visited[i] = 2;
    }

    int num =0;
    for(int i=0; i<1001; i++){
        for(int j=0; j<1001; j++){
            if(graph[i][j] == 1 && visited[j] == 2){
                num++;
                bfs(j);
            }
        }
    }

    for(int k=0; k<1001; k++){
        if(visited[k]==2){
            num++;
            visited[k] = 1;
        }
    }

    cout << num;

}