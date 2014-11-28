#include <cstdio>
#include <queue>
#include <cstdlib>
#include <stack>

using namespace std;

FILE *in = fopen( "dfs.in", "r" );
int M, N, i, j, u, v, **E, *V;
stack< int > A;

void DFS( int node, int needle ) {
    int i, front;

    if ( node == needle ) {
        printf( "Needle found.\n" );
        return;
    }
    for ( i = 0; i < N; ++i ) {
        if ( E[ node ][ i ] && !V[ i ] ) {
            V[ i ] = 1;
            A.push( i );
        }
    }
    if ( A.size() ) {
        front = A.top();
        A.pop();
        DFS( front, needle );
    }
}

void printEdges() {
    printf( "# " );
    for ( i = 0; i < N; ++i ) {
        printf( "%i ", i );
    }
    printf( "\n" );
    for ( i = 0; i < N; ++i ) {
        printf( "%i ", i );
        for ( j = 0; j < N; ++j ) {
            printf( "%i ", E[ i ][ j ] );
        }
        printf( "\n" );
    }
}

int main() {
    fscanf( in, "%i %i", &M, &N );

    E = ( int** )malloc( N * sizeof( int* ) );
    V = ( int* )malloc( N * sizeof( int ) );
    for ( i = 0; i < N; ++i ) {
        E[ i ] = ( int* )malloc( N * sizeof( int ) );
        V[ i ] = 0;

        for ( j = 0; j < N; ++j ) {
            E[ i ][ j ] = 0;
        }
    }

    for ( i = 0; i < M; ++i ) {
        fscanf( in, "%i %i", &u, &v );
        E[ u - 1 ][ v - 1 ] = 1;
        E[ v - 1 ][ u - 1 ] = 1;
    }

    V[ 0 ] = 1;
    DFS( 0, 10 );
    return 0;
}