#include <iostream>
using namespace std;

struct Node {
    int d;
    Node *next;
    Node *prev;
};

Node* first(int d, Node *pend) {
    Node *pv = new Node;//, *zero = new Node;
    pv->d = d;
    pv->next = pend;
    pv->prev = 0;
    //next element as 0
    pend->d = 0;
    pend->next = 0;
    pend->prev = pv;
    return pv;
}

void add(int d, Node **pend) {//Node *set,
    Node *pv = new Node;
    /*pv->d = d;
    pv->prev = *pend;
    (*pend)->d = 0;
    (*pend)->prev = pv;
    (*pend)->next = 0;
    pv->next = *pend;*/
    pv->d = d;
    pv->next = 0;
    pv->prev = *pend;
    (*pend)->next = pv;
    *pend = pv;
    /*zero->d = 0;
    zero->next = 0;
    pv->d = d;
    pv->prev = *pend;
    pv->next = zero;
    zero->prev = pv;
    *pend = zero;
    set = pv;*/
}

int main() {
    cout << "need 1 element. enter 0 for stop";
    cout << "\nenter elements: ";
    int t;
    cin >> t;
    Node *pend = new Node;
    Node *pbeg = first(t, pend);
    while(t) {
        cin >> t;
        if(t) {
            add(t, &pend);
            add(0, &pend);
        }
    }
    Node *pv = pbeg;
    while(pv) {
        cout << pv->d << ' ';
        pv = pv->next;
    }
    return 0;
}
