#include <iostream>

using namespace std;

int main(){
    int K, N;
    cin >> K >> N;

    int karr[10000];
    int total = 0;
    int max1 = 0;
    for(int i=0; i<K; i++){
        cin >> karr[i];
        total += karr[i];
        if(max1 < karr[i]) max1 = karr[i];
    }

    int low = 1;
    int high = max1;

   
    int flag = 0;
    int cnt;

    while(low <= high){
        int mid = (low+high) / 2;
        cnt = 0;

        for(int k=0; k<K; k++){
            cnt += (karr[k] / mid);
        }

        if(cnt == N){
            flag = mid;
            break;
        }

        if(cnt > N) low = mid + 1;
        else if(cnt < N) high = mid - 1;
    }

    while(cnt == N){
        cnt = 0;
        flag += 1;
        for(int k=0; k<K; k++){
            cnt += (karr[k] / flag);
        }
    }

    cout << flag-1;
}