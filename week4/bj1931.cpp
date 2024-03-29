#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 2147483647
#define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )

int N;
int stime[100001];
int etime[100001];
int ltime[100001];
int status[100001];
int reserved[MAX];

void sort_all(){ // 선택 정렬 활용
    int i, j, least, temp;
    
    for(i=0; i<N-1; i++){
        least = i;

        for(j=i+1; j<N; j++){
            if(ltime[j]<ltime[least])
                least = j;
        }

    if(i != least){
        SWAP(ltime[i], ltime[least], temp);
        SWAP(stime[i], stime[least], temp);
        SWAP(etime[i], etime[least], temp);
    }
  }
}

int check_avail(int x){
    int flag = 0;
    for(int j=stime[x]; j<etime[x]; j++){
        if(reserved[j] == 1){
            flag = 1;
            break;
        }
    }

    if(flag == 1) return 0;
    else{
        for(int j=stime[x]; j<etime[x]; j++){
            reserved[j] = 1;
        }
        return 1;
    }
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> stime[i] >> etime[i];
        ltime[i] = etime[i] - stime[i];
    }
    sort_all();

    int cnt = 0;
    for(int i=0; i<N; i++){
        cnt += check_avail(i);
    }
    cout << cnt;
}