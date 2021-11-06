#include <stdio.h>
#include "unistd.h"

char cat(int a, int b, char *buf){
    // cat a and b to string buf
    sprintf(buf,"%d%d", a, b);
    return 0;
}
int main() {
    int a = 100;
    int b = 50;
    char buf[50];

    cat(a, b, buf);
    printf("%s", buf);
    return 0;
}
