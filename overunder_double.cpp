#include <stdio.h>

#define N 1100

int main(int argc, char *argv[])
{
    double under = 1.0f;
    double over = 1.0f;

    for (int i = 0; i < N; i++) {
        under /= 2.0f;
        over *= 2.0f;
        printf("Step %d, under = %e, over = %e\n", i+1, under, over);
    }

	return 0;
}
