#ifndef UTILS_H
#define UTILS_H

#include <time.h>
#include "student.h"
#include "discipline.h"
#include "grade.h"

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
#define BUFFER_SIZE 1024

// Funções de manipulação de memória
void* safe_malloc(size_t size);
void* safe_realloc(void* ptr, size_t size);
void safe_free(void* ptr);
void** create_2d_array(int rows, int cols, size_t element_size);
void free_2d_array(void** array, int rows);

// Funções de manipulação de strings
char* str_duplicate(const char* str);
void str_trim(char* str);
void str_to_upper(char* str);
void str_to_lower(char* str);
int str_starts_with(const char* str, const char* prefix);

// Funções de data e hora
char* get_current_date_string(void);
char* format_date(time_t timestamp);
time_t parse_date(const char* date_string);
int calculate_days_between(const char* date1, const char* date2);
int is_valid_date(const char* date);

// Funções de interface do usuário
void clear_screen(void);
void print_header(const char* title);
void print_menu(const char** options, int num_options);
void print_error(const char* message);
void print_success(const char* message);
void print_warning(const char* message);
void pause_screen(void);
void progress_bar(int current, int total);

// Funções de entrada de dados
void get_string(char* buffer, int max_length, const char* prompt);
int get_integer(const char* prompt, int min, int max);
float get_float(const char* prompt, float min, float max);
void get_password(char* buffer, int max_length);
int confirm_action(const char* message);

// Funções de validação
int is_valid_email(const char* email);
int is_valid_phone(const char* phone);
int is_valid_cpf(const char* cpf);
int is_valid_date_format(const char* date);
int is_number(const char* str);

// Funções de log
void log_error(const char* message);
void log_info(const char* message);
void log_warning(const char* message);
void log_debug(const char* message);
void init_log_system(const char* log_file);

// Funções de arquivo
int file_exists(const char* filename);
long get_file_size(const char* filename);
char* read_file_content(const char* filename);
int write_file_content(const char* filename, const char* content);
int copy_file(const char* source, const char* destination);

// Funções de ordenação
void quick_sort(void* array, int size, size_t elem_size, int (*compare)(const void*, const void*));
void merge_sort(void* array, int size, size_t elem_size, int (*compare)(const void*, const void*));
void bubble_sort(void* array, int size, size_t elem_size, int (*compare)(const void*, const void*));
int binary_search(const void* array, int size, size_t elem_size, const void* key, int (*compare)(const void*, const void*));

// Funções de criptografia
char* encrypt_string(const char* str, const char* key);
char* decrypt_string(const char* encrypted, const char* key);
char* hash_password(const char* password);
int verify_password(const char* password, const char* hash);

// Funções de backup
int create_backup(const char* source_dir, const char* backup_dir);
int restore_backup(const char* backup_dir, const char* destination_dir);
void clean_old_backups(const char* backup_dir, int days_to_keep);
int verify_backup_integrity(const char* backup_dir);

// Funções de configuração
void load_config(const char* config_file);
void save_config(const char* config_file);
char* get_config_value(const char* key);
void set_config_value(const char* key, const char* value);

// Funções de relatório
void start_html_report(const char* filename, const char* title);
void add_report_section(const char* section_title, const char* content);
void add_report_table(const char* headers[], const char* data[], int rows, int cols);
void end_html_report(void);

// Funções de estatísticas
double calculate_mean(const double* array, int size);
double calculate_median(const double* array, int size);
double calculate_standard_deviation(const double* array, int size);
void generate_histogram(const double* data, int size, int num_bins);

#endif // UTILS_H 