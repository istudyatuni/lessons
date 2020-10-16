#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node(int d, Node* p) {
        data = d;
        prev = p;
    }
};

class Stack {
    Node* top = 0;
    int __size = 0;
    Node* inner_push(int t, Node* current) {
        if (__size == 0) {
            __size++;
            return new Node(t, 0);
        }
        Node* pv = new Node(t, current);
        __size++;
        return pv;
    }
    Node* inner_pop(Node* current) {
        Node* pv = current->prev;
        delete current;
        __size--;
        return pv;
    }
public:
    Stack() {
    }
    void push(int t) {
        top = inner_push(t, top);
    }
    int pop() {
        if (__size == 0) {
            cerr << "error: stack is empty\n";
            exit(1);
        }
        int ret = top->data;
        top = inner_pop(top);
        return ret;
    }
    int size() {
        return __size;
    }
};

int main() {
    Stack st;
    int n;
    while (cin >> n) {
        if (n < 0) {
            st.push(n * n);
        } else {
            st.push(n);
        }
    }
    while(st.size()) {
        cout << st.pop() << ' ';
    }
    return 0;
}