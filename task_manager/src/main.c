#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/task.h"
#include "../include/category.h"
#include "../include/file_handler.h"
#include "../include/utils.h"

// Protótipos das funções do menu
void menu_tasks(void);
void menu_categories(void);
void menu_reports(void);
void menu_settings(void);

// Funções auxiliares do menu de tarefas
void add_task(void);
void edit_task(void);
void delete_task_menu(void);
void list_tasks(void);
void mark_task_completed(void);

// Funções auxiliares do menu de categorias
void add_category(void);
void edit_category(void);
void delete_category_menu(void);
void list_categories(void);

// Funções auxiliares do menu de relatórios
void show_task_statistics(void);
void show_category_statistics(void);
void export_data(void);

// Função principal
int main(void) {
    int option;
    
    // Inicializa o sistema de arquivos
    if (initialize_data_directory() != SUCCESS) {
        print_error("Erro ao inicializar o sistema de arquivos");
        return ERROR;
    }
    
    // Loop principal do programa
    do {
        clear_screen();
        print_header("GERENCIADOR DE TAREFAS");
        printf("\n");
        printf("1. Gerenciar Tarefas\n");
        printf("2. Gerenciar Categorias\n");
        printf("3. Relatórios\n");
        printf("4. Configurações\n");
        printf("0. Sair\n");
        printf("\n");
        
        option = get_option(0, 4, "Escolha uma opção: ");
        
        switch (option) {
            case 1:
                menu_tasks();
                break;
            case 2:
                menu_categories();
                break;
            case 3:
                menu_reports();
                break;
            case 4:
                menu_settings();
                break;
            case 0:
                printf("\nSaindo do programa...\n");
                break;
            default:
                print_error("Opção inválida!");
                pause_screen();
        }
    } while (option != 0);
    
    return SUCCESS;
}

void menu_tasks(void) {
    int option;
    
    do {
        clear_screen();
        print_header("GERENCIAR TAREFAS");
        printf("\n");
        printf("1. Adicionar Nova Tarefa\n");
        printf("2. Editar Tarefa\n");
        printf("3. Excluir Tarefa\n");
        printf("4. Listar Tarefas\n");
        printf("5. Marcar Tarefa como Concluída\n");
        printf("0. Voltar\n");
        printf("\n");
        
        option = get_option(0, 5, "Escolha uma opção: ");
        
        switch (option) {
            case 1:
                add_task();
                break;
            case 2:
                edit_task();
                break;
            case 3:
                delete_task_menu();
                break;
            case 4:
                list_tasks();
                break;
            case 5:
                mark_task_completed();
                break;
        }
    } while (option != 0);
}

void menu_categories(void) {
    int option;
    
    do {
        clear_screen();
        print_header("GERENCIAR CATEGORIAS");
        printf("\n");
        printf("1. Adicionar Nova Categoria\n");
        printf("2. Editar Categoria\n");
        printf("3. Excluir Categoria\n");
        printf("4. Listar Categorias\n");
        printf("0. Voltar\n");
        printf("\n");
        
        option = get_option(0, 4, "Escolha uma opção: ");
        
        switch (option) {
            case 1:
                add_category();
                break;
            case 2:
                edit_category();
                break;
            case 3:
                delete_category_menu();
                break;
            case 4:
                list_categories();
                break;
        }
    } while (option != 0);
}

void menu_reports(void) {
    int option;
    
    do {
        clear_screen();
        print_header("RELATÓRIOS");
        printf("\n");
        printf("1. Estatísticas de Tarefas\n");
        printf("2. Estatísticas por Categoria\n");
        printf("3. Exportar Dados\n");
        printf("0. Voltar\n");
        printf("\n");
        
        option = get_option(0, 3, "Escolha uma opção: ");
        
        switch (option) {
            case 1:
                show_task_statistics();
                break;
            case 2:
                show_category_statistics();
                break;
            case 3:
                export_data();
                break;
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
        printf("3. Verificar Integridade dos Dados\n");
        printf("0. Voltar\n");
        printf("\n");
        
        option = get_option(0, 3, "Escolha uma opção: ");
        
        switch (option) {
            case 1:
                if (create_backup() == SUCCESS) {
                    print_success("Backup criado com sucesso!");
                } else {
                    print_error("Erro ao criar backup!");
                }
                break;
            case 2:
                // Implementar restauração de backup
                break;
            case 3:
                if (verify_data_integrity() == SUCCESS) {
                    print_success("Dados íntegros!");
                } else {
                    print_warning("Problemas encontrados nos dados!");
                }
                break;
        }
        pause_screen();
    } while (option != 0);
}

// Implementação das funções auxiliares será feita nos respectivos arquivos .c 