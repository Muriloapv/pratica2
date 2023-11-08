#include "task.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Implementação das funções definidas no arquivo de cabeçalho "task.h"

void insertTask(Task** head, char name[], int priority, char status[]) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strncpy(newTask->name, name, sizeof(newTask->name));
    newTask->priority = priority;
    strncpy(newTask->status, status, sizeof(newTask->status));
    newTask->next = NULL;

    if (*head == NULL) {
        // Lista vazia, insere no início
        newTask->prev = NULL;
        *head = newTask;
        return;
    }

    Task* current = *head;
    while (current) {
        if (priority > current->priority || (priority == current->priority && strcmp(status, "concluída") == 0)) {
            // Inserir antes do nó atual
            newTask->prev = current->prev;
            newTask->next = current;
            if (current->prev) {
                current->prev->next = newTask;
            } else {
                *head = newTask;
            }
            current->prev = newTask;
            return;
        } else if (current->next == NULL) {
            // Inserir no final da lista
            current->next = newTask;
            newTask->prev = current;
            return;
        }
        current = current->next;
    }
}

void removeTask(Task** head, char name[]) {
    Task* current = *head;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                *head = current->next;
            }
            if (current->next) {
                current->next->prev = current->prev;
            }
            free(current);
            return;
        }
        current = current->next;
    }
}

Task* highestPriorityUncompletedTask(Task* head) {
    Task* current = head;
    Task* highestPriorityTask = NULL;

    while (current) {
        if (strcmp(current->status, "concluída") != 0 &&
            (highestPriorityTask == NULL || current->priority > highestPriorityTask->priority)) {
            highestPriorityTask = current;
        }
        current = current->next;
    }

    return highestPriorityTask;
}

void printTasks(Task* head) {
    Task* current = head;
    while (current) {
        printf("Nome: %s, Prioridade: %d, Status: %s\n", current->name, current->priority, current->status);
        current = current->next;
    }
}
