#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct node *element(struct node *dll, int i) ;
struct node *add(struct node *dll, int i, int value) ;
struct node *delete(struct node *dll, int i);

struct node {
    int value;
    struct node *next;
    struct node *prev;
};

struct node *element(struct node *dll, int i) {
    int j = 0;
    struct node *ptr1 = dll;

    while (j < i) {
        if (ptr1 == NULL) {
            return NULL;
        }
        ptr1 = ptr1->next;
        j++;
    }
    return ptr1;
}

struct node *add(struct node *dll, int i, int value) {
    struct node *newnode = (struct node *)calloc(1, sizeof(struct node));
    int length = 0;
    struct node *countptr = dll;

    while (countptr->next != NULL) {
        countptr = countptr->next;
        length++;
    }

    if (i == 0) {
        newnode->value = value;
        newnode->next = dll;
        newnode->prev = NULL;
        dll->prev = newnode;
        dll = newnode;
        return dll;
    } else if (i < 0 || i > length - 1) {
        struct node *prevnode = element(dll, length);
        newnode->value = value;
        newnode->next = NULL;
        newnode->prev = prevnode;
        prevnode->next = newnode;
        return dll;
    } else {
        struct node *prevnode = element(dll, i - 1);
        struct node *nextnode = element(dll, i);
        newnode->value = value;
        newnode->next = nextnode;
        newnode->prev = prevnode;
        if (nextnode != NULL) {
            nextnode->prev = newnode;
        }
        if (prevnode != NULL) {
            prevnode->next = newnode;
        }
        return dll;
    }
    free(newnode);
    return dll;
}

struct node *delete(struct node *dll, int i) {
    struct node *deletenode = element(dll, i);
    int length = 0;
    struct node *countptr = dll;

    while (countptr->next != NULL) {
        countptr = countptr->next;
        length++;
    }

    if (deletenode == NULL) {
        return dll;
    }

    if (deletenode == dll) {
        dll = deletenode->next;
    }

    if (deletenode->prev != NULL) {
        deletenode->prev->next = deletenode->next;
    }

    if (deletenode->next != NULL) {
        deletenode->next->prev = deletenode->prev;
    }
    return dll;
}

void printNode (struct node *dll) {
    if (dll != NULL) {
        printf("< This: %p - %d - P : %p - N : %p >\n", dll, dll->value, dll->prev, dll->next);
    } else {
        printf("Null Pointer");
    }
}


void printLL (struct node *dll) {
    struct node* ptr = dll;
    printf("---\n");
    while (ptr != NULL) {
        printNode(ptr);
        ptr = ptr->next;
    }
    printf("---\n\n");
}

int main () {
    // Testing code! 
    struct node *dll = malloc(sizeof(struct node));
    dll->value = 1;
    printLL(dll);
    dll = add(dll, -1, 3);
    printLL(dll);
    dll = add(dll, -1, 4);
    printLL(dll);
    dll = add(dll, 1, 2);
    printLL(dll);
    dll = add(dll, 2, 7);
    printLL(dll);
    dll = add(dll, 9, -1);
    printLL(dll);
    dll = delete(dll, 2);
    printLL(dll);
    dll = delete(dll, 0);
    printLL(dll);
    dll = delete(dll, 4);
    printLL(dll);
    dll = delete(dll, 0);
    dll = delete(dll, 0);
    dll = delete(dll, 0);
    dll = delete(dll, 0);
    printLL(dll);
}

/* Expected Output: 

---
< This: 0x1cf8590 - 1 - P : (nil) - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf8590 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf8590 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85f0 >
< This: 0x1cf85f0 - 2 - P : 0x1cf8590 - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf85f0 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85f0 >
< This: 0x1cf85f0 - 2 - P : 0x1cf8590 - N : 0x1cf8610 >
< This: 0x1cf8610 - 7 - P : 0x1cf85f0 - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf8610 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85f0 >
< This: 0x1cf85f0 - 2 - P : 0x1cf8590 - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf85f0 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

*/ 