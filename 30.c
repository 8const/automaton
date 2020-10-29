#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t u8;
typedef uint16_t u16;

void print(u8 *a)
{
        for (u8 i = 0; i < 169; i++)
                printf("%d", a[i]);
}

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


int main(void) 
{
        u8 in[3] = {1, 1, 1}; 
        printf("%d\n", rule30(in));
        u8 in1[3] = {1, 1, 0}; 
        printf("%d\n", rule30(in1));
        u8 in2[3] = {1, 0, 1}; 
        printf("%d\n", rule30(in2));
        u8 in3[3] = {1, 0, 0}; 
        printf("%d\n", rule30(in3));
        u8 in4[3] = {0, 1, 1}; 
        printf("%d\n", rule30(in4));
        u8 in5[3] = {0, 1, 0}; 
        printf("%d\n", rule30(in5));
        u8 in6[3] = {0, 0, 1}; 
        printf("%d\n", rule30(in6));
        u8 in7[3] = {0, 0, 0}; 
        printf("%d\n", rule30(in7));
        return 0;
}

/*
 *char **a = malloc(169 * sizeof(char *));
 *     for (int j = 0; j < 1024; j++) {
 *              a[j] = malloc(169);
 *     }
 */

 
