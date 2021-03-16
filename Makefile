CC		:= gcc
CFLAGS	:= -w -O3

BIN		:= bin
SRC		:= .
INCLUDE	:= .

EXECUTABLE	:= trab1
SOURCEDIRS	:= $(shell find $(SRC) -type d)
INCLUDEDIRS	:= $(shell find $(INCLUDE) -type d)

ARGS  := ./in-exemplos/0.txt
K     := 3
ARGS0 := ./in-exemplos/0.txt 3
ARGS1 := ./in-exemplos/1.txt 2
ARGS2 := ./in-exemplos/2.txt 4
ARGS3 := ./in-exemplos/3.txt 5
ARGS4 := ./in-exemplos/4.txt 5
ARGS5 := ./in-exemplos/5.txt 10
ARGS6 := ./in-exemplos/6.txt 3
ARGS7 := ./in-exemplos/7.txt 3
ARGS8 := ./in-exemplos/8.txt 10
ARGS9 := ./in-exemplos/9.txt 42
ARGS10 := ./in-exemplos/10.txt 20
SAIDA := saida.txt

VALGRIND	:= 

CINCLUDES	:= $(patsubst %,-I%, $(INCLUDEDIRS:%/=%))
SOURCES		:= $(wildcard $(patsubst %,%/*.c, $(SOURCEDIRS)))
OBJECTS		:= $(SOURCES:.c=.o)

all: clean $(EXECUTABLE)

.PHONY: clean
clean:
	-$(RM) $(OBJECTS)

run: 
	./$(EXECUTABLE) $(ARGS) $(K) $(SAIDA)

run0: 
	./$(EXECUTABLE) $(ARGS0) $(SAIDA)

run1: 
	./$(EXECUTABLE) $(ARGS1) $(SAIDA)

run2: 
	./$(EXECUTABLE) $(ARGS2) $(SAIDA)

run3: 
	./$(EXECUTABLE) $(ARGS3) $(SAIDA)

run4: 
	./$(EXECUTABLE) $(ARGS4) $(SAIDA)

run5: 
	./$(EXECUTABLE) $(ARGS5) $(SAIDA)

run6: 
	./$(EXECUTABLE) $(ARGS6) $(SAIDA)

run7: 
	./$(EXECUTABLE) $(ARGS7) $(SAIDA)

run8: 
	./$(EXECUTABLE) $(ARGS8) $(SAIDA)

run9: 
	./$(EXECUTABLE) $(ARGS9) $(SAIDA)

run10: 
	./$(EXECUTABLE) $(ARGS10) $(SAIDA)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(CINCLUDES) $^ -o $@ $(LIBRARIES) -lm

val: 
	valgrind ./$(EXECUTABLE) $(ARGS) $(K) $(SAIDA)

val0: 
	valgrind ./$(EXECUTABLE) $(ARGS0) $(SAIDA)

val1: 
	valgrind ./$(EXECUTABLE) $(ARGS1) $(SAIDA)

val2: 
	valgrind ./$(EXECUTABLE) $(ARGS2) $(SAIDA)

val3: 
	valgrind ./$(EXECUTABLE) $(ARGS3) $(SAIDA)
	
val4: 
	valgrind ./$(EXECUTABLE) $(ARGS4) $(SAIDA)

val5: 
	valgrind ./$(EXECUTABLE) $(ARGS5) $(SAIDA)

val6: 
	valgrind ./$(EXECUTABLE) $(ARGS6) $(SAIDA)
	
val7: 
	valgrind ./$(EXECUTABLE) $(ARGS7) $(SAIDA)

val8: 
	valgrind ./$(EXECUTABLE) $(ARGS8) $(SAIDA)

val9: 
	valgrind ./$(EXECUTABLE) $(ARGS9) $(SAIDA)

val10: 
	valgrind ./$(EXECUTABLE) $(ARGS10) $(SAIDA)
	
full: 
	- valgrind -v --leak-check=full ./$(EXECUTABLE) $(N)
