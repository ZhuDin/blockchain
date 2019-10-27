#include <stdio.h>

int main() {
    int cock, hen, chick;
    for (cock = 0; cock <= 20; cock++) {
        for (hen = 0; hen <= 33; hen++) {
            for (chick = 3; chick <= 99; chick++) {
                if ((5*cock + 3*hen + chick/3) == 100) {
                    if ((cock + hen + chick) == 100) {
                        if (chick%3 == 0) {
                            printf("cock: %d, hen: %d, chick: %d\n", cock, hen, chick);
                        }
                    }
                }
            }
        }
    }
}