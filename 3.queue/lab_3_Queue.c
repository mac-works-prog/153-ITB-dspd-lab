//Pavan bokare-IT-B-153
/* AIM: Design, Develop and Implement a menu driven Program in C for the following operations on QUEUE of Characters (Array Implementation of Queue with maximum size MAX)
a. Insert an Element on to QUEUE
b. Delete an Element from QUEUE
c. Demonstrate Overflow and Underflow situations on QUEUE
d. Display the status of QUEUE
e. Exit
*/
#include <stdio.h>
#define MAX 50

char queue[MAX];
int front = -1, rear = -1;

void insert(char ch) {
    if(rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert '%c'\n", ch);
        return;
    }
    if(front == -1)
        front = 0;
    queue[++rear] = ch;
    printf("'%c' inserted into queue.\n", ch);
}

void delete() {
    if(front == -1 || front > rear) {
        printf("Queue Underflow! No elements to delete.\n");
        return;
    }
    printf("'%c' deleted from queue.\n", queue[front]);
    front++;
}

void display() {
    if(front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Current Queue: ");
    for(int i = front; i <= rear; i++)
        printf("%c ", queue[i]);
    printf("\n");
}

int main() {
    int choice;
    char ch;

    while(1) {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter character to insert: ");
                scanf(" %c", &ch);
                insert(ch);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}