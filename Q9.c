#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    scanf("%s", str);  // read input string

    int len = strlen(str);

    // reverse the string
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }

    return 0;
}
