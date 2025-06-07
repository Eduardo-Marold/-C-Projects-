# Sistema de Gerenciamento de Tarefas em C

Este é um sistema de gerenciamento de tarefas desenvolvido em C, que permite aos usuários gerenciar suas atividades diárias de forma eficiente.

## Funcionalidades

- Gerenciamento de Tarefas
  - Adicionar novas tarefas
  - Editar tarefas existentes
  - Marcar tarefas como concluídas
  - Excluir tarefas
  - Listar todas as tarefas

- Categorização
  - Organizar tarefas por categorias
  - Filtrar tarefas por categoria
  - Gerenciar categorias

- Prioridades
  - Definir prioridade das tarefas (Alta, Média, Baixa)
  - Ordenar tarefas por prioridade
  - Visualizar tarefas urgentes

- Datas
  - Definir data de vencimento
  - Alertas de tarefas próximas ao vencimento
  - Visualizar tarefas atrasadas

## Estrutura do Projeto

```
task_manager/
├── src/
│   ├── main.c              # Arquivo principal
│   ├── task.c              # Implementação das funções de tarefas
│   ├── category.c          # Implementação das funções de categorias
│   ├── file_handler.c      # Manipulação de arquivos
│   └── utils.c             # Funções utilitárias
├── include/
│   ├── task.h             # Definições de estruturas e protótipos de tarefas
│   ├── category.h         # Definições de estruturas e protótipos de categorias
│   ├── file_handler.h     # Protótipos de funções de manipulação de arquivos
│   └── utils.h            # Protótipos de funções utilitárias
├── data/
│   ├── tasks.dat          # Arquivo de armazenamento de tarefas
│   └── categories.dat     # Arquivo de armazenamento de categorias
└── Makefile              # Arquivo de compilação
```

## Requisitos

- Compilador GCC
- Sistema operacional: Windows, Linux ou macOS
- Make (para compilação automatizada)

## Como Compilar

1. Certifique-se de ter o GCC e Make instalados
2. Abra o terminal na pasta do projeto
3. Execute o comando:
```bash
make
```

## Como Executar

Após compilar, execute o programa:
```bash
./task_manager
```

## Estruturas de Dados

### Tarefa (Task)
```c
typedef struct {
    int id;
    char title[100];
    char description[500];
    int category_id;
    int priority;
    char due_date[11];
    int completed;
} Task;
```

### Categoria (Category)
```c
typedef struct {
    int id;
    char name[50];
    char description[200];
} Category;
```

## Funcionalidades Detalhadas

1. **Gerenciamento de Tarefas**
   - Criar nova tarefa com título, descrição e categoria
   - Editar detalhes da tarefa
   - Marcar/desmarcar como concluída
   - Excluir tarefa
   - Listar todas as tarefas

2. **Categorização**
   - Criar novas categorias
   - Associar tarefas a categorias
   - Filtrar tarefas por categoria
   - Editar e excluir categorias

3. **Prioridades**
   - Definir prioridade (1-Alta, 2-Média, 3-Baixa)
   - Ordenar tarefas por prioridade
   - Visualizar tarefas prioritárias

4. **Gestão de Datas**
   - Definir data de vencimento
   - Alertar sobre tarefas próximas ao vencimento
   - Listar tarefas atrasadas

## Contribuição

Sinta-se à vontade para contribuir com o projeto através de:
- Reporte de bugs
- Sugestões de melhorias
- Pull requests

## Licença

Este projeto está sob a licença MIT. 