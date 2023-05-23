#include <iostream>

struct Node {
    int data;
    Node *next;
    Node *prev;
};

struct Deque {
    Node *front, *rear;
    int len = 0;

    Deque(){
        front = rear = nullptr;
    }

    int size(){
        return len;
    }

    bool isEmpty(){
        return len == 0;
    }

    int front_data() {
        if(isEmpty())
            return -1;
        return front->data;
    }

    int rear_data() {
        if(isEmpty())
            return -1;
        return rear->data;
    }

    void front_push(int data){
        Node *new_data = new struct Node;
        new_data->data = data;
        new_data->next = nullptr;
        if(isEmpty())
            front = rear = new_data;
        else{
            new_data->next = front;
            front->prev = new_data;
            front = new_data;
        }
        len++;
    }

    void rear_push(int data){
        Node *new_data = new struct Node;
        new_data->data = data;
        new_data->next = nullptr;
        if(isEmpty())
            front = rear = new_data;
        else{
            rear->next = new_data;
            new_data->prev = rear;
            rear = new_data;
        }
        len++;
    }

    int front_pop(){
        Node *del_Node = front;
        if(isEmpty())
            return -1;
        else{
            int ret = front->data;
            front = front->next;
            delete del_Node;
            len--;
            return ret;
        }
    }

    int rear_pop(){
        Node *del_Node = rear;
        if(isEmpty())
            return -1;
        else{
            int ret = rear->data;
            rear = rear->prev;
            delete del_Node;
            len--;
            return ret;
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    Deque q;
    int N;
    std::cin >> N;

    std::string command;
    int input;
    while(N--){
        std::cin >> command;
        if(command == "push_front"){
            std::cin >> input;
            q.front_push(input);
        }
        else if(command == "push_back"){
            std::cin >> input;
            q.rear_push(input);
        }
        else if(command == "pop_front"){
            std::cout << q.front_pop() << "\n";
        }
        else if(command == "pop_back"){
            std::cout << q.rear_pop() << "\n";
        }
        else if(command == "size"){
            std::cout << q.size() << "\n";
        }
        else if(command == "empty"){
            std::cout << q.isEmpty() << "\n";
        }
        else if(command == "front"){
            std::cout << q.front_data() << "\n";
        }
        else if(command == "back"){
            std::cout << q.rear_data() << "\n";
        }
    }
}