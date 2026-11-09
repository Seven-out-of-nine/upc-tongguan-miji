#include <stdio.h>

int main(void) {
    int n; scanf("%d", &n);
    int best_length, best_diameter, best_id;
    scanf("%d%d%d", &best_length, &best_diameter, &best_id);
    for (int i = 1; i < n; ++i) {
        int length, diameter, id; scanf("%d%d%d", &length, &diameter, &id);
        if (length > best_length ||
            (length == best_length && diameter < best_diameter) ||
            (length == best_length && diameter == best_diameter && id > best_id)) {
            best_length = length; best_diameter = diameter; best_id = id;
        }
    }
    printf("%d\n", best_id); return 0;
}
