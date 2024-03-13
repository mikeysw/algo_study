#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    int idx = 0;
    int total_w = 0;
    queue<int>q;

    while(true){
        if(idx==truck_weights.size()){
            answer += bridge_length;
            break;
        }

        answer++;

        int temp = truck_weights[idx];

        if(q.size() == bridge_length){
            total_w -= q.front();  
            q.pop();  
        }

        if(total_w + temp <= weight){  
            total_w += temp;  
            q.push(temp);  
            idx++;  
        }
        else{ q.push(0); }
    }

    return answer;
}