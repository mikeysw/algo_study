#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    long long N;
    cin >> N;

    long long cdn[1,000,000];
    long long cdn_sorted[1,000,000];
    long long max = 0;
    long long temp;
    for(long long i=0; i<N; i++){
        cin >> temp;
        cdn[i] = temp;
        cdn_sorted[i] = temp;
    }

    sort(cdn_sorted, cdn_sorted+N);
    unique(cdn_sorted, cdn_sorted+N);

    long long low = 0;
    long long high = N-1;
    long long mid, cnt, goal;

    for(int j=0; j<N; j++){
        goal = cdn[j];
        while(low <= high){
            mid = (low + high) / 2;

            if(cdn_sorted[mid] == goal){

            }

            if(cdn_sorted[mid] < goal) low = mid + 1;
            else if(cdn_sorted[mid] > goal) high = mid - 1;
        }
    }
    
    

}