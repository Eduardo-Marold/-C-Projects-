#ifndef TASK_H
#define TASK_H

#include <time.h>

// Definição das constantes
#define MAX_TITLE_LENGTH 100
#define MAX_DESCRIPTION_LENGTH 500
#define MAX_DATE_LENGTH 11

// Enumeração para prioridades
typedef enum {
    PRIORITY_HIGH = 1,
    PRIORITY_MEDIUM = 2,
    PRIORITY_LOW = 3
} Priority;

// Estrutura da tarefa
typedef struct {
    int id;
    char title[MAX_TITLE_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int category_id;
    Priority priority;
    char due_date[MAX_DATE_LENGTH];
    int completed;
    time_t created_at;
    time_t updated_at;
} Task;

// Funções de gerenciamento de tarefas
Task* create_task(const char* title, const char* description, int category_id, Priority priority, const char* due_date);
int update_task(Task* task, const char* title, const char* description, int category_id, Priority priority, const char* due_date);
int delete_task(int task_id);
int complete_task(int task_id);
int uncomplete_task(int task_id);

// Funções de busca e listagem
Task* get_task_by_id(int task_id);
Task** get_all_tasks(int* count);
Task** get_tasks_by_category(int category_id, int* count);
Task** get_tasks_by_priority(Priority priority, int* count);
Task** get_overdue_tasks(int* count);
Task** get_tasks_due_soon(int days_threshold, int* count);

// Funções de ordenação
void sort_tasks_by_priority(Task** tasks, int count);
void sort_tasks_by_due_date(Task** tasks, int count);

// Funções de validação
int is_valid_task(const Task* task);
int is_valid_date_format(const char* date);
int is_task_overdue(const Task* task);
int is_task_due_soon(const Task* task, int days_threshold);

// Funções de utilidade
void print_task(const Task* task);
void print_task_list(Task** tasks, int count);
char* get_priority_string(Priority priority);

#endif // TASK_H 