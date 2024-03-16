#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    vector<int> have(N);
    for(int i=0; i<N; i++){
        cin >> have[i];
    }

    sort(have.begin(), have.end());

    int M;
    cin >> M;

    for(int j=0; j<M; j++){
        int find;
        cin >> find;

        int low = 0;
        int high = have.size();
        int mid, cnt;

        while(low <= high){
            mid = (low + high) / 2;

            if(have[mid] == find){
                cnt = 1;

                int temp = mid - 1;
                while(have[temp] == find){
                    cnt++;
                    temp--;
                }
                temp = mid + 1;
                while(have[temp] == find){
                    cnt++;
                    temp++;
                }
                cout << cnt << " ";
                break;
            }

            if(have[mid] < find){ low = mid + 1; }
            else if(have[mid] > find){ high = mid - 1; }
        }
        if(cnt > 0){
            cnt = 0;
        }
        else{
            cout << "0 ";
        }

    }

}