#include <iostream>

using namespace std;

template <typename T>

class queue {
private:
	T* arr;								//큐 원소 넣는 배열
	int q_size;							//큐의 사이즈
	int frontCursor;					//큐의 front가리키는 커서
	int rearCursor;						//큐의 back가리키는 커서

public:
	queue() {							//초기화
		q_size = 0;
		arr = new T[10000];
		frontCursor = 5000;
		rearCursor = 5000;
	}
	~queue() {
		delete[] arr;
	}

	void push(T elem){						//원소 넣기
		arr[rearCursor] = elem;
		rearCursor++;
        q_size++;

	}
	void pop(){						//원소 빼기
		if (q_size!=0) {						//비어있지 않을 때
			arr[frontCursor] = 0;
			frontCursor++;
            q_size--;
		}
		else {
			cout << "큐가 비어있습니다." << '\n';
		}
	}
	T front(){								//큐의 제일 앞 값(먼저 빠짐)
		return arr[frontCursor];
	}
	T back(){								//큐의 제일 뒷 값
		return arr[rearCursor-1];
	}
    T get(int idx){
        return arr[frontCursor+idx];
    }
	bool empty(){							//큐가 비어있는지 여부
		if (q_size==0)
			return true;
		else return false;
	}
	int size(){								//큐의 크기
		return q_size;
	}
    void makeEmpty(){
        while(q_size>0) pop();
    }
};

int main(){
    int T;
    cin >> T;

    for(int i=0; i<T; i++){
        int N, M;
        cin >> N >> M;

        queue<int> qforimp;
        queue<int> qforidx;
        int cnt = 0;

        for(int j=0; j<N; j++){
            int temp;
            cin >> temp;
            qforimp.push(temp);
            qforidx.push(j);
        }

        if(N==1) cout << "1" << endl;

        while(qforimp.size()>0){
            int temp = qforimp.front();
            for(int k=1; k<N; k++){
                if(temp < qforimp.get(k)){
                    qforimp.pop();
                    qforimp.push(temp);

                    temp = qforidx.front();
                    qforidx.pop();
                    qforidx.push(temp);

                    break;
                }

                if(k==N-1){
                    qforimp.pop();
                    cnt++;

                    if(qforidx.front() == M){
                        cout << cnt << endl;
                        qforidx.makeEmpty();
                        qforimp.makeEmpty();
                    } 
                    else qforidx.pop();
                }
            }
        }

        
    }
}