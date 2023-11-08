#include "task.h"
#include <stdio.h>

int main() {
    Task* taskList = NULL;

    insertTask(&taskList, "Tarefa 1", 3, "pendente");
    insertTask(&taskList, "Tarefa 2", 5, "em progresso");
    insertTask(&taskList, "Tarefa 3", 4, "pendente");
    insertTask(&taskList, "Tarefa 4", 5, "pendente");

    printf("Todas as tarefas na lista:\n");
    printTasks(taskList);

    printf("\nRemovendo Tarefa 2:\n");
    removeTask(&taskList, "Tarefa 2");
    printTasks(taskList);

    Task* highestPriority = highestPriorityUncompletedTask(taskList);
    if (highestPriority) {
        printf("\nTarefa de maior prioridade não concluída:\n");
        printf("Nome: %s, Prioridade: %d, Statuskjl: %s\n", highestPriority->name, highestPriority->priority, highestPriority->status);
    } else {
        printf("\nNenhuma tarefa não concluída encontrada.\n");
    }

    return 0;
}
