#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int n = strlen(s);
    int freq[26] = {0};

    // Count frequency of each character
    for (int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
    }

    // Find the first character with frequency = 1
    for (int i = 0; i < n; i++) {
        if (freq[s[i] - 'a'] == 1) {
            printf("%c\n", s[i]);
            return 0;
        }
    }

    // If all characters repeat
    printf("$\n");
    return 0;
}
