CC		:= gcc
CFLAGS	:= -w

BIN		:= bin
SRC		:= .
INCLUDE	:= .

EXECUTABLE	:= trab1
SOURCEDIRS	:= $(shell find $(SRC) -type d)
INCLUDEDIRS	:= $(shell find $(INCLUDE) -type d)

ARGS1 := ./in-exemplos/1.txt
ARGS2 := ./in-exemplos/2.txt
ARGS3 := ./in-exemplos/3.txt
ARGS4 := ./in-exemplos/4.txt
ARGS5 := ./in-exemplos/5.txt
K     := 3
SAIDA := saida.txt

VALGRIND	:= 

CINCLUDES	:= $(patsubst %,-I%, $(INCLUDEDIRS:%/=%))
SOURCES		:= $(wildcard $(patsubst %,%/*.c, $(SOURCEDIRS)))
OBJECTS		:= $(SOURCES:.c=.o)

all: clean $(EXECUTABLE)

.PHONY: clean
clean:
	-$(RM) $(OBJECTS)

run1: 
	./$(EXECUTABLE) $(ARGS1) $(K) $(SAIDA)

run2: 
	./$(EXECUTABLE) $(ARGS2) $(K) $(SAIDA)

run3: 
	./$(EXECUTABLE) $(ARGS3) $(K) $(SAIDA)

run4: 
	./$(EXECUTABLE) $(ARGS4) $(K) $(SAIDA)

run5: 
	./$(EXECUTABLE) $(ARGS5) $(K) $(SAIDA)

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