#include "rule.h"

/* prints a row */
void print(u8 *a, u8 N)
{
        for (u8 i = 0; i < N; i++) {
                if (a[i])
                        printf("$");
                else
                        printf(".");
        }
        puts("\r");
}

int main(int argc, char* argv[]) 
{
        /* 
         * if wrong number of args provided,
         * then massage with instruction how to run 
         */

        if (argc != 4) {

                puts(
"Run this program from shell like $ ./this_program 22 33 100.\n"
"Provide 3 arguments:\n\t"
        "First arg (22 in this case) is the rule number R from {0..255}.\n\t"
        "Second arg (33) is the number of rows M printed.\n\t"
        "Third arg (100) is the number of chars in row N.\n"
"Running like above should produce a gorgerous Serpinsky triangle.\n"
"If it's a messi, may be 101 is too wide for your screen and text size.\n");

                return 0;

        } else {

                /*
                 * R - rule number from {0..256}
                 * M & N - dimentions:
                 * M - down - number of rows 
                 * N - to the right - number of chars in row
                 */

                const u8  R = atoi(argv[1]);
                const u64 M = atol(argv[2]);
                const u8  N = atoi(argv[3]);

                /* index i is for a row; index j is for an element of a row; */
                u8 **rows = malloc(M * sizeof(u8 *));
                for (u64 i = 0; i < M; i++) 
                        rows[i] = calloc(N, sizeof(u8 *));

                /*
                 * add some interesting initial conditions here
                 * right now it just puts 1 in the middle of the firts row
                 * it's a reasonable default but can be quite fun to modify
                 */
                 
                 rows[0][N / 2] = 1; 

                /*apply rule & print */
                for (u64 i = 0; i < M - 1; i++) {
                        for (u8 j = 0; j < N; j++) {
                     
/*
 * a[3] are the 3 cells determining rows[i + 1][j] together with the rule
 * modular arithmetic is used to topologically glue 
 * the left and the wright edge together
 * so what prints out actualy lives on the surface of a cylinder
 * and not a finite width rectangle wich makes it way nicer
 * a[3] are in rows[i] for determining rows[i + 1]
 */

                                u8 a[3] = {
/* (j - 1 % N) is a predescessor */     rows[i][(j - 1) % N], 
/* of j in additive group mod N  */     rows[i][j],
/* (j + 1) % 1 - successor of j  */     rows[i][(j + 1) % N]
                                          };

                                rows[i + 1][j] = rule(a, R);
                        }

                        print(rows[i], N);

                        /* time in seconds over million (microseconds) */
                        usleep(16000);
                }

                for (u64 i = 0; i < M; i++) 
                        free(rows[i]);
                free(rows); 
        
        }
}
