
#include <iostream>


struct Node {
    int d;
    Node* next;
    Node* prev;
};
Node* first(int d) {
    Node* pv = new Node;
    pv->d = d;
    pv->next = 0;
    pv->prev = 0;
    return pv;
}
void add(Node** pend, int d) {
    Node* pv = new Node;
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
bool remove(Node** pbeg, Node** pend, int key) {
    if (Node* pkey = find(*pbeg, key)) {
        if (pkey == *pbeg) {
            *pbeg = (*pbeg)->next;
            (*pbeg)->prev = 0;
        }
        else if (pkey == *pend) {
            *pend = (*pend)->prev;
            (*pend)->next = 0;
        }
        else {
            (pkey->prev)->next = pkey->next;
            (pkey->next)->prev = pkey->prev;
        }
        delete pkey;
        return true;
    }
    return false;
}
Node* insert(Node* const pbeg, Node** pend, int key, int d) {
    if (Node* pkey = find(pbeg, key)) {
        Node* pv = new Node;
        pv->d = d;
        pv->next = pkey->next;
        pv->prev = pkey;
        pkey->next = pv;
        if (pkey != *pend) { (pv->next)->prev = pv; }
        else *pend = pv;
        return pv;
    }
    return 0;
}

int find_Max(Node* const pbeg) {
    int mx = pbeg->d;
    Node* pv = pbeg;
    while (pv) {
        if (pv->d > mx) mx = pv->d;
        pv = pv->next;
    }
    return mx;
}

int find_Min(Node* const pbeg) {
    int mn = pbeg->d;
    Node* pv = pbeg;
    while (pv) {
        if (pv->d < mn) mn = pv->d;
        pv = pv->next;
    }
    return mn;
}

void swap_El(Node* const pbeg, int frst, int scnd) {
    Node* f = find(pbeg, frst);
    Node* s = find(pbeg, scnd);
    f->d = scnd;
    s->d = frst;
}

int main()
{
    int lenght;
    std::cin >> lenght;
    int input;
    std::cin >> input;
    Node* pbeg = first(input);
    Node* pend = pbeg;
    int mn = pbeg->d;
    int mx = pbeg->d;
    for (int i = 1; i < lenght; ++i) {
        std::cin >> input;
        add(&pend, input);
    }

    swap_El(pbeg, find_Max(pbeg), find_Min(pbeg));

    Node* pv = pbeg;
    while (pv) {
        std::cout << pv->d << ' ';
        pv = pv->next;
    }
    return 0;
}
