CC		:= gcc
CFLAGS	:= -w

BIN		:= bin
SRC		:= .
INCLUDE	:= .

EXECUTABLE	:= trab1
SOURCEDIRS	:= $(shell find $(SRC) -type d)
INCLUDEDIRS	:= $(shell find $(INCLUDE) -type d)

ARGS0 := ./in-exemplos/0.txt 3
ARGS1 := ./in-exemplos/1.txt 2
ARGS2 := ./in-exemplos/2.txt 4
ARGS3 := ./in-exemplos/3.txt 5
ARGS4 := ./in-exemplos/4.txt 5
ARGS5 := ./in-exemplos/5.txt 10
SAIDA := saida.txt

VALGRIND	:= 

CINCLUDES	:= $(patsubst %,-I%, $(INCLUDEDIRS:%/=%))
SOURCES		:= $(wildcard $(patsubst %,%/*.c, $(SOURCEDIRS)))
OBJECTS		:= $(SOURCES:.c=.o)

all: clean $(EXECUTABLE)

.PHONY: clean
clean:
	-$(RM) $(OBJECTS)

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

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(CINCLUDES) $^ -o $@ $(LIBRARIES) -lm

val1: all
	valgrind ./$(EXECUTABLE) $(ARGS1)

val2: all
	valgrind ./$(EXECUTABLE) $(ARGS2)

val3: all
	valgrind ./$(EXECUTABLE) $(ARGS3)
	
val4: all
	valgrind ./$(EXECUTABLE) $(ARGS4)

val5: all
	valgrind ./$(EXECUTABLE) $(ARGS5)
	
full: all
	- valgrind -v --leak-check=full ./$(EXECUTABLE) $(N)
