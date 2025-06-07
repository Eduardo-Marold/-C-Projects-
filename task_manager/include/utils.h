#ifndef UTILS_H
#define UTILS_H

#include <time.h>
#include "task.h"
#include "category.h"

// Definições de cores para o terminal
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

// Definições de retorno
#define SUCCESS 0
#define ERROR -1

// Funções de manipulação de data e hora
char* get_current_date_string(void);
char* format_date(time_t timestamp);
time_t parse_date(const char* date_string);
int calculate_days_between(const char* date1, const char* date2);
int is_date_valid(const char* date);

// Funções de interface do usuário
void clear_screen(void);
void print_header(const char* title);
void print_menu(void);
void print_error(const char* message);
void print_success(const char* message);
void print_warning(const char* message);
void pause_screen(void);

// Funções de entrada de dados
void get_string(char* buffer, int max_length, const char* prompt);
int get_integer(const char* prompt);
int get_option(int min, int max, const char* prompt);
void get_date(char* buffer, const char* prompt);

// Funções de validação
int is_valid_string(const char* str);
int is_valid_integer(const char* str);
int is_valid_date_format(const char* date);

// Funções de memória
void* safe_malloc(size_t size);
void* safe_realloc(void* ptr, size_t size);
void safe_free(void* ptr);

// Funções de log
void log_error(const char* message);
void log_info(const char* message);
void log_warning(const char* message);
void log_debug(const char* message);

// Funções de ordenação
int compare_strings(const void* a, const void* b);
int compare_dates(const void* a, const void* b);
int compare_priorities(const void* a, const void* b);

// Funções de conversão
char* priority_to_string(Priority priority);
Priority string_to_priority(const char* str);
char* boolean_to_string(int value);

// Funções de estatísticas
void calculate_task_statistics(Task** tasks, int count);
void calculate_category_statistics(Category** categories, int count);
void print_statistics_report(void);

#endif // UTILS_H 