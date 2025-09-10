#include <stdio.h>

#define N 200

int main(int argc, char *argv[])
{
    int under = 1;
    int over = 1;

    while (1) {
        int last = under;
        under--;

        if (!(last > under)) {
            printf("Underflow at %d (new value %d)\n", last, under);
            break;
        }
    }

    while (1) {
        int last = over;
        over++;

        if (!(last < over)) {
            printf("Overflow at %d (new value %d)\n", last, over);
            break;
        }
    }

	return 0;
}
