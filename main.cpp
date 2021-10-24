#include <iostream>

using namespace std;


int main( )
{
    int maks = 2147483647;
    int ** d;
    int i, j, k; //zmienne pomocniczne do operowania na petlach
    int n; //ilosc wierzcholków
    int m; //ilosc krawedzi;
    int x,y,w; // wagi krawedzi



    cin >> n >> m;
    string sciezka[n][n];

    d = new int * [ n ];
    for( i = 0; i < n; i++ )
    {
        d [ i ] = new int [ n ];
        for( j = 0; j < n; j++ )
            {
            d [ i ][ j ] = maks;
            sciezka[i][j]="";
            }
        d [ i ][ i ] = 0;
        sciezka[i][i]="-0-";
    }

    for( i = 0; i < m; i++ )
    {
        cin >> x >> y >> w;
        d [ x ][ y ] = w;
        sciezka[x][y]=to_string(x) + ">" + to_string(y);
    }


    for( k = 0; k < n; k++ )
        for( i = 0; i < n; i++ )
            for( j = 0; j < n; j++ )
            {
                if( ( d [ i ][ k ] == maks ) || ( d [ k ][ j ] == maks ) )
                    continue;
                w = d [ i ][ k ] + d [ k ][ j ];
                if( d [ i ][ j ] > w )
                    {d [ i ][ j ] = w;
                    sciezka[i][j]=sciezka[i][k] + " dalej " + sciezka[k][j] ;
                    }
            }

    cout << endl;

    for( i = 0; i < n; i++ )
        for( j = 0; j < n; j++ )
        {
            cout << "d [ " << i << ", " << j << " ] = ";
            if( d [ i ][ j ] == maks )
                cout << "Brak sciezki!";
            else
                cout << d [ i ][ j ] << "    sciezka:  " << sciezka[i][j];
            cout << endl;
        }


    for( i = 0; i < n; i++ )
        delete [ ] d [ i ];
    delete [ ] d;

    return 0;
}
