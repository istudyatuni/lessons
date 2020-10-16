#include <iostream>
using namespace std;

struct Node {
    int d;
    Node *next;
    Node *prev;
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

void remove_index(Node **pbeg, Node **pend, int i) {
    //циклом пройти до индекса i, разобраться на месте
    Node *pv = *pbeg;
    int k = 0;
    while(pv->next) {
        if (k < i) {
            k++;   
        } else if (k == i) {
            //remove
            if (pv == *pbeg) {
                *pbeg = (*pbeg)->next;
                (*pbeg)->prev = 0;
            } else if (pv == *pend) {
                *pend = (*pend)->prev;
                (*pend)->next = 0;
            } else {
                (pv->prev)->next = pv->next;
                (pv->next)->prev = pv->prev;
            }
            return;
        } else {
            cerr << "not found this item\n";
            return;
        }
    }
}

void remove(Node **pbeg, Node **pend, Node *rem) {
    if (rem == *pbeg) {
        *pbeg = (*pbeg)->next;
        (*pbeg)->prev = 0;
    }
    else if (rem == *pend) {
        *pend = (*pend)->prev;
        (*pend)->next = 0;
    }
    else {
        (rem->prev)->next = rem->next;
        (rem->next)->prev = rem->prev;
    }
}

int main() {
    cout << "need 1 element. enter 0 for stop";
    cout << "\nenter elements: ";
    int t;
    cin >> t;
    Node *pbeg = first(t);
    Node *pend = pbeg;
    while(t) {
        cin >> t;
        if(t) {
            add(t, &pend);
        }
    }
    Node *pv = pbeg;
    while(pv) {
        if ((pv->d)%2) {
            remove(&pbeg, &pend, pv);
        }
        pv = pv->next;
    }
    pv = pbeg;
    while(pv) {
        cout << pv->d << ' ';
        pv = pv->next;
    }
    return 0;
}
