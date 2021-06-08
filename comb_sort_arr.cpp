#include <iostream>
using namespace std;

void swap(int &tab1, int &tab2)
{
    int tmp = tab1;
    tab1 = tab2;
    tab2 = tmp;
}

void comb_sort(int tab[], int size )
{
    int gap = size;
    bool replace = true;

    while( gap > 1 || replace )
    {
        gap = gap * 10 / 13;
        if( gap == 0 )
            gap = 1;

        replace = false;
        for( int i = 0; i + gap < size; i++ )
        {
            if( tab[ i + gap ] < tab[ i ] )
            {
                swap( tab[ i ], tab[ i + gap ] );
                replace = true;
            }
        }
    }

}

int main() {
    int tab[5] = {4,35,6,1,67};
    comb_sort(tab, 5);
    for(int i =0; i<5; i++)
    {
        cout << tab[i]<< " ";
    }


    return 0;
}
