
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

struct node *front = NULL;
struct node *rear = NULL;

void push(int item) {
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = item;
    newnode->next = top;
    top = newnode;

    printf("Element pushed successfully.\n");
}

void pop() {
    struct node *temp;

    if (top == NULL) {
        printf("Stack Underflow!\n");
        return;
    }

    temp = top;
    printf("Deleted element: %d\n", temp->data);

    top = top->next;
    free(temp);
}

void stackPeek() {
    if (top == NULL) {
        printf("Stack is Empty!\n");
    } else {
        printf("Top element: %d\n", top->data);
    }
}

void displayStack() {
    struct node *temp = top;

    if (top == NULL) {
        printf("Stack is Empty!\n");
        return;
    }

    printf("Stack: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void enqueue(int item) {
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = item;
    newnode->next = NULL;

    if (front == NULL) {
        front = newnode;
        rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }

    printf("Element inserted successfully.\n");
}

void dequeue() {
    struct node *temp;

    if (front == NULL) {
        printf("Queue Underflow!\n");
        return;
    }

    temp = front;

    printf("Deleted element: %d\n", temp->data);

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

void queuePeek() {
    if (front == NULL) {
        printf("Queue is Empty!\n");
    } else {
        printf("Front element: %d\n", front->data);
    }
}

void displayQueue() {
    struct node *temp = front;

    if (front == NULL) {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Queue: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    int choice, ch, item;

    while (1) {
        printf("\n--- MAIN MENU ---\n");
        printf("1. Stack Operations\n");
        printf("2. Queue Operations\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("\n--- STACK MENU ---\n");
                printf("1. PUSH\n");
                printf("2. POP\n");
                printf("3. PEEK\n");
                printf("4. DISPLAY\n");

                printf("Enter your choice: ");
                scanf("%d", &ch);

                switch (ch) {
                    case 1:
                        printf("Enter element: ");
                        scanf("%d", &item);
                        push(item);
                        break;

                    case 2:
                        pop();
                        break;

                    case 3:
                        stackPeek();
                        break;

                    case 4:
                        displayStack();
                        break;

                    default:
                        printf("Invalid choice!\n");
                }
                break;

            case 2:
                printf("\n--- QUEUE MENU ---\n");
                printf("1. ENQUEUE\n");
                printf("2. DEQUEUE\n");
                printf("3. PEEK\n");
                printf("4. DISPLAY\n");

                printf("Enter your choice: ");
                scanf("%d", &ch);

                switch (ch) {
                    case 1:
                        printf("Enter element: ");
                        scanf("%d", &item);
                        enqueue(item);
                        break;

                    case 2:
                        dequeue();
                        break;

                    case 3:
                        queuePeek();
                        break;

                    case 4:
                        displayQueue();
                        break;

                    default:
                        printf("Invalid choice!\n");
                }
                break;

            case 3:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

