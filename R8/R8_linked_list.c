/*
Implementing a signle linked list using dynamic memory allocation.
f(x) = ax^n + bx^(n-1) ....... + C
g(x) = a1x^n + b1x^(n-1) ....... + C1
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

struct Node* createNode(int c, int p);

struct Node* createNode(int c, int p) {
    //struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Non contiguous blocks of memory ; non initialized 

    struct Node* newNode = (struct Node*)calloc(1, sizeof(struct Node)); // Continuous blocks of memory in heap, initialized with 0.
    newNode->coeff = c;
    newNode->pow = p;
    newNode->next = NULL;
    return newNode;
}

struct Node* addpolynomials(struct Node* p1, struct Node* p2){
     struct Node* dummy = createNode(0, 0);

     struct Node* prev = dummy;
        struct Node *curr1 = p1, *curr2 = p2;

    while (curr1 != NULL && curr2 != NULL) {

        // if the powers of the current pointer in p1 and p2 are unequal
         if (curr1->pow < curr2->pow) {
            prev->next = curr2;
            prev = curr2;
            curr2 = curr2->next;
         }

         else if (curr1->pow > curr2->pow) {
            prev->next = curr1;
            prev = curr1;
            curr1 = curr1->next;
        }
        else {
            curr1->coeff = curr1->coeff + curr2->coeff;
            prev->next = curr1;
            prev = curr1;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
    }

    if (curr1 != NULL) {
        prev->next = curr1;
    }
    
    if (curr2 != NULL) {
        prev->next = curr2;
    }

    return dummy->next;
}

void printList(struct Node* head) {
    struct Node* curr = head;

    while (curr != NULL) {
        printf("%dx^%d +", curr->coeff, curr->pow);
        curr = curr->next;

    }

    printf("\n");
}

int main(){
    //Two polynomials as input f(x) = 10x^3 + 5x^2 + 2x + 7
    // g(x) = 11x^3 + 7x^2 + 3

    struct Node* poly1 = createNode(10,3);
    poly1->next = createNode(5,2);
    poly1->next->next = createNode(2,1);
    struct Node* last = createNode(7,0);
    poly1->next->next->next = last;
    printf("f(x) = 10x^3 + 5x^2 + 2x + 7\n");
    printf("g(x) = 11x^3 + 7x^2 + 3\n");
    struct Node* poly2 = createNode(11,3);
    poly2->next = createNode(7,2);
    poly2->next->next = createNode(3,0);

    struct Node* head = (struct Node*)addpolynomials(poly1, poly2);

    printList(head);

    return 0;
}