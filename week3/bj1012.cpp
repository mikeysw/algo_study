#include <iostream>
#include <string.h>

using namespace std;

int M, N, K;
int graph[50][50] = {0};
bool visited[50][50] = {0};
int checkA[4] = {1, -1, 0, 0}; // x축, 왼오 탐색용
int checkB[4] = {0, 0, 1, -1}; // y축, 위아래 탐색용

void dfs(int a, int b){ //a는 위아래 b는 왼오
    for(int i=0; i<4; i++){
        int aA = a + checkA[i];
        int bB = b + checkB[i];
        //cout << "aY: " << aY << "bX: " << bX << endl;

        if(aA >= N || aA < 0 || bB >= N || bB < 0) continue;

        if(!visited[aA][bB] && graph[aA][bB]){
            visited[aA][bB]++;
            //cout << "!aY: " << aY << "!bX: " << bX << endl;
            dfs(aA, bB);
        }
    }
}

int main(){
    int T, x, y;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> M >> N >> K;

        memset(graph, 0, sizeof(graph));
        memset(visited, 0, sizeof(visited));

        int num = 0;

        for(int j=0; j<K; j++){
            cin >> x >> y;
            graph[y][x] = 1;
        }
        
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(graph[i][j] && !visited[i][j]){ // 가구 있고, 방문 아직 안함
                    num++;
                    visited[i][j]++; // 방문 체크
                    dfs(i, j);
                    //cout << "i: " << i << "j: " << j << endl;
                }// 단지 1개 단위 끝
            }
        }
        cout << num << "\n";
    }
}

