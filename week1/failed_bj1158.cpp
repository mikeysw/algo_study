#include <iostream>
#include <string>

using namespace std;

struct node{
    int num;
    node* next;
};

class LinkedList{
private:
    node* head;
    node* tail;

public:
    LinkedList(){
        head = NULL;
        tail = NULL;
    }

    void addNode(int n);
    int deleteNode(node* prev);
    int deleteFirstNode();
    node* getHead(){ return head; }
};

void LinkedList::addNode(int n){
    node* temp = new node;
    temp -> num = n;
    temp -> next = NULL;

    if(head==NULL){
        head = temp;
        tail = temp;
    }
    else{
        tail -> next = temp;
        tail = temp;
    }
}

int LinkedList::deleteNode(node* prev){
    node* temp = prev -> next;
    int tempnum = temp -> num;
    prev -> next = temp -> next;

    delete temp;
    return tempnum;
}

int LinkedList::deleteFirstNode(){
    node* temp = getHead();
    int tempnum = temp -> num;

    delete temp;
    return tempnum;
}

int main(){
    int arr[5000];
    int N, K, turn;
    cin >> N >> K;

    LinkedList l;
    
    for(int i=1; i<N+1; i++){
        l.addNode(i);
    }

    for(int j=N; j>0; j--){
        turn = K % j;

        node* temp = l.getHead();
        if(turn==1) arr[K-j] = l.deleteFirstNode();
        else if(turn==2) arr[K-j] = l.deleteNode(l.getHead());
        else{
            for(int t=0;t<turn-2;t++){
                temp = temp->next;
            }
            arr[K-j] = l.deleteNode(temp);
        }
        
    }

    cout << "<";
    for(int i=0; i<N-1; i++){
        cout << arr[i] << ", ";
    }
    cout << arr[N] << ">";


}


