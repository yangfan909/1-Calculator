%{
#  include <stdio.h>
#  include <math.h>
void yyerror(char *s);
int yylex();
%}

// you should define the return value in lexer here
%union {
	float val;
}

// you should declare tokens and their value type here
%token <val> NUMBER LP RP
%left ADD SUB MUL DIV 
%right EXPONENT
%token EOL
%type <val> term exp0 exp1 exp2 


// you should declare rules for parser between the first and the second %%
%%
calclist: 
	| calclist exp2 EOL { printf("= %.5f\n> ", $2);}
	| calclist EOL { printf("> "); } 
	;

exp0: term
	| exp0 EXPONENT exp0 { $$ = pow($1,$3);}
	| LP exp2 RP {$$ = $2; } 
	;
exp1:exp0
	| exp1 DIV exp1 { $$ = $1 / $3;}
	| exp1 MUL exp1 { $$ = $1 * $3; }
	;

exp2: exp1
	| exp2 ADD exp2 { $$ = $1 + $3; }
	| exp2 SUB exp2 { $$ = $1 - $3; }
	;



term: NUMBER
	;


%%
void yyerror(char *s)
{
	fprintf(stderr, "Error: %s\n", s);
}

int main()
{
	printf("> "); 
	yyparse();
}