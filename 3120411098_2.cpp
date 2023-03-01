#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};
//khoi tao
struct Node *initNode (int n) //t?o 1 h�m c� t�n initNode truy?n v�o 1 bi?n n, h�m tr? v? 1 node
{
    struct Node *newNode = new Node; //khai b�o v� t?o 1 node m?i c� t�n newNode
    newNode->data = n; //gi� tr? c?a newNode = gi� tr? bi?n n truy?n v�o h�m
    newNode->next = NULL; //v?a kh?i t?o n�n node->next = NULL
    return newNode; //tr? v? 1 Node
}
//them node vao cuoi
void addNode (Node *head,int n) //khai b�o 1 h�m c� t�n addNode ?? th�m 1 node v�o cu?i dslk, truy?n v�o h�m 1 Node head v� 1 bi?n n l� gi� tr? c?a node ta s? th�m v�o dslk
{
    Node *newNode = new Node; //khai b�o v� t?o 1 Node m?i c� t�n newNode
    newNode->data = n; //Node v?a t?o c� gi� tr? = n ta truy?n v�o h�m
    newNode->next = NULL; //node v?a t?o n�n ->next = NULL

    Node *cur = head; //khai b�o 1 Node c� t�n cur tr? ??n con tr? head d�ng ?? duy?t dslk
    while(cur) //?i?u ki?n cur != NULL
    {
        if (cur->next == NULL) //l�c n�y ?ang ? node cu?i c?a dslk
        {
            cur->next = newNode; //t?o m?i li�n k?t gi?a node cu?i v� node m?i v?a t?o
            return; //tho�t v�ng l?p
        }
        cur = cur->next; //n?u kh�ng th?a m�n ?i?u ki?n if th� th?c duy?t ti?p ?? ki?m tra Node kh�c
    }
}
//them vao dau
void InsertFront (Node **head, int n) //t?o 1 h�m c� t�n InsertFront truy?n v�o 1 Node c� t�n head do l� khi th�m v�o con tr? head s? thay ??i n�n ta c?n truy?n tham chi?u v� 1 bi?n n l� gi� c?a node ta s? th�m v�o
{
    Node *newNode = new Node; //khai b�o v� t?o 1 node m?i c� t�n newNode
    newNode->data = n; //gi� tr? c?a node m?i = gi� tr? c?a bi?n ta truy?n v�o
    newNode->next = *head; //t?o m?i li�n k?t gi?a Node v?a t?o v?i node ??u ti�n c?a dslk v� c?n th�m v�o ??u dslk
    *head = newNode; //c?p nh?t l?i con tr? head, v� l�c n�y node v?a t?o ?� l� node ??u ti�n c?a dslk
}
// tim node co khoa
struct Node *searchNode (struct Node *head, int n) //t?o h�m c� t�n searchNode tr? v? 1 node, truy?n v�o h�m 1 Node t�n head v� 1 bi?n n l� gi� tr? c?a node c?n t�m
{
    Node *cur = head; //khai b�o 1 Node c� t�n cur tr? ??n con tr? head d�ng ?? duy?t dslk
    while (cur) //?i?u ki?n ?? th?c hi?n v�ng l?p
    {
        if (cur->data == n) //?� t�m ra node c?n t�m
        {
            return cur; //tho�t v�ng l?p
        }
        cur = cur->next; //n?u ch?a t�m th?y duy?t sang node k? ti?p ??n h?t dslk
    }
    cout << " Khong tim thay.\n ";  //n?u duy?t xong dslk m� kh�ng t�m th?y node xu?t ra d�ng Khong tim thay.
}
// xoa node
void deleteNode (Node **head, int n) //t?o h�m c� t�n deleteNode truy?n v�o 1 Node c� t�n head do con tr? head c� th? thay ??i khi x�a n�n ta c?n truy?n v�o tham chi?u v� 1 bi?n n l� gi� tr? c?a node ta c?n x�a
{
    Node *cur = *head; //khai b�o 1 Node c� t�n cur tr? ??n con tr? head d�ng ?? duy?t dslk
    Node *pre = NULL; //khai b�o 1 Node t�n pre cho tr? ??n NULL m?c ?�ch d�ng ?? x�a node kh�c node ??u dslk
    if (cur->data == n) //tr??ng h?p t�m th?y gi� tr? node c?n x�a ngay node ??u dslk
    {
        *head = cur->next; //di chuy?n con tr? head sang node k? ti?p
        delete cur; //x�a node c?n x�a
        return; //tho�t v�ng l?p
    }
    else //tr??ng h?p node c?n x�a kh�c node ??u ti�n 
        while (cur != NULL && cur->data != n) //?i?u ki?n duy?t v�ng l?p ?? t�m node c?n x�a
        {
            pre = cur; //cho con tr? pre tr? ??n cur
            cur = cur->next; //cho con tr? cur di chuy?n ??n node k? ti?p
        }
    if (cur == NULL) //tr??ng h?p duy?t h?t dslk t?c l� node c?n x�a ko c� 
        return; //tho�t ?i?u ki?n if
    pre->next = cur->next; //tr??ng h?p t�m ???c node c?n x�a th� ta cho con tr? pre tr? ??n node k? ti?p c?a node cur ?? t?o m?i li�n k?t
    delete cur; //x�a node cur c?ng ch�nh l� node c?n x�a
}
//in danh sach 
void Print (Node *head) //t?o h�m c� t�n Print truy?n v�o 1 Node t�n head d�ng ?? in ra dslk
{
    Node *cur = head; //khai b�o v� t?o 1 Node t�n cur tr? ??n head d�ng ?? duy?t dslk
    while (cur) //?i?u ki?n ?? th?c hi?n v�ng l?p
    {
        cout << cur->data << " "; //xu?t ra gi� tr? data c?a node
        cur = cur->next; //di chuy?n ??n node ti?p theo
    }
    cout << endl;
}
//dao danh sach
void reverse (Node **head)
{
    Node *cur = *head ;
    Node *pre = NULL;
    Node *next = NULL;
    while (cur)
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    *head = pre;
}
//copy list
Node *Copy (Node *head)
{
	if (head == NULL)
	return NULL;

	else 
	{
		Node *cur = head;
		Node *newL = new Node;
		newL->data = cur->data;
		newL->next = NULL;
		
		while (cur->next != NULL)
		{
			cur = cur->next;
			addNode (newL, cur->data);
		}
		return newL;
	}
}
//xoa danh sach
void deleteList (Node **head)
{
    Node *cur = *head;
    while (cur)
    {
        *head = cur->next;
        delete cur;
        cur = *head; 
    }
}
//sosanh
void Compare (Node *head, Node *head2)
{
    Node *cur = head;
    Node *cur2 = head2;

    while ( cur!=NULL && cur2 != NULL)
    {
        if (cur->data != cur2->data)
        {
            cout <<"Not same";
            return;
        }
        cur = cur->next;
        cur2 = cur2->next;
    }
    if (cur==NULL && cur2 == NULL)
    cout <<"Same";
    else
    cout <<"Not same";
}

int main ()
{
    Node *head;
    head = initNode(1);
    addNode (head, 2);
    addNode (head, 3);
    addNode (head, 4);
    addNode (head, 5);
    InsertFront (&head,0);
    Print (head);
    
    //head = searchNode (head,1);
    //if (head != 0)
    {
    	//cout<<"Co node trong List";
	}
    
    //deleteNode(&head,0);
    //cout <<"List is: ";
	//Print(head);
    
    //reverse(&head);
    //cout <<"List after: ";
    //Print(head);
    
    //cout <<"Copy list: ";
    //head = Copy(head);
    //Print (head);
    
    //cout<<"Sau khi xoa";
    //deleteList(&head);
    //Print(head);

	/*
    Node *head2;
    head2 = initNode(1);
    addNode (head2, 2);
    addNode (head2, 3);
    addNode (head2, 4);
    addNode (head2, 5);
    InsertFront (&head2,0);
    Print (head2);
	Compare(head, head2);
	*/
	//Print(head);
	
	return 0;
}
