#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

typedef uint8_t u8;
typedef uint64_t u64;

/*
 * returns 1 if bit in byte, 0 otherwise
 * this is used to decode binary represetation of a rule number
 */
u8 bit(u8 byte, u8 bit) 
{
        switch (bit) {

        case 7:
                return (byte & 1);
        case 6:
                return (byte & 2) / 2;
        case 5:
                return (byte & 4) / 4;
        case 4:
                return (byte & 8) / 8;
        case 3:
                return (byte & 16) / 16;
        case 2:
                return (byte & 32) / 32;
        case 1:
                return (byte & 64) / 64;
        case 0:
                return (byte & 128) / 128;
        
       }
}



/* quite literally the definition of rule n */
u8 rule(u8 a[3], u8 n)
{
        if (a[0] && a[1] && a[2])
                return bit(n, 0);

        if (a[0] && a[1] && !a[2])
                 return bit(n, 1);

        if (a[0] && !a[1] && a[2])
                 return bit(n, 2);

        if (a[0] && !a[1] && !a[2])
                return bit(n, 3);

        if (!a[0] && a[1] && a[2])
                return bit(n, 4);

        if (!a[0] && a[1] && !a[2])
                return bit(n, 5);

        if (!a[0] && !a[1] && a[2])
                return bit(n, 6);
}
