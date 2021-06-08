#include <iostream>
using namespace std;

#include <iostream>
using namespace std;
struct node {
    int val;
    node* next;
};

int count(node *&H)
{
    node *tmp = H;
    int count = 0;
    while(tmp != NULL)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
}
void find(node *&H, int x)
{
    node *tmp = H;
    for(int i=0; i<count(tmp); i++)
    {

    }
}

int length(node *&H){
    node *tmp = H;
    int count = 0;
    while(tmp != NULL){
        count++;
        tmp=tmp->next;
    }
    return count;
}
node* GetNth(node* head, int index)
{
    node* current = head;
    int count = 0;
    while (current != NULL) {
        if (count == index)
            return current;
        count++;
        current = current->next;
    }
}

void add(node* &H, int x) {
    node *p = new node;
    p->val = x;
    p->next = H;
    H = p;
}

void swapNodes(node *&H, node *x, node *y)
{
    node *prevX = NULL, *currX = H;
    while (currX && currX != x)
    {
        prevX = currX;
        currX = currX->next;
    }

    node *prevY = NULL, *currY = H;
    while (currY && currY != y)
    {
        prevY = currY;
        currY = currY->next;
    }

    if (currX == NULL || currY == NULL)
        return;

    if (prevX != NULL)
        prevX->next = currY;
    else
        H = currY;

    if (prevY != NULL)
        prevY->next = currX;
    else
        H = currX;

    node *temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}

void comb_sort(node *&H)
{
    node *p = H;
    int gap = length(p);
    bool replace = true;

    while( gap > 1 || replace )
    {
        gap = gap * 10 / 13;
        if( gap == 0 )
            gap = 1;

        replace = false;
        for( int i = 0; i + gap < length(p); i++ )
        {
            if(GetNth(p,i+gap)->val < GetNth(p,i)->val)
            {
                swapNodes(H, GetNth(p,i), GetNth(p,i+gap) );
                replace = true;
            }
        }
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

int main() {
    node *H = NULL;
    add(H,5);
    add(H,6);
    add(H,3);
    add(H,100);
    add(H,34);
    add(H,53);
    add(H,2);
    show(H);
    //nie dziala dla powyzej 9 elementow dla liscie
    comb_sort(H);
    show(H);

    return 0;
}
