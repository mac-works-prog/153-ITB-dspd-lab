//Pavan bokare-IT-B-53
/*AIM:  This C program creates a linked list to store integer elements. 
        It prompts the user to enter elements and add them to the list until the user enters 0.
        It then traverses the list and prints each element and "=>" until reaching the null pointer. 
        Finally, it displays the number of nodes in the list.
        */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *temp, *newNode;
    int value, count = 0;

    printf("Enter elements (Enter 0 to stop):\n");

    while (1) {
        if (scanf("%d", &value) != 1) {
            printf("Invalid input! Exiting...\n");
            break;
        }
        if (value == 0)
            break;

        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
        count++;
    }

    printf("\nLinked List: ");
    temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" => ");
        temp = temp->next;
    }
    printf(" => NULL\n");

    printf("Total Number of Nodes = %d\n", count);

    temp = head;
    while (temp != NULL) {
        struct Node *next = temp->next;
        free(temp);
        temp = next;
    }

    return 0;
}
