#include <iostream>
#include <cstdio>
#include <cstring>

const int MAX_WORDS = 100;
const int MAX_WORD_LEN = 100;

int main() {
    char sentence[1000];

    scanf_s("%[^\n]s", sentence, (unsigned int)sizeof(sentence));

    char words[MAX_WORDS][MAX_WORD_LEN];
    int wordCount = 0;

    int i = 0;
    while (sentence[i] != NULL) 
    {
        while (sentence[i] == ' ') 
            i++;

        if (sentence[i] == NULL) 
            break;

        int j = 0;
        while (sentence[i] != ' ' && sentence[i] != NULL) 
        {
            words[wordCount][j++] = sentence[i++];
        }

        words[wordCount][j] = NULL;
        wordCount++;
    }
    ///bobble sort
    for (int a = 0; a < wordCount - 1; a++) 
    {
        for (int b = 0; b < wordCount - 1 - a; b++) 
        {
            int lenB = strlen(words[b]);
            int lenB1 = strlen(words[b + 1]);
            bool shouldSwap = false;
            if (lenB < lenB1)
            {
                shouldSwap = true;
            }
            else if (lenB == lenB1) 
            {
                if (strcmp(words[b], words[b + 1]) > 0)
                {
                    shouldSwap = true;
                }
            }

            if (shouldSwap) 
            {
                char temp[MAX_WORD_LEN];
                strcpy_s(temp, words[b]);
                strcpy_s(words[b], words[b + 1]);
                strcpy_s(words[b + 1], temp);
            }
        }
    }

    for (int k = 0; k < wordCount; k++) 
    {
        printf("%s\n", words[k]);
    }

    return 0;
}
