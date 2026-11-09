#include <stdio.h>

int main(void)
{
    int tests;
    scanf("%d", &tests);
    while (tests--) {
        int n, bid, highest = 0, second = 0, winner = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &bid);
            if (bid > highest) { second = highest; highest = bid; winner = i; }
            else if (bid > second) second = bid;
        }
        printf("%d %d\n", winner, second);
    }
    return 0;
}
