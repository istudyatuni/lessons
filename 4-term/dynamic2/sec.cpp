#include <iostream>
using namespace std;

struct Node {
    int d;
    Node *prev, *next;
};

Node* first(int d) {
    Node *pv = new Node;
    pv->d = d;
    pv->next = 0;
    pv->prev = 0;
    return pv;
}

void add(int d, Node **pend) {
    Node *pv = new Node;
    pv->d = d;
    pv->next = 0;
    pv->prev = *pend;
    (*pend)->next = pv;
    *pend = pv;
}

int main() {
    cout << "need 1 element. enter 0 for stop";
    cout << "\nenter elements: ";
    int t;
    cin >> t;
    Node *pbeg, *pend;
    if (t % 2 == 0) {
        pbeg = first(t);
        pend = pbeg;
        add(0, &pend);
    } else {
        pbeg = first(t * t);
        pend = pbeg;
    }
    while(t) {
        cin >> t;
        if(t) {
            if (t % 2 == 0) {
                add(t, &pend);
                add(0, &pend);
            } else {
                add(t * t, &pend);
            }
        }
    }
    Node *pv = pbeg;
    while(pv) {
        cout << pv->d << ' ';
        pv = pv->next;
    }
    return 0;
}