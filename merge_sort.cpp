#include <iostream>
using namespace std;
struct node {
    int val;
    node* next;
};

void add(node* &H, int x) {
    node *p = new node;
    p->val = x;
    p->next = H;
    H = p;
}
void del(node *&H)
{
    if(H != NULL)
    {
        node *p = H;
        H = p->next;
        delete p;
    }
}
void show(node* &H) {
    node *p = H;
    cout << "H -> ";
    while(p != NULL) {
        cout << p->val << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}
void merge(node *&H1, node *&H2, node *&H3) {
    add(H3,0);
    node *T = H3;

    while(H1 && H2){
        if(H1->val < H2->val){
            T->next = H1;
            H1 = H1 -> next;
            T=T->next;
        }
        else {
            T->next = H2;
            H2 = H2 -> next;
            T = T->next;
        }
    }
    if(H1 == NULL){
        T->next = H2;
        H2 = NULL;
    }
    else{
        T->next = H1;
        H1 = NULL;
    }
    del(H3);
}

void split(node *&H, node *&H1, node *&H2 )
{
    node * p1, * p2;
    bool s = false;
    add( H1, 0 );
    add( H2, 0 );
    p1 = H1;
    p2 = H2;
    while(H)
    {
        if( s )
        {
            p2->next = H;
            p2 = p2->next;
        }
        else
        {
            p1->next = H;
            p1 = p1->next;
        }
        H = H->next;
        s = !s;
    }
    p1->next = p2->next = NULL;
    del( H1 );
    del( H2);
}

void MergeSort(node *&H)
{
    if(H && H->next)
    {
        node *H1 = NULL;
        node *H2 = NULL;
        split(H,H1,H2);
        MergeSort(H1);
        MergeSort(H2);
        merge(H1,H2,H);
    }

}

int main() {
    node *H = NULL;
    add(H,10);
    add(H,7);
    add(H,16);
    add(H,4);
    add(H,53);
    add(H,32);
    add(H,11);
    show(H);
    MergeSort(H);
    show(H);
    return 0;
}
