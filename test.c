#include <stdio.h>
#include <stdlib.h>


int main(int ac, char **av) {
    int nb;

    nb = atoi(av[1]);
    printf("%u\n", (unsigned int)nb);
    return 0;
}