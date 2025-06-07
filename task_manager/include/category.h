#ifndef CATEGORY_H
#define CATEGORY_H

#include <time.h>

// Definição das constantes
#define MAX_CATEGORY_NAME_LENGTH 50
#define MAX_CATEGORY_DESCRIPTION_LENGTH 200

// Estrutura da categoria
typedef struct {
    int id;
    char name[MAX_CATEGORY_NAME_LENGTH];
    char description[MAX_CATEGORY_DESCRIPTION_LENGTH];
    time_t created_at;
    time_t updated_at;
} Category;

// Funções de gerenciamento de categorias
Category* create_category(const char* name, const char* description);
int update_category(Category* category, const char* name, const char* description);
int delete_category(int category_id);

// Funções de busca e listagem
Category* get_category_by_id(int category_id);
Category* get_category_by_name(const char* name);
Category** get_all_categories(int* count);

// Funções de validação
int is_valid_category(const Category* category);
int is_category_in_use(int category_id);
int category_exists(const char* name);

// Funções de utilidade
void print_category(const Category* category);
void print_category_list(Category** categories, int count);
int get_task_count_by_category(int category_id);

// Funções de estatísticas
void print_category_statistics(int category_id);
void print_all_categories_statistics(void);

#endif // CATEGORY_H 