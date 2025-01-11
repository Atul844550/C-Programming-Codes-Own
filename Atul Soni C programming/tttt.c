#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_REQUESTS 100 // Maximum number of requests
#define REQUEST_TIME 10  // Fixed time to handle each request in minutes

typedef struct {
    int time_received; // Time when the request was received
    int handle_time;   // Estimated time required to handle the request
} Request;

int main() {
    Request student_queue[MAX_REQUESTS];
    Request faculty_queue[MAX_REQUESTS];
    int student_front = 0, faculty_front = 0;
    int student_rear = 0, faculty_rear = 0;
    time_t start_time, end_time;
    int total_time = 0;
    int num_requests = 0;

    // Log in from 10am to 12am
    struct tm login_time = {0};
    login_time.tm_hour = 10;
    login_time.tm_min = 0;
    login_time.tm_sec = 0;
    start_time = mktime(&login_time);
    login_time.tm_hour = 12;
    end_time = mktime(&login_time);

    // Simulate request handling
    srand(time(NULL)); // Initialize random number generator
    while (difftime(end_time, time(NULL)) > 0) {
        // Check for new requests
        if (rand() % 2 == 0) {
            // Add a new student request
            if (student_rear < MAX_REQUESTS) {
                student_queue[student_rear].time_received = time(NULL);
                student_queue[student_rear].handle_time = REQUEST_TIME;
                student_rear++;
                printf("New student request received\n");
            } else {
                printf("Student request queue is full\n");
            }
        } else {
            // Add a new faculty request
            if (faculty_rear < MAX_REQUESTS) {
                faculty_queue[faculty_rear].time_received = time(NULL);
                faculty_queue[faculty_rear].handle_time = REQUEST_TIME;
                faculty_rear++;
                printf("New faculty request received\n");
            } else {
                printf("Faculty request queue is full\n");
            }
        }

        // Handle student requests
        if (student_front < student_rear) {
            if (difftime(time(NULL), student_queue[student_front].time_received) >= REQUEST_TIME) {
                printf("Handling student request\n");
                total_time += REQUEST_TIME;
                num_requests++;
                student_front++;
            }
        }

        // Handle faculty requests
        if (faculty_front < faculty_rear) {
            if (difftime(time(NULL), faculty_queue[faculty_front].time_received) >= REQUEST_TIME) {
                printf("Handling faculty request\n");
                total_time += REQUEST_TIME;
                num_requests++;
                faculty_front++;
            }
        }
    }

    // Calculate and print summary
    printf("Session ended\n");
    printf("Total time spent on handling queries: %d minutes\n", total_time);
    printf("Average query time: %.2f minutes\n", (float)total_time / num_requests);

    return 0;
}