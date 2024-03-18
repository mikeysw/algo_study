#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(int V, vector<int> graph[], bool visited[]){
    visited[V] = true;
    cout << V << " ";

    for(int i=0; i<graph[V].size(); i++){
        int next = graph[V][i];
        if(!visited[next]) { dfs(next, graph, visited); }
    }
}

void bfs(int V, vector<int> graph[], bool visited[]){
    queue<int> q;
    q.push(V);
    visited[V] = true;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << " ";

        for(int i=0; i<graph[cur].size(); i++){
            int next = graph[cur][i];
            if(!visited[next]){
                q.push(next);
                cout << next<<"?";
                visited[next] = true;
            }
        }
    }
}

int main(){
    int N, M, V;
    cin >> N >> M >> V;

    vector<int> graph1[N+1];
    vector<int> graph2[N+1];
    bool visited1[N+1];
    bool visited2[N+1];

    for(int i=0; i<M; i++){
        int v1, v2;
        cin >> v1 >> v2;
        graph1[v1].push_back(v2);
        graph1[v2].push_back(v1);
        graph2[v1].push_back(v2);
        graph2[v2].push_back(v1);
    }

    dfs(V, graph1, visited1);
    cout << "\n";
    bfs(V, graph2, visited2);


    /*

    int graph[N+1][N+1];

    for(int i=0; i<=N; i++){
        for(int j=0; j<=N; j++){
            graph[i][j] = -1;
        }
    }

    for(int i=0; i<M; i++){
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }

    */




}