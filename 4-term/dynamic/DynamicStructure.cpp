
#include <iostream>

struct Node {
    int d;
    Node *next;
    Node *prev;
};
//формирование первого элемента
Node* first(int d) {
    Node *pv = new Node;
    pv->d = d;
    pv->next = 0;
    pv->prev = 0;
    return pv;
}
//добавление в конец списка
void add(Node **pend, int d) {
    Node *pv = new Node;
    pv->d = d;
    pv->next = 0;
    pv->prev = *pend;
    (*pend)->next = pv;
    *pend = pv;
}
//поиск элемента по ключу
Node* find(Node* const pbeg, int d) {
    Node* pv = pbeg;
    while (pv) {
        if (pv->d == d) break;
        pv = pv->next;
    }
    return pv;
}
//удаление элемента
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
//вставка элемента
Node* insert (Node * const pbeg, Node **pend, int key, int d){
    if(Node *pkey = find(pbeg, key)){
        Node *pv = new Node;
        pv->d = d;
        // 1 - установление связи нового узла с последующим:
        pv->next = pkey->next;
        // 2 - установление связи нового узла с предыдущим:
        pv->prev = pkey;
        // 3 - установление связи предыдущего узла с новым:
        pkey->next = pv;
        // 4 - установление связи последующего узла с новым:
        if(pkey != *pend) { (pv->next)->prev = pv; }
        // Обновление указателя на конец списка, если узел вставляется в конец:
        else *pend = pv;
        return pv;
    }
    return 0;
}


int main()
{
    Node *pbeg = first(1);//формирование первого элемента списка
    Node *pend = pbeg;//
    //добавление в конец 4х элементов
    for (int i = 2; i < 6; ++i) add(&pend, i);
    //вставка элемента 200 после элемента 2
    insert(pbeg, &pend, 2, 200);
    //удаление элемента 5
    if (!remove(&pbeg, &pend, 5)) std::cout << "not found";
    Node* pv = pbeg;
    while (pv) { //вывод списка на экран
        std::cout << pv->d << ' ';
        pv = pv->next;
    }
    return 0;
}
