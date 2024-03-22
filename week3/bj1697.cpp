#include <iostream>
#include <queue>

using namespace std;

#define MAX 100001

int N, K;
int graph[MAX][MAX] = {0, };
int visited[MAX];
queue<int> q;

int bfs(int x){
    q.push(x);
    int cnt = 0;

    while(!q.empty()){
        int qsize = q.size();
        while(qsize--){
            int now = q.front();
            //cout << "now: " << now << endl;
            q.pop();
            if(now - 1 == K || now + 1 == K || now * 2 == K){
                return cnt+1;
            }
            
            if(now - 1 >= 0) q.push(now - 1);
            if(now + 1 < MAX) q.push(now + 1);
            if(now * 2 < MAX) q.push(now * 2);
            /*
            for(int i=0; i<MAX; i++){
                if(graph[now][i] == 1 && visited[i] == 0){
                    q.push(i);
                    visited[i] = 1;
                }
            }*/
        }
        cnt++;
    }
    return -1;
}
/*
void search_case(int n){
    int sb1 = n - 1;
    int sb2 = n + 1;
    int sb3 = 2 * n;

    if(sb1 >= 0){
        graph[n][sb1] = 1;
        graph[sb1][n] = 1;
        cout << "!";
    }

    if(sb2 <= 100000){
        graph[n][sb2] = 1;
        graph[sb2][n] = 1;
    }

    if(sb3 <= 100000){
        graph[n][sb3] = 1;
        graph[sb3][n] = 1;
    }

}*/

void search_case1(int n){
    int sb1 = n - 1;
    if(sb1 >= 0){
        graph[n][sb1] = 1;
        graph[sb1][n] = 1;
        search_case1(sb1);
    }
}

void search_case2(int n){
    int sb2 = n + 1;
    if(sb2 < MAX){
        graph[n][sb2] = 1;
        graph[sb2][n] = 1;
        search_case2(sb2);
    }
}

void search_case3(int n){
    int sb3 = n * 2;
    if(sb3 < MAX){
        graph[n][sb3] = 1;
        graph[sb3][n] = 1;
        search_case3(sb3);
    }
}

int main(){
    cin >> N >> K;

    //search_case1(N);
    //search_case2(N);
    //search_case3(N);

    visited[N] = 1;
    cout << bfs(N);
}