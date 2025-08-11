#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_LEN 1000

int main() {
    char paragraph[MAX_LEN];
    char words[MAX_WORDS][50];
    int count[MAX_WORDS] = {0};
    int totalWords = 0;

    fgets(paragraph, sizeof(paragraph), stdin);

    for (int i = 0; paragraph[i]; i++)
        paragraph[i] = ispunct(paragraph[i]) ? ' ' : tolower(paragraph[i]);

    char *token = strtok(paragraph, " \t\n");
    while (token) {
        int found = 0;
        for (int i = 0; i < totalWords; i++) {
            if (strcmp(words[i], token) == 0) {
                count[i]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(words[totalWords], token);
            count[totalWords] = 1;
            totalWords++;
        }
        token = strtok(NULL, " \t\n");
    }

    for (int i = 0; i < totalWords; i++)
        printf("%s: %d\n", words[i], count[i]);

    return 0;
}
