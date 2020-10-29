#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t u8;
typedef uint64_t u64;

/* prints a row */
void print(u8 *a)
{
        for (u8 i = 0; i < 169; i++)
                printf("%d", a[i]);
        puts("\r");
}

/* quite literally the definition of rule 30 */
u8 rule30(u8 a[3])
{
        if (a[0] == 1 && a[1] == 1 && a[2] == 1)
                return 0;
        if (a[0] == 1 && a[1] == 1 && a[2] == 0)
                 return 0;
        if (a[0] == 1 && a[1] == 0 && a[2] == 1)
                 return 0;
        if (a[0] == 1 && a[1] == 0 && a[2] == 0)
                return 1;
        if (a[0] == 0 && a[1] == 1 && a[2] == 1)
                return 1;
        if (a[0] == 0 && a[1] == 1 && a[2] == 0)
                return 1;
        if (a[0] == 0 && a[1] == 0 && a[2] == 1)
                return 1;
        if (a[0] == 0 && a[1] == 0 && a[2] == 0)
                return 0;
}

/* predecessor of j in additive group mod N */
u8 pred(u8 j, u8 N)
{
        if (j == 0)
                return N - 1;
        else
                return j - 1;
}

/* successor of j in additive group mod N */
u8 succ(u8 j, u8 N)
{
        if (j == N - 1)
                return 0;
        else
                return j + 1;
}


int main(int argc, char* argv[]) 
{

        /*
         * dimentions:
         * M - down \/ 
         * N - to the right > 
         */

        u64 const M = atol(argv[1]);
        u8  const N = atoi(argv[2]);


        /* index i is for a row; index j is for an element of a row; */
        u8 **rows = malloc(M * sizeof(u8 *));
        for (u64 i = 0; i < M; i++) 
                rows[i] = calloc(N, sizeof(u8 *));
        

        /* some initial conditions that are enough for fun */
        rows[0][2] = 1; 
        rows[0][4] = 1; 
        rows[0][5] = 1; 
        rows[0][7] = 1; 
        
        /*apply rule & print */
        for (u64 i = 0; i < M - 1; i++) {
                for (u8 j = 0; j < N - 1; j++) {
                        u8 a[3] = {rows[i][pred(j, N)], rows[i][j], rows[i][succ(j, N)]};
                        rows[i + 1][j] = rule30(a);
                }
                print(rows[i]);
        }

        /* deallocation */
        for (u64 i = 0; i < M; i++) 
                free(rows[i]);
        free(rows); 
}

