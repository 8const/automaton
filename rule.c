#include "rule.h"

/*
 * returns 1 if bit in byte, 0 otherwise
 * this is used to decode binary represetation of a rule number
 */

u8 is_bit(u8 byte, u8 bit) 
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
                
        default:
                /*this should never happen*/
                puts("wrong second arg in call of is_bit"
                     "it should be from set {0, 1, 2, 3, 4, 5, 6, 7}");

                return 2;
       }
}

/* quite literally the definition of rule n */
u8 rule(u8 a[3], u8 n)
{
        if (a[0] && a[1] && a[2])
                return is_bit(n, 0);

        if (a[0] && a[1] && !a[2])
                 return is_bit(n, 1);

        if (a[0] && !a[1] && a[2])
                 return is_bit(n, 2);

        if (a[0] && !a[1] && !a[2])
                return is_bit(n, 3);

        if (!a[0] && a[1] && a[2])
                return is_bit(n, 4);

        if (!a[0] && a[1] && !a[2])
                return is_bit(n, 5);

        if (!a[0] && !a[1] && a[2])
                return is_bit(n, 6);

        if (!a[0] && !a[1] && !a[2])
                return is_bit(n, 7);

        else {
                /*this literally never happens by design*/
                puts("mistake in design of rule function in rule.c");
                return 2;
        }
}
