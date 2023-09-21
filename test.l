%{
# include "test.tab.h"
void yyerror(char*);
%}

/* you should implement the following between the first and the second %% */
/* 1. more operators and actions */
/* 2. how to match float numbers? */
%%
"**" { return EXPONENT;}
"*" { return MUL; }
"/" {return DIV;}
"+"	{ return ADD; }
"-"	{ return SUB; }
"\(" {return LP;}
")" {return RP;}
((0|([1-9][0-9]*))\.[0-9]*)|(0|([1-9][0-9]*)) { yylval.val = atof(yytext); return NUMBER; }

[ \t]   { /* ignore white space */ }
.	{ yyerror("Unknown character!\n"); }
\n      { return EOL; }
%%