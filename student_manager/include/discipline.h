#ifndef DISCIPLINE_H
#define DISCIPLINE_H

// Definição das constantes
#define MAX_DISCIPLINE_NAME 50
#define MAX_DISCIPLINE_CODE 10
#define MAX_PROFESSOR_NAME 100
#define MAX_PREREQUISITES 10
#define MAX_DESCRIPTION 200

// Enumeração para o período da disciplina
typedef enum {
    MORNING,
    AFTERNOON,
    EVENING
} Period;

// Estrutura da disciplina
typedef struct Discipline {
    int id;
    char name[MAX_DISCIPLINE_NAME];
    char code[MAX_DISCIPLINE_CODE];
    char professor[MAX_PROFESSOR_NAME];
    char description[MAX_DESCRIPTION];
    int workload;                    // Carga horária em horas
    int credits;                     // Créditos da disciplina
    Period period;                   // Período de oferta
    float min_grade;                 // Nota mínima para aprovação
    int* prerequisites;              // Array de IDs dos pré-requisitos
    int num_prerequisites;           // Quantidade de pré-requisitos
    int max_students;                // Capacidade máxima de alunos
    int current_students;            // Quantidade atual de alunos
} Discipline;

// Estrutura para a matriz de disciplinas
typedef struct {
    Discipline** disciplines;        // Matriz de disciplinas
    int rows;                       // Número de períodos
    int cols;                       // Número máximo de disciplinas por período
    int total_disciplines;          // Total de disciplinas
} CurriculumMatrix;

// Funções de criação e destruição
Discipline* create_discipline(const char* name, const char* code, int workload);
void destroy_discipline(Discipline* discipline);
CurriculumMatrix* create_curriculum_matrix(int num_periods, int max_per_period);
void destroy_curriculum_matrix(CurriculumMatrix* matrix);

// Funções de manipulação de disciplinas
int add_discipline_to_matrix(CurriculumMatrix* matrix, Discipline* discipline, int period);
int remove_discipline_from_matrix(CurriculumMatrix* matrix, const char* code);
Discipline* find_discipline(CurriculumMatrix* matrix, const char* code);
int update_discipline(Discipline* discipline, const char* professor, int workload);

// Funções de pré-requisitos
int add_prerequisite(Discipline* discipline, int prerequisite_id);
int remove_prerequisite(Discipline* discipline, int prerequisite_id);
int check_prerequisites(const Discipline* discipline, const int* completed_disciplines, int num_completed);
int* get_all_prerequisites(const Discipline* discipline, int* count);

// Funções de validação
int is_valid_discipline_code(const char* code);
int can_enroll_in_discipline(const Discipline* discipline, const int* completed_disciplines, int num_completed);
int has_available_slots(const Discipline* discipline);
int has_schedule_conflict(const Discipline* disc1, const Discipline* disc2);

// Funções de matrícula
int enroll_student_in_discipline(Discipline* discipline);
int unenroll_student_from_discipline(Discipline* discipline);
int get_available_slots(const Discipline* discipline);

// Funções de busca e filtro
Discipline** find_disciplines_by_period(const CurriculumMatrix* matrix, Period period, int* count);
Discipline** get_available_disciplines(const CurriculumMatrix* matrix, int* count);
Discipline** get_disciplines_by_professor(const CurriculumMatrix* matrix, const char* professor, int* count);

// Funções de impressão e relatórios
void print_discipline(const Discipline* discipline);
void print_curriculum_matrix(const CurriculumMatrix* matrix);
void print_prerequisites_tree(const Discipline* discipline, const CurriculumMatrix* matrix);
void generate_discipline_report(const Discipline* discipline);

// Funções de verificação de grade
int verify_curriculum_integrity(const CurriculumMatrix* matrix);
int check_workload_distribution(const CurriculumMatrix* matrix);
void suggest_optimal_sequence(const CurriculumMatrix* matrix);

// Funções de arquivo
int save_disciplines_to_file(const CurriculumMatrix* matrix, const char* filename);
int load_disciplines_from_file(CurriculumMatrix* matrix, const char* filename);
void export_curriculum_to_csv(const CurriculumMatrix* matrix, const char* filename);

// Funções de estatísticas
float calculate_total_workload(const CurriculumMatrix* matrix);
int count_disciplines_by_period(const CurriculumMatrix* matrix, Period period);
void analyze_prerequisites_complexity(const CurriculumMatrix* matrix);

#endif // DISCIPLINE_H 