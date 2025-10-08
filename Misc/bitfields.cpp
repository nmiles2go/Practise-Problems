// // C Program to illustrate the structure without bit field
// #include <iostream>

// // A simple representation of the date
// struct date {
//     unsigned int d;
//     unsigned int m;
//     unsigned int y;
// };

// int main()
// {
//     // printing size of structure
//     printf("Size of date is %lu bytes and size of unsigned int is %u bytes.\n",
//            sizeof(struct date), sizeof(unsigned int));
//     struct date dt = { 31, 12, 2014 };
//     printf("Date is %d/%d/%d", dt.d, dt.m, dt.y);
// }

// // C program to demonstrate use of Bit-fields
// #include <stdio.h>

// // Space optimized representation of the date
// struct date {
//     // d has value between 0 and 31, so 5 bits
//     // are sufficient
//     int d : 5;

//     // m has value between 0 and 15, so 4 bits
//     // are sufficient
//     int m : 4;

//     int y;
// };

// int main()
// {
//     struct date dt = { 31, 12, 2014 };
//     printf("Size of date is %lu bytes and size of int is %d bytes.\n",
//            sizeof(struct date), sizeof(int));
//     printf("Date is %d/%d/%d", dt.d, dt.m, dt.y);
//     return 0;
// }

#include <stdio.h>

struct test {
    // Unsigned integer member x
    unsigned int x;
    // Bit-field member y with 33 bits
    long int y : 33;
    // Unsigned integer member z
    unsigned int z;
};

int main()
{
    // Print the size of struct test
    printf("%lu", sizeof(struct test));

    return 0;
}