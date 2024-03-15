#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> cdn(N);
    vector<int> cdn_sorted(N);

    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        cdn[i] = temp;
        cdn_sorted[i] = temp;
    }

    sort(cdn_sorted.begin(), cdn_sorted.end());
    cdn_sorted.erase(unique(cdn_sorted.begin(), cdn_sorted.end()), cdn_sorted.end());

    
    for(int j=0; j<N; j++){
        int low = 0;
        int high = cdn_sorted.size();
        int mid;
        
        while(low <= high){
            mid = (low + high) / 2;
            if(cdn[j] == cdn_sorted[mid]){
                cout << mid << " ";
                break;
            }

            if(cdn[j] > cdn_sorted[mid]){ low = mid + 1; }
            else if(cdn[j] < cdn_sorted[mid]){ high = mid - 1; }
        }
    }



}