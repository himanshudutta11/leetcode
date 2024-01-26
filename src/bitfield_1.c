
// C Program to show what happends when out of range value
// is assigned to bit field member
#include <stdio.h>
 
struct test {
    // Bit-field member x with 2 bits
    unsigned int x : 2;
    // Bit-field member y with 2 bits
    unsigned int y : 2;
    // Bit-field member z with 2 bits
    unsigned int z : 2;
};
 
int main()
{
    // Declare a variable t of type struct test
    struct test t;
    // Assign the value 5 to x (2 bits)
    t.x = 5;
 
    // Print the value of x
    printf("%d", t.x);
 
    return 0;
}