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

Node* find(Node* const pbeg, int d) {
    Node* pv = pbeg;
    while (pv) {
        if (pv->d == d) break;
        pv = pv->next;
    }
    return pv;
}

void swap(Node* const pbeg, int a, int b) {
    Node* m = find(pbeg, a);
    Node* n = find(pbeg, b);
    m->d = b;
    n->d = a;
}

int main() {
    cout << "need 1 element. enter 0 for stop";
    cout << "\nenter elements: ";
    int t;
    cin >> t;
    Node *pbeg = first(t), *pend = pbeg;
    Node *mx = pbeg, *mn = pbeg;
    while(t) {
        cin >> t;
        if(t) {
            add(t, &pend);
            if (pend->d > mx->d) {
                mx = pend;
            }
            if (pend->d < mn->d) {
                mn = pend;
            }
        }
    }
    swap(pbeg, mx->d, mn->d);
    Node *pv = pbeg;
    while(pv) {
        if (pv == mx) {
            cout << mx->d << ' ';
        } else if (pv == mn) {
            cout << mn->d << ' ';
        } else {
            cout << pv->d << ' ';
        }
        pv = pv->next;
    }
    return 0;
}
/*
void swap(Node *a, Node *b) {
    Node *c = new Node, *d = new Node;
    //c = a, d = b
    c->d = a->d;
    c->next = a->next;
    c = a;
    //
    d->d = b->d;
    d->next = b->next;
    d->next = b->next;
    //b = c, a = d
    b->d = c->d;
    b->next = c->next;
    b->next = c->next;
    //
    a->d = d->d;
    a->next = d->next;
    a->next = d->next;
}*/