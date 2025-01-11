#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10
#define MAX_QUERY_TIME 20 // in minutes

typedef enum { STUDENT, FACULTY } QueueType;

typedef struct {
    QueueType type;
    int arrival_time; // in minutes since 10am
} Query;

typedef struct {
    Query buffer[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

void init_queue(Queue* q) {
    q->front = q->rear = 0;
}

int is_empty(Queue* q) {
    return q->front == q->rear;
}

int is_full(Queue* q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void enqueue(Queue* q, Query query) {
    if (is_full(q)) {
        fprintf(stderr, "Error: queue is full\n");
        exit(EXIT_FAILURE);
    }
    q->buffer[q->rear] = query;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
}

Query dequeue(Queue* q) {
    if (is_empty(q)) {
        fprintf(stderr, "Error: queue is empty\n");
        exit(EXIT_FAILURE);
    }
    Query query = q->buffer[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return query;
}

int main() {
    Queue student_queue, faculty_queue;
    init_queue(&student_queue);
    init_queue(&faculty_queue);

    int total_query_time = 0;
    int num_queries_handled = 0;

    // loop for 2 hours (120 minutes) starting at 10am
    for (int current_time = 0; current_time < 120; current_time++) {
        // handle student queries
        if (!is_empty(&student_queue) && total_query_time + MAX_QUERY_TIME <= 120) {
            Query query = dequeue(&student_queue);
            total_query_time += MAX_QUERY_TIME;
            num_queries_handled++;
            printf("Handled student query at %d minutes\n", current_time);
        }

        // handle faculty queries
        if (!is_empty(&faculty_queue) && total_query_time + MAX_QUERY_TIME <= 120) {
            Query query = dequeue(&faculty_queue);
            total_query_time += MAX_QUERY_TIME;
            num_queries_handled++;
            printf("Handled faculty query at %d minutes\n", current_time);
        }
    }

    printf("Total time spent handling queries: %d minutes\n", total_query_time);
    printf("Average query time: %.2f minutes\n", (float)total_query_time / num_queries_handled);

    return 0;
}
