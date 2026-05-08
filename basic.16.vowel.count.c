#include <ctype.h>
#include <stdio.h>
#include <unistd.h>

int vowel_count(char letter);
int main(int argc, char* argv[])
{
    char sentence[256];
    char vowel = 0;
    int index = 0;



    printf("Enter Sentence : ");
    fgets(sentence, sizeof(sentence), stdin);

    while (sentence[index] != '\0') {
        vowel += vowel_count(sentence[index]);
        index++;
    }
    printf("Total Vowel in this sentence %d", vowel);
    write(1, sentence, sizeof(sentence));
    return 0;
}

int vowel_count(char letter)
{
    letter = tolower(letter);
    switch (letter) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return 1;
    }
    return 0;
}
