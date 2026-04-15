#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int n = strlen(s);
    int seen[26] = {0};  // track occurrences of each character

    for (int i = 0; i < n; i++) {
        int idx = s[i] - 'a';
        if (seen[idx] == 1) {
            // second occurrence found → first repeated character
            printf("%c\n", s[i]);
            return 0;
        }
        seen[idx]++;
    }

    // If no repeated character
    printf("-1\n");
    return 0;
}
