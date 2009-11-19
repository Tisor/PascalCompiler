LEX = lex
YACC = yacc

CC = gcc

all: parser

parser: yac lex
	$(CC) -o parser map.c y.tab.c lex.yy.c -ll

yac:
	$(YACC) -d parser.y

lex: yac
	$(LEX) -i scanner.l
	
clean:
	rm -f *.o lex.yy.c y.tab.c y.tab.h parser *~
