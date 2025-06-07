#ifndef GRADE_H
#define GRADE_H

#include "student.h"
#include "discipline.h"

// Definição das constantes
#define MAX_GRADES 4           // Máximo de notas por disciplina
#define MIN_GRADE 0.0         // Nota mínima
#define MAX_GRADE 10.0        // Nota máxima
#define PASSING_GRADE 6.0     // Nota mínima para aprovação

// Estrutura para uma nota individual
typedef struct {
    float value;              // Valor da nota
    float weight;             // Peso da nota
    char description[50];     // Descrição (ex: "Prova 1", "Trabalho")
    time_t date;             // Data da avaliação
} Grade;

// Estrutura para o conjunto de notas de uma disciplina
typedef struct {
    int student_id;          // ID do aluno
    int discipline_id;       // ID da disciplina
    Grade grades[MAX_GRADES]; // Array de notas
    int num_grades;          // Quantidade atual de notas
    float final_grade;       // Média final
    int attendance;          // Frequência (em porcentagem)
    char status[20];         // Status (Aprovado/Reprovado)
} StudentGrades;

// Estrutura para a matriz de notas
typedef struct {
    float** matrix;          // Matriz de notas [aluno][disciplina]
    int num_students;        // Número de alunos
    int num_disciplines;     // Número de disciplinas
    StudentGrades*** details; // Matriz de detalhes das notas
} GradeMatrix;

// Funções de criação e destruição
GradeMatrix* create_grade_matrix(int num_students, int num_disciplines);
void destroy_grade_matrix(GradeMatrix* matrix);
StudentGrades* create_student_grades(int student_id, int discipline_id);
void destroy_student_grades(StudentGrades* grades);

// Funções de manipulação de notas
int add_grade(StudentGrades* grades, float value, float weight, const char* description);
int update_grade(StudentGrades* grades, int index, float new_value);
int remove_grade(StudentGrades* grades, int index);
float calculate_final_grade(const StudentGrades* grades);

// Funções de manipulação da matriz
int set_grade(GradeMatrix* matrix, int student_id, int discipline_id, float grade);
float get_grade(const GradeMatrix* matrix, int student_id, int discipline_id);
StudentGrades* get_student_grades(const GradeMatrix* matrix, int student_id, int discipline_id);
void update_all_final_grades(GradeMatrix* matrix);

// Funções de cálculo e estatísticas
float calculate_student_average(const GradeMatrix* matrix, int student_id);
float calculate_discipline_average(const GradeMatrix* matrix, int discipline_id);
float calculate_class_average(const GradeMatrix* matrix);
void calculate_grade_distribution(const GradeMatrix* matrix, int discipline_id, int* distribution, int num_ranges);

// Funções de análise
int* get_failing_students(const GradeMatrix* matrix, int discipline_id, int* count);
int* get_top_students(const GradeMatrix* matrix, int discipline_id, int limit, int* count);
float get_approval_rate(const GradeMatrix* matrix, int discipline_id);
void analyze_performance_trend(const GradeMatrix* matrix, int discipline_id);

// Funções de validação
int is_valid_grade(float grade);
int has_minimum_grades(const StudentGrades* grades);
int check_attendance_requirement(const StudentGrades* grades);
int can_calculate_final_grade(const StudentGrades* grades);

// Funções de relatório
void print_student_report_card(const GradeMatrix* matrix, int student_id);
void print_discipline_grades(const GradeMatrix* matrix, int discipline_id);
void print_class_statistics(const GradeMatrix* matrix, int discipline_id);
void generate_performance_report(const GradeMatrix* matrix);

// Funções de arquivo
int save_grades_to_file(const GradeMatrix* matrix, const char* filename);
int load_grades_from_file(GradeMatrix* matrix, const char* filename);
void export_grades_to_csv(const GradeMatrix* matrix, const char* filename);

// Funções de ordenação e classificação
void sort_students_by_grade(const GradeMatrix* matrix, int discipline_id, int** sorted_students, int* count);
void rank_students_overall(const GradeMatrix* matrix, int** rankings, int* count);
void identify_at_risk_students(const GradeMatrix* matrix, int** at_risk_students, int* count);

// Funções de atualização em lote
int import_grades_from_csv(GradeMatrix* matrix, const char* filename);
int batch_update_grades(GradeMatrix* matrix, const char* updates_file);
void recalculate_all_grades(GradeMatrix* matrix);

#endif // GRADE_H 