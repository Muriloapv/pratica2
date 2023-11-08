#ifndef TASK_H
#define TASK_H

typedef struct Task {
    char name[100];
    int priority;
    char status[20];
    struct Task* next;
    struct Task* prev;
} Task;

void insertTask(Task** head, char name[], int priority, char status[]);
void removeTask(Task** head, char name[]);
Task* highestPriorityUncompletedTask(Task* head);
void printTasks(Task* head);

#endif
