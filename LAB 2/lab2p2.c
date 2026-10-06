#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

void enQueue(int element) {
    if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) {
        printf("\nQueue is full!!\n");
        return;
    }

    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    items[rear] = element;
    printf("\nInserted -> %d\n", element);
}

void deQueue() {
    if (front == -1) {
        printf("\nQueue is empty !!\n");
        return;
    }

    printf("\nDeleted element -> %d\n", items[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void display() {
    if (front == -1) {
        printf("\nEmpty Queue\n");
        return;
    }

    printf("\nFront -> %d\nItems -> ", front);
    int i = front;
    while (1) {
        printf("%d ", items[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\nRear -> %d\n", rear);
}

int main() {
    int choice, val;
    printf("\n1.Insert  2.Delete  3.Display  4.Exit\nEnter choice: ");
    while (1) {
        if (scanf("%d", &choice) != 1) return 0;
        switch (choice) {
            case 1:
                printf("Enter value: ");
                if (scanf("%d", &val) == 1) enQueue(val);
                break;
            case 2: deQueue(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("\nInvalid Choice!\n");
        }
    }
    return 0;
}
