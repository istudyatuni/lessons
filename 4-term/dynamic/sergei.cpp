#include "iostream"
using namespace std;


struct Node{
	int info;
	Node *next;
	Node *prev;
};


Node * first(int info){
	Node *nd = new Node;
	nd->info = info;
	nd->next = 0;
	nd->prev = 0;
	return nd;
}

void add(Node **pend, int info){
	Node *nd = new Node;
	nd->info = info;
	nd->next = 0;
	nd->prev=*pend;
	(*pend)->next = nd;
	*pend = nd;
}


Node* Find(Node* const pbeg, int key){
	Node* nd=pbeg;
	while(nd){
		if (nd->info==key) break;
		nd=nd->next;
	}
	return nd;
}

bool del(Node** pbeg,Node** pend, int key){

	if (Node* pkey=Find(*pbeg,key)){

		if (pkey == *pbeg){
			*pbeg = (*pbeg)->next;
			(*pbeg)->prev =0;}

		else if (pkey == *pend){
			*pend = (*pend)->prev;
			(*pend)->next =0;}

		else{
			(pkey->prev)->next = pkey->next;
			(pkey->next)->prev = pkey->prev;}
		delete pkey;
		return true;

	}
	return false;

}


Node *Input (Node * const pbeg, Node **pend, int key, int info){
	if(Node *pkey = Find(pbeg, key)){
		Node *nd = new Node;
		nd->info = info;
		nd->next = pkey->next;

		nd->prev = pkey;

		pkey->next = nd;

		if( pkey != *pend)
			(nd->next)->prev = nd;

		else *pend = nd;

		return nd;
	}
	return 0;
}


int main()
{
    int n,x;
    cout<<"Enter n:";  cin>>n;
    cout<<"Enter x:"; cin>>x;

	Node *pbeg = first(x);
	Node *pend = pbeg;
	add(&pend, 0);
	for (int i = 1; i<n; i++){
		cin>>x;

		add(&pend, x);
		add(&pend, 0);
	}

	Node* nd=pbeg;
	while (nd){
		cout<<nd->info<<' ';
		nd=nd->next;
	}




    cout<<"\n\nEx 2"<<endl;
    cout<<"Enter n:";  cin>>n;
    cout<<"Enter x:"; cin>>x;

	Node *pbeg2 = first(x);
	Node *pend2 = pbeg2;

	for (int i = 1; i<n; i++){
		cin>>x;

		add(&pend2, x);

		if(Find(pbeg2,x)->info % 2 == 1)
        {
            del(&pbeg2,&pend2,x);

        }
	}

	for(int i=1; i<n;i++)
    {

	}


	Node* nd2=pbeg2;
	while (nd2){
		cout<<nd2->info<<' ';
		nd2=nd2->next;
	}
	return 0;
}











/*#include <iostream>
using namespace std;


struct Node{
    int n;
    Node *next;
    Node *prev;
};

Node *Add_First(int n)
{
    Node *pv = new Node;
    pv->n;
    pv->next=0;
    pv->prev=0;
    return pv;
}


void add(Node **pend, int x)
{
    Node *pv = new Node;
    pv->n = x;
    pv->next=0;
    pv->prev = *pend;
}


Node *Find(Node *const pbeg, int n)
{
    Node *pv=pbeg;
    while(pv){
        if(pv->n == n)break;
        pv = pv->next;
    }
    return pv;
}

Node *Input(Node *const pbeg, Node **pend, int key, int n)
{
    if(Node *pKey = Find(pbeg,key))
    {
        Node *pv = new Node;
        pv->n = n;
        pv->next = pKey->next;
        pv->prev = pKey;
        pKey->next = pv;
        if(pKey != *pend)(pv->next)->prev=pv;
        else *pend = pv;
        return pv;
    }
}

/*void printNode(Node *const pbeg)
{
    Node *pv = pbeg;
    while(pv)
    {
        cout<<pv->n<<" ";
        pv = pv->next;
    }
}

int main()
{
    int n,x;
    Node *pBeg = Add_First(1);
    Node *pEnd = pBeg;

    cout<<"Enter num of input: "; cin>>n;

    for(int i=0; i<n; i++)
    {
        cout<<"Enter x for Node: "; cin>>x;
        add(&pEnd, x);
    }


    Node *pv = pBeg;
    while(pv)
    {
        cout<<"Element: "<<pv->n<<" ";
        pv = pv->next;
    }



}

*/








/*
#include <iostream>
using namespace std;


struct Node
{
    int data;
    int key;
    Node *next;
    Node *prev;

};


class ListNodes
{
private:
    Node *head;
public:

    ListNodes(){head = NULL;}

    void addNode(int n)
    {
        Node *pv = new Node;
        pv->data = n;
        pv->next = NULL;
        if(head == NULL)
            head = pv;
        else
        {
            Node *cur = head;

            while(cur->next != NULL)
                cur = cur->next;

            cur->next = pv;
        }
    }


    int FindNode(int k)
    {
        Node *counter = head;
        while(counter)
        {
            if(counter->key == k)
                return counter->data;
            counter = counter->next;
        }
    }

    void printList()
    {
        Node *current = head;
        cout<<"List: ";
        while(current != NULL)
        {
            cout << current->data <<" ";
            current = current->next;
        }
    }
};



int main()
{

    int n,x;
    ListNodes List1;

    cout<<"Enter num of input: "; cin>>n;


    for(int i=0; i<n; i++)
    {
        cout<<"Enter x for Node: "; cin>>x;
        List1.addNode(x);
    }

    List1.printList();
    return 0;
}

*/



/*
#include <iostream>
using namespace std;

class Node        //���� ����, �������������� � ���� ���������
{
friend class List;//��������� ����� ������ �������������, ����� �� ���� ������ � �������� �����
private:
    int key;       //����� ���� � ������
    int data;      //������, ������������ � ����
    Node *next;    //��������� �� ��������� ���������
    Node *last;    //��������� �� ���������� ���������
public:
    Node(int data, Node *next, Node *last)
    {
        this->data = data;
        this->next = next;
        this->last = last;
    }
    Node(int data)
    {
        this->data = data;
    }
};




class List        //�����, ����������� ������ "������"
{
private:
    Node *head;   //������ ������ (��������� �� ������ ���� � ������)

public:
    List() : head(NULL) //� ������ ��������� ������� ��������� ����� ����, �.�. ���������� ������� ��� ��� � ��������� �� �� ���
    {}
    void addNodeEnd(int data)     //�����, ����������� ���� � ����� ������
    {
        Node *nd = new Node(data, NULL, temp); //������� ����� ����, ��������� � ���� ������ � ������ ��� ���������, ���������� NULL
        temp = nd;
        if(head)
        {
            Node *current = head;  //��������� �� ������ ������, �� ������ ����; � ������������ � ����� ��� ���������� ����������� ����
            while(current->next)   //������������ � ����� ��� ������, ���� �� ������ �� ���������� ����, ������������� �� ����������
                current = current->next; //��������� �� ��������� ����
                current->next = nd;    //���������� ��������� �� ��������� ����
        }
        else                       //���� ������ ��� ���� � ��������� ������ ����, �� ������ ��������� �� ����
            head = nd;             //� ������ ������ ��� ���������: ��� ���� NULL, ���� ��������� �� ������ ���� � ������
        numNode(); //�������� ���� ������
    }

    int find(int k) //����� �� ����� � ������
    {
        Node *counter = head;
        while(counter)
        {
            if(counter->key == k)
                return counter->data;
            counter = counter->next;
        }
    }

    void printListForward() const //������� �� ������ ��� ������ � ������ �������
    {
        Node *current = head;
        while(current)             //���� �� ������ �� ���������� ����
        {
            cout << current->key << " - " << current->data << endl;   //������� ������ �� �����
            current = current->next;         //��������� � ���������� ����
        }
    }


    void numNode() //���������� �������-�������, �������� ���� ������
    {
        Node *counter = head;
        int i = 0;
        while(counter)
        {
            counter->key = ++i;
            counter = counter->next;
        }
    }
};
int main()
{



    List n; //������� ��������� ������ List
    int key;
    n.addNodeEnd(21);  //�������� ����� addNode ������ List (���������� ����)
    n.addNodeEnd(32);
    n.addNodeEnd(47);
    n.addNodeEnd(63);
    n.addNodeEnd(78);
    n.addNodeEnd(83);
    n.addNodeEnd(97);
    n.addNodeEnd(98);
    n.printListForward();
    cout << endl;
    n.printListBack();
    n.addNodeBeginning(17);
    n.addNodeBeginning(15);
    n.addNodeBeginning(10);
    n.addNodeBeginning(3);
    cout << endl;
    n.printListForward();
    n.deleteNodeEnd();
    cout << endl;
    n.printListForward();
    n.deleteNodeBeginning();
    cout << endl;
    n.printListForward();
    cout << "Enter a number of node: ";
    cin >> key;
    cout << "Data node " << key << " = " << n.find(key) << endl;
}

*/








