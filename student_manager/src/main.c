#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/student.h"
#include "../include/discipline.h"
#include "../include/grade.h"
#include "../include/utils.h"

// Protótipos das funções do menu
void menu_students(void);
void menu_disciplines(void);
void menu_grades(void);
void menu_reports(void);
void menu_settings(void);

// Variáveis globais
StudentList* student_list = NULL;
CurriculumMatrix* curriculum = NULL;
GradeMatrix* grades = NULL;

int main(void) {
    int option;
    
    // Inicialização das estruturas
    student_list = create_student_list();
    curriculum = create_curriculum_matrix(8, 6); // 8 períodos, máximo 6 disciplinas por período
    grades = create_grade_matrix(100, 48); // Capacidade inicial para 100 alunos e 48 disciplinas
    
    if (!student_list || !curriculum || !grades) {
        print_error("Erro na inicialização do sistema!");
        return ERROR;
    }
    
    // Carrega dados salvos
    load_students_from_file(student_list, "data/students.dat");
    load_disciplines_from_file(curriculum, "data/disciplines.dat");
    load_grades_from_file(grades, "data/grades.dat");
    
    // Loop principal do programa
    do {
        clear_screen();
        print_header("SISTEMA DE GERENCIAMENTO ACADÊMICO");
        printf("\n");
        printf("1. Gerenciar Alunos\n");
        printf("2. Gerenciar Disciplinas\n");
        printf("3. Gerenciar Notas\n");
        printf("4. Relatórios\n");
        printf("5. Configurações\n");
        printf("0. Sair\n");
        printf("\n");
        
        option = get_integer("Escolha uma opção: ", 0, 5);
        
        switch (option) {
            case 1:
                menu_students();
                break;
            case 2:
                menu_disciplines();
                break;
            case 3:
                menu_grades();
                break;
            case 4:
                menu_reports();
                break;
            case 5:
                menu_settings();
                break;
            case 0:
                // Salva dados antes de sair
                save_students_to_file(student_list, "data/students.dat");
                save_disciplines_to_file(curriculum, "data/disciplines.dat");
                save_grades_to_file(grades, "data/grades.dat");
                
                // Libera memória
                destroy_student_list(student_list);
                destroy_curriculum_matrix(curriculum);
                destroy_grade_matrix(grades);
                
                printf("\nSaindo do sistema...\n");
                break;
        }
    } while (option != 0);
    
    return SUCCESS;
}

void menu_students(void) {
    int option;
    char name[MAX_NAME_LENGTH];
    char registration[MAX_REGISTRATION_LENGTH];
    char course[MAX_COURSE_LENGTH];
    Student* student;
    
    do {
        clear_screen();
        print_header("GERENCIAR ALUNOS");
        printf("\n");
        printf("1. Cadastrar Novo Aluno\n");
        printf("2. Buscar Aluno\n");
        printf("3. Editar Aluno\n");
        printf("4. Remover Aluno\n");
        printf("5. Listar Todos os Alunos\n");
        printf("0. Voltar\n");
        printf("\n");
        
        option = get_integer("Escolha uma opção: ", 0, 5);
        
        switch (option) {
            case 1:
                get_string(name, MAX_NAME_LENGTH, "Nome do aluno: ");
                get_string(registration, MAX_REGISTRATION_LENGTH, "Matrícula: ");
                get_string(course, MAX_COURSE_LENGTH, "Curso: ");
                
                student = create_student(name, registration, course);
                if (insert_student(student_list, student) == SUCCESS) {
                    print_success("Aluno cadastrado com sucesso!");
                } else {
                    print_error("Erro ao cadastrar aluno!");
                    destroy_student_list(student);
                }
                break;
                
            case 2:
                get_string(registration, MAX_REGISTRATION_LENGTH, "Digite a matrícula: ");
                student = find_student(student_list, registration);
                if (student) {
                    print_student(student);
                } else {
                    print_error("Aluno não encontrado!");
                }
                break;
                
            case 3:
                get_string(registration, MAX_REGISTRATION_LENGTH, "Digite a matrícula: ");
                student = find_student(student_list, registration);
                if (student) {
                    get_string(name, MAX_NAME_LENGTH, "Novo nome (Enter para manter): ");
                    get_string(course, MAX_COURSE_LENGTH, "Novo curso (Enter para manter): ");
                    
                    if (strlen(name) > 0) strcpy(student->name, name);
                    if (strlen(course) > 0) strcpy(student->course, course);
                    
                    print_success("Dados atualizados com sucesso!");
                } else {
                    print_error("Aluno não encontrado!");
                }
                break;
                
            case 4:
                get_string(registration, MAX_REGISTRATION_LENGTH, "Digite a matrícula: ");
                if (remove_student(student_list, registration) == SUCCESS) {
                    print_success("Aluno removido com sucesso!");
                } else {
                    print_error("Erro ao remover aluno!");
                }
                break;
                
            case 5:
                print_student_list(student_list);
                break;
        }
        
        if (option != 0) {
            pause_screen();
        }
    } while (option != 0);
}

void menu_disciplines(void) {
    int option;
    char name[MAX_DISCIPLINE_NAME];
    char code[MAX_DISCIPLINE_CODE];
    int workload;
    Discipline* discipline;
    
    do {
        clear_screen();
        print_header("GERENCIAR DISCIPLINAS");
        printf("\n");
        printf("1. Cadastrar Nova Disciplina\n");
        printf("2. Buscar Disciplina\n");
        printf("3. Editar Disciplina\n");
        printf("4. Remover Disciplina\n");
        printf("5. Listar Grade Curricular\n");
        printf("0. Voltar\n");
        printf("\n");
        
        option = get_integer("Escolha uma opção: ", 0, 5);
        
        switch (option) {
            case 1:
                get_string(name, MAX_DISCIPLINE_NAME, "Nome da disciplina: ");
                get_string(code, MAX_DISCIPLINE_CODE, "Código: ");
                workload = get_integer("Carga horária: ", 15, 120);
                
                discipline = create_discipline(name, code, workload);
                if (add_discipline_to_matrix(curriculum, discipline, 1) == SUCCESS) {
                    print_success("Disciplina cadastrada com sucesso!");
                } else {
                    print_error("Erro ao cadastrar disciplina!");
                    destroy_discipline(discipline);
                }
                break;
                
            case 2:
                get_string(code, MAX_DISCIPLINE_CODE, "Digite o código: ");
                discipline = find_discipline(curriculum, code);
                if (discipline) {
                    print_discipline(discipline);
                } else {
                    print_error("Disciplina não encontrada!");
                }
                break;
                
            case 3:
                get_string(code, MAX_DISCIPLINE_CODE, "Digite o código: ");
                discipline = find_discipline(curriculum, code);
                if (discipline) {
                    char professor[MAX_PROFESSOR_NAME];
                    get_string(professor, MAX_PROFESSOR_NAME, "Professor: ");
                    workload = get_integer("Nova carga horária (0 para manter): ", 0, 120);
                    
                    if (update_discipline(discipline, professor, workload) == SUCCESS) {
                        print_success("Disciplina atualizada com sucesso!");
                    } else {
                        print_error("Erro ao atualizar disciplina!");
                    }
                } else {
                    print_error("Disciplina não encontrada!");
                }
                break;
                
            case 4:
                get_string(code, MAX_DISCIPLINE_CODE, "Digite o código: ");
                if (remove_discipline_from_matrix(curriculum, code) == SUCCESS) {
                    print_success("Disciplina removida com sucesso!");
                } else {
                    print_error("Erro ao remover disciplina!");
                }
                break;
                
            case 5:
                print_curriculum_matrix(curriculum);
                break;
        }
        
        if (option != 0) {
            pause_screen();
        }
    } while (option != 0);
}

void menu_grades(void) {
    int option;
    char registration[MAX_REGISTRATION_LENGTH];
    char code[MAX_DISCIPLINE_CODE];
    Student* student;
    Discipline* discipline;
    float grade_value;
    
    do {
        clear_screen();
        print_header("GERENCIAR NOTAS");
        printf("\n");
        printf("1. Lançar Nota\n");
        printf("2. Alterar Nota\n");
        printf("3. Consultar Notas do Aluno\n");
        printf("4. Consultar Notas da Disciplina\n");
        printf("5. Calcular Médias\n");
        printf("0. Voltar\n");
        printf("\n");
        
        option = get_integer("Escolha uma opção: ", 0, 5);
        
        switch (option) {
            case 1:
                get_string(registration, MAX_REGISTRATION_LENGTH, "Matrícula do aluno: ");
                student = find_student(student_list, registration);
                
                if (!student) {
                    print_error("Aluno não encontrado!");
                    break;
                }
                
                get_string(code, MAX_DISCIPLINE_CODE, "Código da disciplina: ");
                discipline = find_discipline(curriculum, code);
                
                if (!discipline) {
                    print_error("Disciplina não encontrada!");
                    break;
                }
                
                grade_value = get_float("Nota: ", 0.0, 10.0);
                
                if (set_grade(grades, student->id, discipline->id, grade_value) == SUCCESS) {
                    print_success("Nota lançada com sucesso!");
                } else {
                    print_error("Erro ao lançar nota!");
                }
                break;
                
            case 2:
                // Similar ao caso 1, mas atualizando nota existente
                break;
                
            case 3:
                get_string(registration, MAX_REGISTRATION_LENGTH, "Matrícula do aluno: ");
                student = find_student(student_list, registration);
                
                if (student) {
                    print_student_report_card(grades, student->id);
                } else {
                    print_error("Aluno não encontrado!");
                }
                break;
                
            case 4:
                get_string(code, MAX_DISCIPLINE_CODE, "Código da disciplina: ");
                discipline = find_discipline(curriculum, code);
                
                if (discipline) {
                    print_discipline_grades(grades, discipline->id);
                } else {
                    print_error("Disciplina não encontrada!");
                }
                break;
                
            case 5:
                update_all_final_grades(grades);
                print_success("Médias calculadas com sucesso!");
                break;
        }
        
        if (option != 0) {
            pause_screen();
        }
    } while (option != 0);
}

void menu_reports(void) {
    int option;
    
    do {
        clear_screen();
        print_header("RELATÓRIOS");
        printf("\n");
        printf("1. Boletim Individual\n");
        printf("2. Histórico Escolar\n");
        printf("3. Estatísticas da Turma\n");
        printf("4. Alunos em Risco\n");
        printf("5. Exportar Dados\n");
        printf("0. Voltar\n");
        printf("\n");
        
        option = get_integer("Escolha uma opção: ", 0, 5);
        
        switch (option) {
            case 1:
                // Implementar geração de boletim
                break;
            case 2:
                // Implementar geração de histórico
                break;
            case 3:
                // Implementar estatísticas
                break;
            case 4:
                // Implementar análise de risco
                break;
            case 5:
                // Implementar exportação
                break;
        }
        
        if (option != 0) {
            pause_screen();
        }
    } while (option != 0);
}

void menu_settings(void) {
    int option;
    
    do {
        clear_screen();
        print_header("CONFIGURAÇÕES");
        printf("\n");
        printf("1. Criar Backup\n");
        printf("2. Restaurar Backup\n");
        printf("3. Limpar Dados\n");
        printf("4. Verificar Integridade\n");
        printf("0. Voltar\n");
        printf("\n");
        
        option = get_integer("Escolha uma opção: ", 0, 4);
        
        switch (option) {
            case 1:
                if (create_backup("data", "data/backup") == SUCCESS) {
                    print_success("Backup criado com sucesso!");
                } else {
                    print_error("Erro ao criar backup!");
                }
                break;
                
            case 2:
                if (restore_backup("data/backup", "data") == SUCCESS) {
                    print_success("Backup restaurado com sucesso!");
                } else {
                    print_error("Erro ao restaurar backup!");
                }
                break;
                
            case 3:
                if (confirm_action("Tem certeza que deseja limpar todos os dados?")) {
                    destroy_student_list(student_list);
                    destroy_curriculum_matrix(curriculum);
                    destroy_grade_matrix(grades);
                    
                    student_list = create_student_list();
                    curriculum = create_curriculum_matrix(8, 6);
                    grades = create_grade_matrix(100, 48);
                    
                    print_success("Dados limpos com sucesso!");
                }
                break;
                
            case 4:
                if (verify_backup_integrity("data/backup") == SUCCESS) {
                    print_success("Integridade verificada com sucesso!");
                } else {
                    print_warning("Problemas encontrados na verificação!");
                }
                break;
        }
        
        if (option != 0) {
            pause_screen();
        }
    } while (option != 0);
} 