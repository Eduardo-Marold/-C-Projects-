# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -I./include

# Diretórios
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
DATA_DIR = data

# Arquivos fonte
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Nome do executável
TARGET = $(BIN_DIR)/task_manager

# Regra padrão
all: directories $(TARGET)

# Criação dos diretórios necessários
directories:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(DATA_DIR)
	@mkdir -p $(DATA_DIR)/backup

# Compilação do programa
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Compilação dos objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza
clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)

# Limpeza completa (incluindo dados)
cleanall: clean
	rm -rf $(DATA_DIR)/*

# Execução do programa
run: all
	./$(TARGET)

# Regras que não são arquivos
.PHONY: all clean cleanall run directories 