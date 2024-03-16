#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0; // 현재 시간
    
    sort(times.begin(), times.end());
    
    long long low = 1;
    long long high = n * (long long)times.back();
    long long mid, cnt;
    
    while(low <= high){
        mid = (low + high) / 2;
        cnt = 0;
        
        for(int i=0; i<times.size(); i++){
            cnt += (mid / (long long) times[i]);
        }
        if(cnt >= n){
            high = mid - 1;
            answer = mid;
        }
        else { low = mid + 1; }
    }
    
    return answer;
}