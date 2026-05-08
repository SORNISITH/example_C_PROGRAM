#include <ctype.h>
#include <stdio.h>
int face_valueue[26] = { 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3,
    1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10 };
int x = 0;
int check_letter(char letter);
int main(int argc, char* argv[])
{
    char buf[128];
    int sum = 0;
    printf("enter any words : ");
    scanf("%s", buf);
    for (int i = 0; buf[i] != '\0'; i++) {
        sum += check_letter(buf[i]);

    }
    printf("srable valueue : %d", sum);
    return 0;
}
int check_letter(char letter)
{
    // int face_valueue[26] = { 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10,
    // 1, 1, 1, 1, 4, 4, 8, 4, 10 }; a = 65  z = 90  a - a  = 0  z-a  = 25
    letter = toupper(letter);
    int valueue = 0;
    int index = 0;
    if (letter >= 'A' && letter <= 'Z') {
        index = (int)letter - 'A';
        valueue = face_valueue[index];
        printf("%d-\t%c\t: %d\n", x, letter, valueue);
        x++;
        return valueue;
    }
    return 0;
}
