#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Task {
    char task_name[100];
    char task_description[100];
};

struct Task todo_list[100];
int todo_list_size = 0;

void add_task(const char *task_name, const char *task_description) {
    strcpy(todo_list[todo_list_size].task_name, task_name);
    strcpy(todo_list[todo_list_size].task_description, task_description);
    ++todo_list_size;
    printf("Task added: %s, %s\n", task_name, task_description);
}

void view_tasks() {
    if (todo_list_size == 0) {
        printf("No tasks to display.\n");
    } else {
        for (int i = 0; i < todo_list_size; ++i) {
            printf("%s, %s\n", todo_list[i].task_name, todo_list[i].task_description);
        }
    }
}

void complete_task(const char *task_name) {
    for (int i = 0; i < todo_list_size; ++i) {
        if (strcmp(todo_list[i].task_name, task_name) == 0) {
            printf("Task completed: %s, %s\n", todo_list[i].task_name, todo_list[i].task_description);
            --todo_list_size;
            for (int j = i; j < todo_list_size; ++j) {
                todo_list[j] = todo_list[j + 1];
            }
            return;
        }
    }
    printf("Task not found.\n");
}

int main() {
    while (1) {
        printf("--- To-Do List ---\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Complete Task\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            char task_name[100], task_description[100];
            printf("Enter task name: ");
            scanf("%s", task_name);
            printf("Enter task description: ");
            scanf("%s", task_description);
            add_task(task_name, task_description);
        } else if (choice == 2) {
            view_tasks();
        } else if (choice == 3) {
            char task_name[100];
            printf("Enter task name: ");
            scanf("%s", task_name);
            complete_task(task_name);
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }
