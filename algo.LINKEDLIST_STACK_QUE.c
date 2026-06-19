// #define LINKLISTED_STR_IMPLEMENT
// #include "nzlib.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Word {
    int len;
    char* w;
    struct Word* next;
    struct Word* prev;
} Word;

typedef struct STRING {
    int size;
    Word* HEAD_WORD;
    Word* TAIL_WORD;
} STRING;

void deque(STRING* self);
void display_reverse(STRING* self, char seperator);
void pop(STRING* self);
void kill(STRING* self);
void push(STRING* self, char* str, size_t len);
void display(STRING* self, char seperator);
Word* make_NODE(char* str, size_t len);
void kill_a_word(Word* word);
STRING* NEW_LIST();
void enque(STRING* self, char* str, size_t len);

int main(int argc, char* argv[])
{
    STRING* newstr = NEW_LIST();
    push(newstr, "mypush", 10);
    push(newstr, "mypush", 10);
    push(newstr, "mypush", 10);
    push(newstr, "mypush", 10);
    push(newstr, "mypush", 10);
    push(newstr, "mypush", 10);
    push(newstr, "mypush", 10);
    push(newstr, "mypush", 10);
    push(newstr, "mypush", 10);
    push(newstr, "mypush", 10);
    push(newstr, "secound mypush", 20);
    push(newstr, "last mypush", 15);
    enque(newstr, "enque", 30);
    enque(newstr, "enque", 30);
    enque(newstr, "sec enque", 30);
    enque(newstr, "last enque", 30);
   enque(newstr, "mylassssss", 2000);
    deque(newstr);
    pop(newstr);
    //    display_reverse(newstr, '<');
    printf("\n");
    display(newstr, '>');
    kill(newstr);
    return EXIT_SUCCESS;
}

STRING* NEW_LIST()
{
  STRING* new = malloc(sizeof(*new));
    new->HEAD_WORD = NULL;
    new->TAIL_WORD = NULL;
    new->size = 0;
    return new;
}

void display(STRING* self, char seperator)
{
    if (self == NULL) {

        return;
    }
    Word* current = self->HEAD_WORD;
    printf("LINKED_LIST SIZE ( %d ) :", self->size + 1);
    while (current != NULL) {
        Word* next = current->next;
        if (next == NULL) {
            printf(" %s > NULL", current->w);
        } else {
            printf(" %s %c", current->w, seperator);
        }
        current = next;
    }
}

void display_reverse(STRING* self, char seperator)
{
    if (self == NULL) {
        return;
    }
    Word* current = self->TAIL_WORD;
    printf("LINKED_LIST SIZE ( %d ) :", self->size + 1);
    while (current != NULL) {
        Word* next = current->prev;
        if (next == NULL) {
            printf(" %s > NULL", current->w);
        } else {
            printf(" %s %c", current->w, seperator);
        }
        current = next;
    }
}

void push(STRING* self, char* str, size_t len)
{
    Word* new_NODE = make_NODE(str, len);
    if (self->HEAD_WORD == NULL) {
        self->HEAD_WORD = new_NODE;
        self->TAIL_WORD = new_NODE;
        return;
    }
    new_NODE->next = self->HEAD_WORD;
    self->HEAD_WORD->prev = new_NODE;
    self->HEAD_WORD = new_NODE;
    self->size++;
    return;
};
void deque(STRING* self)
{
    Word* tmp = self->TAIL_WORD;
    self->TAIL_WORD = self->TAIL_WORD->prev;
    self->TAIL_WORD->next = NULL;
    kill_a_word(tmp);
    // free(self->TAIL_WORD->next->w);
    // free(self->TAIL_WORD->next);
}
void enque(STRING* self, char* str, size_t len)
{
    Word* new_NODE = make_NODE(str, len);
    if (self->HEAD_WORD == NULL && self->TAIL_WORD == NULL) {
        self->HEAD_WORD = new_NODE;
        self->TAIL_WORD = new_NODE;
        return;
    }
    self->TAIL_WORD->next = new_NODE;
    new_NODE->prev = self->TAIL_WORD;
    self->TAIL_WORD = new_NODE;
    self->size++;
    return;
}

void pop(STRING* self)
{
    Word* tmp = self->HEAD_WORD;
    Word* next = tmp->next;
    if (tmp == NULL) {
        return;
    }
    kill_a_word(tmp);
    self->HEAD_WORD = next;
    self->HEAD_WORD->prev = NULL;
};

Word* make_NODE(char* str, size_t len)
{
    Word* ch = malloc(sizeof(Word));
    if (ch == NULL)
        return NULL;
    ch->w = malloc(len + 1);
    ch->len = len;
    strcpy(ch->w, str);
    ch->next = NULL;
    ch->prev = NULL;
    return ch;
}

void kill_a_word(Word* w)
{
    free(w->w);
    free(w);
}

void kill(STRING* self)
{
    Word* current = self->HEAD_WORD;
    while (current != NULL) {
        Word* next = current->next;
        kill_a_word(current);
        current = next;
    }
    free(self);
}
