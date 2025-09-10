#include <stdio.h>

#define N 200

int main(int argc, char *argv[])
{
    float under = 1.0f;
    float over = 1.0f;

    for (int i = 0; i < N; i++) {
        under /= 2.0f;
        over *= 2.0f;
        printf("Step %d, under = %e, over = %e\n", i+1, under, over);
    }

	return 0;
}
