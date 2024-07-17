CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin

# Lista de arquivos-fonte (todos os .c no diretório src)
SRCS = $(wildcard $(SRC)/*.c)

# Gere a lista de objetos a partir dos arquivos-fonte
OBJS = $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(SRCS))

EXE = $(BIN)/tp2.out

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(LIBS)

# Regra para compilar cada arquivo-fonte
$(OBJ)/%.o: $(SRC)/%.c $(wildcard $(INC)/*.h)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(EXE) $(OBJS) gmon.out

