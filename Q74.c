#include <stdio.h>
#include <string.h>

#define MAX 1000
#define NAME_LEN 50

// Structure to store candidate name and vote count
struct Candidate {
    char name[NAME_LEN];
    int votes;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Candidate candidates[MAX];
    int count = 0;

    for (int i = 0; i < n; i++) {
        char temp[NAME_LEN];
        scanf("%s", temp);

        // Check if candidate already exists
        int found = -1;
        for (int j = 0; j < count; j++) {
            if (strcmp(candidates[j].name, temp) == 0) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            candidates[found].votes++;
        } else {
            strcpy(candidates[count].name, temp);
            candidates[count].votes = 1;
            count++;
        }
    }

    // Find candidate with maximum votes
    char winner[NAME_LEN];
    int maxVotes = -1;

    for (int i = 0; i < count; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            strcpy(winner, candidates[i].name);
        } else if (candidates[i].votes == maxVotes) {
            // Tie → choose lexicographically smaller
            if (strcmp(candidates[i].name, winner) < 0) {
                strcpy(winner, candidates[i].name);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);
    return 0;
}
