#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include "task.h"
#include "category.h"

// Definição das constantes
#define TASKS_FILE "data/tasks.dat"
#define CATEGORIES_FILE "data/categories.dat"
#define BACKUP_DIR "data/backup/"
#define MAX_PATH_LENGTH 256

// Funções de manipulação de arquivos de tarefas
int save_task(const Task* task);
int save_all_tasks(Task** tasks, int count);
Task* load_task_by_id(int task_id);
Task** load_all_tasks(int* count);
int delete_task_file(int task_id);

// Funções de manipulação de arquivos de categorias
int save_category(const Category* category);
int save_all_categories(Category** categories, int count);
Category* load_category_by_id(int category_id);
Category** load_all_categories(int* count);
int delete_category_file(int category_id);

// Funções de backup
int create_backup(void);
int restore_from_backup(const char* backup_date);
int list_backups(char*** backup_list, int* count);
int delete_backup(const char* backup_date);

// Funções de gerenciamento de arquivos
int initialize_data_directory(void);
int check_file_exists(const char* filename);
int get_next_task_id(void);
int get_next_category_id(void);

// Funções de validação e verificação
int verify_data_integrity(void);
int repair_data_files(void);
void print_file_statistics(void);

// Funções de exportação e importação
int export_tasks_to_csv(const char* filename);
int import_tasks_from_csv(const char* filename);
int export_categories_to_csv(const char* filename);
int import_categories_from_csv(const char* filename);

#endif // FILE_HANDLER_H 