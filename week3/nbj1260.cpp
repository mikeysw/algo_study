#include <iostream>
#include <queue>

using namespace std;

int N, M, V;
int graph[1001][1001];
bool visited[1001];
queue<int> q;

void reset(){
    for(int i=1; i<N+1; i++){
        visited[i] = 0;
    }
}

void dfs(int v){
    visited[v] = true;
    cout << v << " ";

    for(int i=1; i<N+1; i++){
        if(graph[v][i] == 1 && visited[i] == 0) { dfs(i); }
    }
}

void bfs(int v){
    q.push(v);
    visited[v] = true;
    cout << v << " ";

    while(!q.empty()){
        v = q.front();
        q.pop();

        for(int i=1; i<N+1; i++){
            if(graph[v][i] == 1 && visited[i] == 0){
                q.push(i);
                visited[i] = true;
                cout << i << " ";
            }
        }
    }
}

int main(){
    cin >> N >> M >> V;

    for(int i=0; i<M; i++){
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }

    reset();
    dfs(V);
    cout << "\n";
    reset();
    bfs(V);

    return 0;

}