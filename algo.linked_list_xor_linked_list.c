#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// TODO : workinhg enque and deque
struct Node {
    int value;
    uintptr_t xptr; // using xor  new_node ^ prev_node_xptr
};

struct LINKED_LISTED_XOR { // storage for front and rear
    size_t size;
    struct Node* Head;
    struct Node* Tail;
};

struct LLX_STEP_CONTROLLER { // controll temp movement of node
    uintptr_t prev_xptr;
    uintptr_t current_xptr;
    uintptr_t next_xptr;
    struct Node* prev_node;
    struct Node* current_node;
    struct Node* next_node;
} LLX_STEP_CONTROLLER;

enum MODES {
    NORMAL,
    REVERSE,
    RIGHT,
    LEFT,
    MIDDLE
};

struct LINKED_LISTED_XOR* NEW_LIST_XOR(); // create lists

void LLX_LOOP_NEXT_STEP(struct LINKED_LISTED_XOR* list, void (*func)(struct Node* current_list), short mode);
void LLX_pop(struct LINKED_LISTED_XOR* list);
void LLX_push(struct LINKED_LISTED_XOR* list, int value); // insert value to list
void LLX_KILLS(struct LINKED_LISTED_XOR* list);
void LLX_display(struct LINKED_LISTED_XOR* list, short mode);
// UTILITES
uintptr_t X0R(uintptr_t prev_node, uintptr_t current_xptr);
void util_print_current_value(struct Node* current_list);
void util_kill_an_list(struct Node* current_list);
bool util_check_null_list(struct Node* list);

int main()
{
    struct LINKED_LISTED_XOR* mylist = NEW_LIST_XOR();

    LLX_pop(mylist);
    // LLX_push(mylist, 80);
    // LLX_push(mylist, 40);
    // LLX_push(mylist, 90);
    for (int i = 1; i <= 1000000; i++) {
        LLX_push(mylist, i + i);
    }

    LLX_display(mylist, REVERSE);
    printf("\n");
    // LLX_display(mylist, NORMAL);
    LLX_KILLS(mylist);
    return 0;
}

void LLX_pop(struct LINKED_LISTED_XOR* list)
{
    if (list != NULL && list->size >= 1) {
        if (util_check_null_list(list->Head)) {
            struct LLX_STEP_CONTROLLER controller;
            if (list->size <= 1) {
                free(list->Head);
                list->Head = NULL;
            } else if (list->size == 2) {
                // prev  node
                controller.prev_node = list->Head;
                // current node
                controller.current_xptr = X0R(0, controller.prev_node->xptr);
                controller.current_node = (struct Node*)controller.current_xptr;
                list->Head = controller.current_node;
                list->Head->xptr = 0;
                free(controller.prev_node);
            } else if (list->size >= 3) {
                // prev  node
                controller.prev_node = list->Head;
                // current node
                controller.current_xptr = X0R(0, controller.prev_node->xptr);
                controller.current_node = (struct Node*)controller.current_xptr;
                // next node
                controller.next_xptr = X0R((uintptr_t)controller.prev_node, controller.current_node->xptr);
                controller.next_node = (struct Node*)controller.next_xptr;

                list->Head = controller.current_node;
                list->Head->xptr = X0R(0, (uintptr_t)controller.next_node);
                free(controller.prev_node);
            }
            list->size--;
        }
    }
};

void LLX_push(struct LINKED_LISTED_XOR* list, int value)
{

    struct Node* new_node = malloc(sizeof(*new_node));
    new_node->value = value;
    if (!util_check_null_list(list->Head)) {
        // init list here !
        new_node->xptr = 0;
        list->Head = new_node;
        list->Tail = new_node;
        list->size = 0;
    } else {
        list->Head->xptr = X0R((uintptr_t)new_node, list->Head->xptr);
        new_node->xptr = (uintptr_t)list->Head;
        list->Head = new_node;
    }
    list->size++;
}

void LLX_KILLS(struct LINKED_LISTED_XOR* list)
{
    if (list != NULL) {
        if (util_check_null_list(list->Head) && list->size >= 1) {
            LLX_LOOP_NEXT_STEP(list, util_kill_an_list, NORMAL);
        }
        if (list != NULL) {
            free(list);
        }
    }
}

void util_kill_an_list(struct Node* current_list)
{
    if (util_check_null_list(current_list)) {
        free(current_list);
    } else {
        printf("\nNo List to Kills");
    }
}

void LLX_display(struct LINKED_LISTED_XOR* list, short mode)
{
    if (util_check_null_list(list->Head) && list->size >= 1) {
        printf("Lists size (%zu) : ", list->size);
        LLX_LOOP_NEXT_STEP(list, util_print_current_value, mode);
    } else {
        printf("List is Empty !");
        printf("hello oworld");
    }
}

void LLX_LOOP_NEXT_STEP(struct LINKED_LISTED_XOR* list, void (*func)(struct Node* current_list), short mode)
{
    if (util_check_null_list((mode == NORMAL ? list->Head : list->Tail))) {
        struct LLX_STEP_CONTROLLER controll;
        controll.prev_xptr = 0;
        controll.current_node = (mode == NORMAL) ? list->Head : list->Tail;
        while (controll.current_node) {
            controll.next_xptr = X0R(controll.prev_xptr, controll.current_node->xptr);
            controll.prev_xptr = (uintptr_t)controll.current_node;
            // paste external funtion here
            func(controll.current_node);
            controll.current_node = (struct Node*)controll.next_xptr;
        }
    }
}

struct LINKED_LISTED_XOR* NEW_LIST_XOR()
{
    struct LINKED_LISTED_XOR* l = malloc(sizeof(*l));
    l->Head = NULL;
    l->Tail = NULL;
    return l;
}

uintptr_t X0R(uintptr_t prev_node, uintptr_t current_xptr)
{
    // take prev node convert to uintptr type
    // @ret  address of next node ,:
    return prev_node ^ current_xptr;
}

void util_print_current_value(struct Node* current_list)
{
    if (util_check_null_list(current_list)) {
        printf("%d -> ", current_list->value);
    }
}

bool util_check_null_list(struct Node* list)
{
    return list != NULL ? true : false;
}
// void LLX_display(struct Node* header)
// {
//     if (header == nullptr) {
//         return;
//     }
//     struct LLXOR_MOVE_POSITION* list;
//     list->current = header;
//     list->prev = 0;
//     while (list->current) {
//         printf("%d -> ", list->current->value);
//         list->next = X0R(list->prev, list->current->xptr);
//         list->prev = (uintptr_t)list->current;
//         list->current = (struct Node*)list->next;
//     }
// }
