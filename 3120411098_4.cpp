#include <iostream>
#include <math.h>
using namespace std;

struct Node {
    int indexdata;
    Node *left;
    Node *right;
};
//H�m kh?i t?o 1 node
struct Node *createNode (int n) // khai b�o 1 h�m c� t�n l� createNode tr? v? 1 node, truy?n v�o 1 bi?n n l� gi� tr? c?a node ?�
{
    Node *newNode = new Node;  // khai b�o v� t?o 1 node m?i c� t�n l� newNode
    newNode->left = NULL;  // khi v?a kh?i t?o n�n c�y con tr�i = NULL
    newNode->right = NULL;  // khi v?a kh?i t?o n�n c�y con ph?i = NULL
    newNode->indexdata = n;  // gi� tr? c?a newNode = gi� tr? n ta truy?n v�o h�m
    return newNode; // tr? v? 1 node
}

struct Node *InsertNode (Node *root, int n) //1 h�m c� t�n l� InsertNode d�ng ?? ch�n 1 node m?i v�o c�y c� gi� tr? n, ??u v�o ta truy?n v�o h�m 1 c�i g?c v� 1 bi?n n. H�m tr? v? 1 g?c
{
    if (root == NULL) // n?u g?c = NULL
        root = createNode(n); // ta g?i h�m t?o m?i ?? ch�n 1 node v?i gi� tr? n
    if (n < root->indexdata) // n?u gi� tr? c?a node m?i ta mu?n th�m v�o < gi� tr? node g?c
        root->left = InsertNode (root->left, n); // th� ta g?i ?? quy ?? th�m node v�o b�n tr�i
    if (n > root->indexdata) // n?u gi� tr? c?a node m?i ta mu?n th�m v�o > gi� tr? node g?c
        root->right = InsertNode (root->right, n); // th� ta g?i ?? quy ?? th�m node v�o b�n ph?i
    return root; // tr? v? 1 c�i g?c
}

struct Node *minValue(struct Node *root) //khai b�o h�m c� t�n minValue truy?n v�o 1 c�i g?c v� tr? v? 1 node d�ng ?? t�m node con nh? nh?t b�n tr�i ph?c v? cho vi?c x�a Node c� 2 con
{
    Node *cur = root; //khai b�o v� t?o 1 Node cur v� g�n = root d�ng ?? duy?t ?? t�m node con nh? nh?t b�n tr�i
    while(cur != NULL && cur->left != NULL) //v�ng l?p v?i ?i?u ki?n cur != NULL v� cur->left != NULL v� c?n t�m node con nh? nh?t b�n tr�i n�n cur->left != NULL n?u cur->left = NULL t?c l� ?� t�m ?c node c?n t�m n�n s? d?ng v�ng l?p
    {
        cur = cur->left; // n?u th?a ?i?u ki?n th� duy?t ??n node k? ti?p
    }
    return cur; // tr? v? c�i node c?n t�m
}
struct Node *deleteNode(struct Node *root, int data) //khai b�o h�m c� t�n deleteNode v� truy?n v�o 1 g?c v� 1 bi?n data l� gi� tr? c?a node c?n x�a, h�m tr? v? 1 c�i g?c
{
    if(root == NULL) //n?u root = NULL ??ng ngh?a kh�ng c� node c?n x�a trong c�y ch? c?n tr? v? g?c
        return root; // tr? v? g?c
    
    if(data < root->indexdata) // n?u gi� tr? c?a node c?n x�a < node g?c th� ta ?i t�m node c?n x�a ?� b�n c�y con tr�i
        root->left = deleteNode(root->left,data); // g?i ?? qui t�m node c?n x�a b�n c�y con tr�i
    else if (data > root->indexdata) // n?u gi� tr? c?a node c?n x�a < node g?c th� ta ?i t�m node c?n x�a ?� b�n c�y con ph?i
        root->right = deleteNode(root->right,data); // g?i ?? qui t�m node c?n x�a b�n c�y con tr�i
    else //l�c n�y n?u node c?n x�a c� t?n t?i trong c�y th� ta s? thi h�nh c�c c�u l?nh trong h�m else t?c l� hi?n t?i ta ?� t�m ra node c?n x�a (data == root->indexdata)
    {
        //1 child or leaf
        if(root->left == NULL) // n?u node con c?a node c?n x�a = NULL th� ?�y l� c�y con ph?i
        {
            Node *temp = root->right; // khai b�o v� t?o m?t Node temp v� g�n = gi� tr?  c?a c�y con ph?i c?a node c?n x�a ?? l?u l?i gi� tr? c�y con ph?i node c?n x�a
            delete root; // sau ?� x�a node c?n x�a
            return temp; // return temp ?? c?p nh?t l?i m?i li�n k?t c?a node g?c v?i temp
        }
        else if(root->right == NULL) // n?u node con c?a node c?n x�a = NULL th� ?�y l� c�y con tr�i
        {
            Node *temp = root->left; // khai b�o v� t?o m?t Node temp v� g�n = gi� tr?  c?a c�y con tr�i c?a node c?n x�a ?? l?u l?i gi� tr? c?a c�y con tr�i node c?n x�a
            delete root; // sau ?� x�a node c?n x�a
            return temp; ; // return temp ?? c?p nh?t l?i m?i li�n k?t c?a node g?c v?i temp
        }
        //2 child
        Node *temp = minValue(root->right); // khai b�o v� t?o 1 node temp v� g�n = gi� tr? c?a node con nh? nh?t b�n tr�i
        root->indexdata = temp->indexdata; // g�n node c?n x�a = gi� tr? c?a node con nh? nh?t b�n tr�i
        root->right = deleteNode(root->right, temp->indexdata); // g?i ?? quy ?? x�a node con nh? nh?t b�n tr�i
    }
       return root; // tr? v? g?c
}

void DestroyTree (Node *root)  //t?o h�m c� t�n l� DestroyTree truy?n v�o 1 c�i g?c
{
    if (root != NULL) //?i?u ki?n n?u root != NULL
    {
        DestroyTree(root->left); //g?i ?? quy h?y b�n tr�i
        DestroyTree(root->right); //g?i ?? quy h?y b�n ph?i
        delete root; // h?y node g?c
    }
}

Node *findNode (Node *root, int n) //t?o h�m c� t�n finNode truy?n v�o 1 c�i g?c v� 1 bi?n n l� gi� tr? c?a node c?n t�m, h�m tr? v? 1 node
{
    if (root == NULL) //n?u root == NULL t?c l� kh�ng c� node c?n t�m
        return NULL; //n�n tr? v? NULL
    if (n < root->indexdata) //n?u gi� tr? c?n t�m < node g?c 
        return findNode (root->left, n); //th� g?i ?? quy t�m node b�n c�y con tr�i
    if (n > root->indexdata) //n?u gi� tr? c?n t�m > node g?c 
        return findNode (root->right, n); //th� g?i ?? quy t�m node b�n c�y con ph?i
    return root; //tr? v? node c?n t�m = NULL n?u kh�ng t�m ???c
}

void printLNR (Node *root) //t?o h�m c� t�n l� printLNR truy?n v�o 1 g?c ?? duy?t c�y 
{
    if (root != NULL) //n?u c�y kh�c r?ng
    {
        printLNR(root->left); //duy?t b�n tr�i
        cout << root->indexdata << " ";  //duy?t node g?c
        printLNR(root->right); //duy?t b�n ph?i
    }
}

void printNLR (Node *root) //t?o h�m c� t�n l� printNLR truy?n v�o 1 g?c ?? duy?t c�y 
{
        if (root != NULL) //n?u c�y kh�c r?ng
       {
               cout << root->indexdata <<" "; //duy?t node g?c
               printNLR(root->left); //duy?t b�n tr�i
               printNLR(root->right); //duy?t b�n tr�i
      }
}

void printRNL (Node *root) //t?o h�m c� t�n l� printRNL truy?n v�o 1 g?c ?? duy?t c�y 
{
               if (root != NULL) //n?u c�y kh�c r?ng
     {
               printRNL(root->right); //duy?t b�n tr�i
               cout << root->indexdata << " ";	 //duy?t node g?c
               printRNL(root->left); //duy?t b�n tr�i
     }	
}

bool SNT (int n)
{
	if (n < 2)
	{
		return false;
	}
	else 
	{
		for (int i = 2;i <= sqrt(n);i++)
		{
			if (n % i == 0)
				return false;
		}
	}
	return true;
}


int demsonguyento (Node *root, int &count)
{
	if (root != NULL)
	{
		if (SNT(root->indexdata) == true)
		{
			count++;
		}
		demsonguyento(root->left, count);
		demsonguyento(root->right, count);
	}
	return count;
}

int main ()
{
    Node *t = NULL;
    t = createNode (5);
    t = InsertNode (t, -5);
    t = InsertNode (t, 8);
    t = InsertNode (t, 7);
    t = InsertNode (t, 15);
    t = InsertNode (t, 14);
    t = InsertNode (t, 13);
    t = InsertNode (t, 20);
    printLNR (t);
    cout <<endl;

    deleteNode (t, 20);
    printLNR (t);
    //Node *f = findNode(t, 1);
    //if (f == NULL)
    {
        //cout <<"Khong co Node trong cay.\n";
    }
    //else
    {
        //cout <<"Co node trong cay.\n";
    }

    //cout <<"Destroy Tree";
    //DestroyTree (t);
    //printLNR (t);
    
    //cout <<"NLR: ";
    //printNLR(t);
    
    //cout<<"RNL: ";
    //printRNL(t);
    
    int count = 0;
	cout<<"So luong so nguyen to: " <<demsonguyento(t, count);
}

