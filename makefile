OBJS = producao.o alocaMemoria.o
SAIDA = producao
CC = gcc
FLAGS = -g -c -Wall

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(SAIDA)

producao.o: producao.c
	$(CC) $(FLAGS) producao.c

alocaMemoria.o: alocaMemoria.c
	$(CC) $(FLAGS) alocaMemoria.c

clean:
	rm -f $(OBJS) 
