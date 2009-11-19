%{
/**
  * lexical analyzer for a subset of pascal
  * Authors: Rajkishan G
  *          Garimella Jagannath Kashyap
  *          Kashyap R Puranik
  **/
#include <stdio.h>
#include "y.tab.h"
#include "map.h"

extern int lineNo;
void yyerror(char *s);
char lineBuf[500];
ListNodePtr install_id();

%}

/* Declarations */

delim 	[ \t]
ws	{delim}+ 
letter 	[A-Za-z]
digit	[0-9]
id	{letter}({letter}|{digit})*
number	(-)?{digit}+({digit}+)?(E[+\-]?{digit}+)?


%%

and   {return AND;}
array {return ARRAY;}
":="  {return ASSIGNMENT;}
case  {return CASE;}
":"   {return COLON;}
","   {return COMMA;}
const {return CONST;}
div   {return DIV;}
do    {return DO;}
"."   {return DOT;}
".."  {return DOTDOT;}
downto {return DOWNTO;}
else   {return ELSE;}
"="    {return EQUAL;}
end    {return END;}
extern |
external {return EXTERNAL;}
for      {return FOR;}
forward  {return FORWARD;}
function {return FUNCTION;}
">="     {return GE;} 
goto     {return GOTO;}
">"      {return GT;}
if       {return IF;}
label    {return LABEL;}
"["      {return LBRAC;}
"<="     {return LE;}
"("      {return LPAREN;}
"<"      {return LT;}
"-"      {return MINUS;}
mod      {return MOD;}
nil      {return NIL;}
not      {return NOT;}
"<>"     {return NOTEQUAL;}
{number} {yylval.symTabEntry = install_id();;yylval.symTabEntry->data.type = INTEGER; yylval.symTabEntry->data.isNum = 1; yylval.symTabEntry->data.constVal = atoi(yytext); return NUMBER;}  
{number}"."{number} {yylval.symTabEntry = install_id();;yylval.symTabEntry->data.type = REAL;return REALNUMBER;}
of       {return OF;}
or       {return OR;}
otherwise {return OTHERWISE;}
packed    {return PACKED;}
begin     {return PBEGIN;}
"+"       {return PLUS;}
file      {return PFILE;}
procedure {return PROCEDURE;}
program   {return PROGRAM;}
"]"       {return RBRAC;}
record    {return RECORD;}
repeat    {return REPEAT;}
")"       {return RPAREN;}
";"       {return SEMICOLON;}
"/"       {return SLASH;}
"*"       {return STAR;}
"**"      {return STARSTAR;}
set       {return SET;}
then      {return THEN;}
to        {return TO;}
type      {return TYPE;}
until     {return UNTIL;}
"->" |
"^"       {return UPARROW;}
var       {return VAR;}
while     {return WHILE;}
{ws}      {;}
"integer" {yylval.gen = INTEGER;return INTEGER;}
"real"    {yylval.gen = REAL;return REAL;} 
\n.*      {strcpy(lineBuf,yytext+1);lineNo++;yyless(1);}
{id}      {yylval.symTabEntry = install_id();/* bug: yylval.symTabEntry->data.type = -1*/;return IDENTIFIER;}
'([^']|'')+' {return CHARACTER_STRING;}
"(*"  |
"{"   {
	int c;
	while(c=input())
	{
		if(c=='}') break;
		else if (c == '*')
        {
			if((c=input()) == ')') break;
			else unput(c);
		}
		else if(c == '\n') lineNo++;
		else if(c==0) {
			printf("Unexpected EOF at line %d\n",lineNo);
			exit(1);
		}
	}
}
.         {printf("Warning. Skipping illegal character %c at line %d\n",yytext[0],lineNo);}

%%

ListNodePtr install_id()
{
	int i=0;
	char *lookupVal=malloc(yyleng+1);
	
	// Make a copy of the current token to lookupVal
	for(i=0;i<yyleng;i++)
		lookupVal[i]=yytext[i];
	lookupVal[i]='\0';
	
	ListNodePtr lookupToken=lookup(lookupVal,currentST,0);
	if(lookupToken==NULL || lookupToken->data.tableNo == 0 && currentST != 0 && isDeclaration)
	{
		
		
		token entry;
		initToken(&entry);
		strcpy(entry.key,lookupVal);
		ListNodePtr entryPtr=insertIntoMap(lookupVal,entry,currentST);
		return entryPtr;
	}
	return lookupToken;
}




void yyerror(char *s)
{
	printf("line %d: %s at %s in this line: %s\n",lineNo, s, yytext,lineBuf);
}
