#include <stdio.h>
#include <stdlib.h>

#define MAX_QUERIES 10 // maximum number of queries that can be in a queue
#define QUERY_TIME 10 // time (in minutes) Sudesh Sharma will spend on each query

typedef enum { STUDENT, FACULTY } query_type; // enum to distinguish between student and faculty queries

typedef struct {
    int time; // time the query was received
    query_type type; // type of query (student or faculty)
} query;

int main() {
    int time_remaining = 120; // Sudesh Sharma has 120 minutes (2 hours) to handle queries
    int total_queries = 0; // total number of queries handled
    int total_time = 0; // total time (in minutes) spent handling queries
    query student_queue[MAX_QUERIES]; // queue for student queries
    query faculty_queue[MAX_QUERIES]; // queue for faculty queries
    int student_front = 0; // front of student queue
    int student_rear = -1; // rear of student queue
    int faculty_front = 0; // front of faculty queue
    int faculty_rear = -1; // rear of faculty queue

    // loop for 2 hours (from 10am to 12pm)
    for (int i = 0; i < 120; i++) {
        // check if there are any pending student queries and Sudesh Sharma has time
        if (student_front <= student_rear && time_remaining >= QUERY_TIME && student_queue[student_front].time <= i) {
            // handle next student query in queue
            query q = student_queue[student_front++];
            total_queries++;
            total_time += QUERY_TIME;
            time_remaining -= QUERY_TIME;
            printf("Handling student query %d at time %d\n", total_queries, i);
        }

        // check if there are any pending faculty queries and Sudesh Sharma has time
        else if (faculty_front <= faculty_rear && time_remaining >= QUERY_TIME && faculty_queue[faculty_front].time <= i) {
            // handle next faculty query in queue
            query q = faculty_queue[faculty_front++];
            total_queries++;
            total_time += QUERY_TIME;
            time_remaining -= QUERY_TIME;
            printf("Handling faculty query %d at time %d\n", total_queries, i);
        }
    }

    // print summary
    printf("Handled a total of %d queries\n", total_queries);
    printf("Total time spent handling queries: %d minutes\n", total_time);
    printf("Average query time: %.2f minutes\n", (float) total_time / total_queries);

    return 0;
}

