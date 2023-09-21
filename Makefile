test: test.l test.y
	bison -d test.y
	flex test.l
	cc -o $@ test.tab.c lex.yy.c -lfl -lm

clean:
	rm -f test \
	lex.yy.c test.tab.c test.tab.h