#include <stdio.h>

#define N 200

int main(int argc, char *argv[])
{
    unsigned int under = 1;
    unsigned int over = 1;

    while (1) {
        int last = under;
        under--;

        if (!(last > under)) {
            printf("Underflow at %u (new value %u)\n", last, under);
            break;
        }
    }

    while (1) {
        int last = over;
        over++;

        if (!(last < over)) {
            printf("Overflow at %u (new value %u)\n", last, over);
            break;
        }
    }

	return 0;
}
