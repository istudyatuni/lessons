#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
    Node* top = 0;
    int __size = 0;
public:
    void push(int a) {
        Node* node = new Node();
        node->data = a;
        node->next = top;
        top = node;
        __size++;
    }
    int pop() {
        Node* node = top;
        int rt = top->data;
        top = top->next;
        delete node;
        __size--;
        return rt;
    }
    int back() {
        return top->data;
    }
    int size() {
        return __size;
    }
    bool empty() {
        return __size == 0;
    }
    void clear() {
        while (__size) {
            pop();
        }
    }
};

int main() {
    Stack st;
    st.push(3);
    for (int i = -7; i < 10; ++i)
    {
        st.push(i);
        if (i*i>12) st.pop();
    }
    while(!st.empty()) {
        cout << st.pop() << ' ';
    }
    return 0;
}