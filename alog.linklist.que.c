#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct Node {
    int valueue;
    struct Node* next;
} Node;

typedef struct Que {
    int Size;
    Node* Front;
    Node* Rear;
} Que;

void enque(Que* q, int valueue);
Que* create_que();
Node* create_note(int valueue);

int main(int argc, char* argv[])
{
    Que* que = create_que();
    enque(que, 10);
    enque(que, 30);
    enque(que, 40);
    enque(que, 50);
    return EXIT_SUCCESS;
}

void enque(Que* q, int valueue)
{
    Node* NODE = create_note(valueue);
    if (q->Front == NULL) {
        q->Front = q->Rear = NODE;
    } else {
        q->Rear->next = NODE;
        q->Rear = NODE;
    }
    q->Size++;
}

Que* create_que()
{
    Que* q = malloc(sizeof(Que));
    q->Front = q->Rear = NULL;
    q->Size = 0;
    return q;
}

Node* create_note(int valueue)
{
    Node* new_NODE = malloc(sizeof(Node));
    new_NODE->valueue = valueue;
    new_NODE->next = NULL;
    return new_NODE;
}

