#include <iostream>

using namespace std;

int main(){
    unsigned int K, N;
    cin >> K >> N;

    unsigned int karr[10000];
    unsigned int max1 = 0;
    for(int i=0; i<K; i++){
        cin >> karr[i];
        if(max1 < karr[i]) max1 = karr[i];
    }

    unsigned int low = 1;
    unsigned int high = max1;
    unsigned int ans = 0;
    unsigned int mid;

    while(low <= high){
        mid = (low + high) / 2;

        unsigned int cnt = 0;
        
        for(int i=0; i<K; i++){
            cnt += karr[i] / mid;
        }

        if(cnt >= N){
            low = mid + 1;
            if(ans < mid) ans = mid;
        }
        else{
            high = mid - 1;
        }
    }

    cout << ans;
   
}