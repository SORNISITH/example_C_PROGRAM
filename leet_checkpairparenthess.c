#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
bool isPair(char a, char b)
{
    switch (a) {
    case '(':
        if (b == ')')
            return true;
        break;
    case '[':
        if (b == ']')
            return true;
        break;
    case '{':
        if (b == '}')
            return true;
        break;
    }
    return false;
}

bool isValid(char* s)
{
    size_t len = strlen(s);
    char open_stack[len + 1];
    int open_sindex = 0;
    for (int i = 0; i < len; ++i) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            ++open_sindex;
            open_stack[open_sindex] = s[i];
        } else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (isPair(open_stack[open_sindex], s[i])) {
                printf("%c", s[i]);
                printf("%c", open_stack[open_sindex]);
                --open_sindex;
            } else {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char* argv[])
{
    bool x = isPair('[', '}');
    printf("%d", x);
    return 0;
}
