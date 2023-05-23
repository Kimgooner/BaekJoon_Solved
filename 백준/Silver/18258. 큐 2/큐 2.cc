#include <iostream>

struct Node {
    int data;
    Node* next;
};

struct Queue {
    Node *front, *back;
    int len = 0;

    Queue(){
        front = back = nullptr;
    }

    int size(){
        return len;
    }

    int isEmpty(){
        if(len == 0) return 1;
        else return 0;
    }

    int front_data(){
        if(isEmpty())
            return -1;
        return front->data;
    }

    int back_data(){
        if(isEmpty())
            return -1;
        return back->data;
    }

    void push(int data){
        Node* new_data = new struct Node;
        new_data->data = data;
        new_data->next = nullptr;
        if(isEmpty()){
            front = back = new_data;
        }
        else{
            back->next = new_data;
            back = back->next;
        }
        len++;
    }

    int pop(){
        if(isEmpty())
            return -1;
        Node* pop_data = front;
        int ret = pop_data->data;
        front = pop_data->next;
        delete pop_data;
        len--;
        return ret;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    Queue q;
    int N;
    std::cin >> N;

    std::string command;
    int input;
    while(N--){
        std::cin >> command;
        if(command == "push"){
            std::cin >> input;
            q.push(input);
        }
        else if(command == "pop"){
            int ret = q.pop();
            std::cout << ret << "\n";
        }
        else if(command == "size"){
            int ret = q.size();
            std::cout << ret << "\n";
        }
        else if(command == "empty"){
            int ret = q.isEmpty();
            std::cout << ret << "\n";
        }
        else if(command == "front"){
            int ret = q.front_data();
            std::cout << ret << "\n";
        }
        else if(command == "back"){
            int ret = q.back_data();
            std::cout << ret << "\n";
        }
    }
}