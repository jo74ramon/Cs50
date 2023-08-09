#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This program generates 100 random numbers from 0 to 500.
Creates a queue to store them as they are created and prioritizes
the 1 to 2 digit ones*/

// Structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Structure for the queue
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function to create an empty queue
Queue* createQueue()
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return (queue->front == NULL);
}
int isFull(Queue* queue)
{
    for (int counter = 0; counter < 100; counter++)
    {
        Node* temp = queue->front;

        if (temp->next == NULL && counter == 99)
        {
            return 0;
        }
        else if (temp->next == NULL)
        {
            return 1;
        }
        temp->next = queue->front->next;
    }
    return 0;
}

// Function to enqueue an element depending on its digit size
void enqueue(Queue* queue, int data)
{
    // Create a new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    // If the queue is empty, there will be only the new node, thus, taking both front and rear
    if (isEmpty(queue))
    {
        queue->front = newNode;
        queue->rear = newNode;
    }
    
     // Otherwise, add the new node based on the priority
    else if (data >= 0 && data <= 99)


    // Add to front if it's 2 digit or less.
    {



        newNode->next = queue->front;
        queue->front = newNode;
        printf("Prioritized: %d\n", data);

    }
    else // Three-digit insert at the rear
    {

        queue->rear->next = newNode;
        queue->rear = newNode;
        printf("Enqueued: %d\n", data);
    }

    //printf("Enqueued: %d\n", data); //prints the numbers as they are joining the queue
}




// Function to print the elements of the queue
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    Node* current = queue->front;
    printf("Queue: ");
    printf("\n");
    int counter = 0;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
        counter++; // break line counter
        if (counter % 10 == 0)
        { // break line after 10 values are printed
            printf("\n");
        }

    }
    printf("\n");
}

// Function to free the memory allocated for the queue
void destroyQueue(Queue* queue) {
    while (!isEmpty(queue)) {
        Node* temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
    free(queue);
}

int main() {
    struct Queue* queue = createQueue();

    srand(time(NULL)); // Seed the random number generator

    for (int i = 0; i < 100; i++) {
        int randomNumber = rand() % 500 + 1;
        enqueue(queue, randomNumber);
    }

    displayQueue(queue);

    destroyQueue(queue);

    return 0;
}
