#ifndef STUDENT_H
#define STUDENT_H

#include <time.h>

// Definição das constantes
#define MAX_NAME_LENGTH 100
#define MAX_REGISTRATION_LENGTH 20
#define MAX_COURSE_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_PHONE_LENGTH 20

// Estrutura do aluno (nó da lista encadeada)
typedef struct Student {
    int id;
    char name[MAX_NAME_LENGTH];
    char registration[MAX_REGISTRATION_LENGTH];
    char course[MAX_COURSE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    time_t enrollment_date;
    float* grades;              // Array dinâmico de notas
    int num_grades;             // Quantidade de notas
    float average;              // Média geral
    struct Student* next;       // Ponteiro para próximo aluno
} Student;

// Estrutura para a lista de alunos
typedef struct {
    Student* head;              // Ponteiro para o primeiro aluno
    Student* tail;              // Ponteiro para o último aluno
    int count;                  // Quantidade de alunos
} StudentList;

// Funções de criação e destruição
StudentList* create_student_list(void);
void destroy_student_list(StudentList* list);
Student* create_student(const char* name, const char* registration, const char* course);

// Funções de manipulação da lista
int insert_student(StudentList* list, Student* student);
int remove_student(StudentList* list, const char* registration);
Student* find_student(StudentList* list, const char* registration);
void sort_students(StudentList* list, int (*compare)(const Student*, const Student*));

// Funções de manipulação de notas
int add_grade(Student* student, float grade);
int update_grade(Student* student, int index, float grade);
float calculate_average(const Student* student);
void update_all_averages(StudentList* list);

// Funções de busca e filtro
Student** find_students_by_course(StudentList* list, const char* course, int* count);
Student** get_top_students(StudentList* list, int limit);
Student** get_failing_students(StudentList* list, float min_average, int* count);

// Funções de validação
int is_valid_registration(const char* registration);
int is_valid_email(const char* email);
int is_valid_phone(const char* phone);
int has_passing_grade(const Student* student, float min_grade);

// Funções de impressão e relatórios
void print_student(const Student* student);
void print_student_list(const StudentList* list);
void print_student_report(const Student* student);
void generate_class_report(const StudentList* list, const char* course);

// Funções de ordenação (comparadores)
int compare_by_name(const Student* a, const Student* b);
int compare_by_registration(const Student* a, const Student* b);
int compare_by_average(const Student* a, const Student* b);

// Funções de estatísticas
float get_class_average(const StudentList* list, const char* course);
void calculate_grade_distribution(const StudentList* list, int* distribution, int num_ranges);
int get_passing_count(const StudentList* list, float min_grade);

// Funções de arquivo
int save_students_to_file(const StudentList* list, const char* filename);
int load_students_from_file(StudentList* list, const char* filename);
void export_student_data_csv(const StudentList* list, const char* filename);

#endif // STUDENT_H 