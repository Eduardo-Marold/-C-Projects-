# Sistema de Gerenciamento de Alunos em C

Este é um sistema de gerenciamento de alunos desenvolvido em C, utilizando estruturas de dados avançadas como listas encadeadas, ponteiros e matrizes.

## Funcionalidades

- Gerenciamento de Alunos
  - Cadastrar novo aluno
  - Editar dados do aluno
  - Remover aluno
  - Buscar aluno por matrícula
  - Listar todos os alunos

- Gerenciamento de Notas
  - Registrar notas por disciplina
  - Calcular média por aluno
  - Calcular média por disciplina
  - Gerar boletim individual

- Gerenciamento de Disciplinas
  - Cadastrar disciplinas
  - Associar professores
  - Definir carga horária
  - Gerenciar pré-requisitos

- Relatórios e Estatísticas
  - Alunos aprovados/reprovados
  - Ranking de notas
  - Histórico escolar
  - Estatísticas por disciplina

## Estruturas de Dados Utilizadas

1. **Lista Encadeada de Alunos**
   - Cadastro dinâmico de alunos
   - Busca otimizada
   - Ordenação flexível

2. **Matriz de Notas**
   - Notas por aluno/disciplina
   - Cálculos de médias
   - Análise de desempenho

3. **Ponteiros**
   - Gerenciamento eficiente de memória
   - Relacionamentos entre estruturas
   - Manipulação dinâmica de dados

## Estrutura do Projeto

```
student_manager/
├── src/
│   ├── main.c              # Arquivo principal
│   ├── student.c           # Implementação das funções de alunos
│   ├── discipline.c        # Implementação das funções de disciplinas
│   ├── grade.c            # Implementação das funções de notas
│   └── utils.c            # Funções utilitárias
├── include/
│   ├── student.h          # Definições de estruturas de alunos
│   ├── discipline.h       # Definições de estruturas de disciplinas
│   ├── grade.h           # Definições de estruturas de notas
│   └── utils.h           # Definições de funções utilitárias
├── data/
│   ├── students.dat       # Arquivo de dados dos alunos
│   ├── disciplines.dat    # Arquivo de dados das disciplinas
│   └── grades.dat        # Arquivo de dados das notas
└── Makefile             # Arquivo de compilação
```

## Estruturas de Dados

### Aluno (Lista Encadeada)
```c
typedef struct Student {
    int id;
    char name[100];
    char registration[20];
    char course[50];
    float* grades;         // Array dinâmico de notas
    struct Student* next;  // Ponteiro para próximo aluno
} Student;
```

### Disciplina
```c
typedef struct Discipline {
    int id;
    char name[50];
    char code[10];
    int workload;
    int* prerequisites;    // Array de IDs de pré-requisitos
    int num_prerequisites;
} Discipline;
```

### Matriz de Notas
```c
typedef struct GradeMatrix {
    float** grades;       // Matriz de notas [aluno][disciplina]
    int num_students;
    int num_disciplines;
} GradeMatrix;
```

## Funcionalidades Detalhadas

1. **Gestão de Alunos**
   - Inserção em lista encadeada
   - Busca binária por matrícula
   - Remoção com reorganização automática
   - Ordenação por diferentes critérios

2. **Gestão de Notas**
   - Matriz dinâmica de notas
   - Cálculo de médias ponderadas
   - Análise de aprovação/reprovação
   - Geração de estatísticas

3. **Gestão de Disciplinas**
   - Árvore de pré-requisitos
   - Verificação de conflitos
   - Cálculo de carga horária total
   - Planejamento de grade

## Como Compilar

1. Certifique-se de ter o GCC instalado
2. Execute no terminal:
```bash
make
```

## Como Executar

Após compilar:
```bash
./student_manager
```

## Recursos Técnicos

1. **Alocação Dinâmica**
   - Uso de malloc/realloc
   - Gerenciamento de memória
   - Liberação adequada de recursos

2. **Estruturas Complexas**
   - Listas encadeadas
   - Matrizes dinâmicas
   - Árvores de dependência

3. **Algoritmos**
   - Ordenação eficiente
   - Busca otimizada
   - Cálculos matriciais

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para:
- Reportar bugs
- Sugerir melhorias
- Implementar novas funcionalidades

## Licença

Este projeto está sob a licença MIT. 