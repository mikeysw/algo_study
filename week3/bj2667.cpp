#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N, cnt;
int graph[26][26];
bool visited[26][26] = {0, };
string s;
vector<int> v;
int axisX[4] = {0, 1, 0, -1}; // x축, 왼오 탐색용
int axisY[4] = {-1, 0, 1, 0}; // y축, 위아래 탐색용

void dfs(int a, int b){ //a는 위아래 b는 왼오
    for(int i=0; i<4; i++){
        int aY = a + axisY[i];
        int bX = b + axisX[i];

        if(aY >= N || aY < 0 || bX >= N || bX < 0) continue;

        if(visited[aY][bX] == 0 && graph[aY][bX] == 1){
            visited[aY][bX] = 1;
            cnt += 1;
            dfs(aY, bX);
        }
    }
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> s;
        for(int j=0; j<N; j++){
            if(s[j] == '1') graph[i][j] = 1;
            else graph[i][j] = 0;
        }
    }

    int num = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(graph[i][j] == 1 && visited[i][j] == 0){ // 가구 있고, 방문 아직 안함
                visited[i][j] = 1; // 방문 체크
                cnt = 1;
                dfs(i, j);
                v.push_back(cnt);
                num++;
            }// 단지 1개 단위 끝
        }
    }

    sort(v.begin(), v.end());

    cout << num << endl;

    for(int i=0; i<num; i++){
        cout << v[i] << endl;
    }

}