#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next = 0;
    Node(int d) {
        data = d;
    }
};

class Queue {
    // head ...... tail
    Node* tail = 0;
    Node* head = 0;
    int __size = 0;
public:
    void push(int n) {
        Node* node = new Node(n);
        if (tail) {
            tail->next = node;
        } else {
            head = node;
        }
        tail = node;
        __size++;
    }
    int pop() {
        Node* node = head;
        head = head->next;
        int ret = node->data;
        delete node;
        __size--;
        if (__size == 0) {
            tail = 0;
        }
        return ret;
    }
    bool empty() {
        return __size == 0;
    }
};

int main() {
    Queue q;
    int n = 1, a;
    cout << "enter a: ";
    cin >> a;
    cout << "enter elements(0 for stop): ";
    while (n) {
        cin >> n;
        if (n % a == 0 && n) {
            q.push(n);
        }
    }
    while(!q.empty()) {
        cout << q.pop() << ' ';
    }
    cout << endl;
    return 0;
}