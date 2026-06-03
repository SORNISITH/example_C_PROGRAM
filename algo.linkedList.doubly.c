#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valueue;
    struct Node* next;
    struct Node* prev;
} Node;

Node* create_NODE(int x);
Node* push(Node* head, int valueue);
void display_list(Node* list);
void destroy_list(Node* list);

void push_p(Node** head, int valueue);
void pop(Node** list)
{

    if (*list == NULL) {
        return;
    }
    Node* temp = *list;
    *list = (*list)->next;

    free(temp);
}

int main(int argc, char* argv[])
{

    Node* List = NULL;
    push_p(&List, 10);
    push_p(&List, 20);
    push_p(&List, 30);
    push_p(&List, 40);
    push_p(&List, 50);
    display_list(List);
    destroy_list(List);
    return EXIT_SUCCESS;
}

void destroy_list(Node* list)
{
    if (list == NULL) {
        return;
    }
    destroy_list(list->next);
    free(list);
}

void display_list(Node* list)
{
    if (list == NULL) {
        return;
    }
    if (list->next == NULL) {
        printf("%d -> NULL ", list->valueue);
    } else {
        printf("%d -> ", list->valueue);
    }
    display_list(list->next);
}

Node* push(Node* head, int valueue)
{
    Node* new_NODE = create_NODE(valueue);
    if (head == NULL) {
        return new_NODE;
    }
    new_NODE->next = head;
    head->prev = new_NODE;
    head = new_NODE;
    return new_NODE;
}

void push_p(Node** head, int valueue)
{
    Node* new_NODE = create_NODE(valueue);
    if (*head == NULL) {
        *head = new_NODE;
        return;
    }
    new_NODE->next = *head;
    (*head)->prev = new_NODE;
    *head = new_NODE;
}
Node* create_NODE(int valueue)
{
    Node* NODE = malloc(sizeof(Node));
    if (NODE == NULL)
        return NULL;
    NODE->valueue = valueue;
    NODE->prev = NULL;
    NODE->next = NULL;
    return NODE;
}
