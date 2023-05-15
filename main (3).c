#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *front;
    struct node *rear;
};

void initQueue(struct queue *q) {
    q->front = q->rear = NULL;
}

int isQueueEmpty(struct queue *q) {
    return (q->front == NULL);
}

void enqueue(struct queue *q, int value) {
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    if (q->rear)
        q->rear->next = newNode;
    q->rear = newNode;
    if (q->front == NULL)
        q->front = q->rear;
}

int dequeue(struct queue *q) {
    int data = 0;
    struct node *temp;
    if (isQueueEmpty(q)) {
        printf("Kuyruk Bos.\n");
        return 0;
    }
    else {
        temp = q->front;
        data = temp->data;
        q->front = q->front->next;
        free(temp);
    }
    return data;
}

void printQueue(struct queue *q) {
    struct node *temp;
    if (isQueueEmpty(q)) {
        printf("Kuyruk Bos.\n");
        return;
    }
    temp = q->front;
    printf("Kuyruk Elemanlari: \n");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int secim, eklenecek;
    struct queue q;
    initQueue(&q);
    do {
        printf("\n\n--Kuyruk Islemleri--\n");
        printf("1-Ekle\n2-Cikar\n3-Goruntule\n4-Cikis\nSecim: ");
        scanf("%d", &secim);
        switch (secim) {
        case 1:
            printf("Eklenecek Elemani Giriniz: ");
            scanf("%d", &eklenecek);
            enqueue(&q, eklenecek);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            printQueue(&q);
            break;
        case 4:
            printf("Program Sonlandiriliyor.\n");
            break;
        default:
            printf("Gecersiz Secim.\n");
        }
    } while (secim != 4);
    return 0;
}
