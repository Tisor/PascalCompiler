%{
/**
 * Parser for subset of the pascal language
 * Authors: Rajkishan G
 *           Garimella Jagannadh Kashyap
 *           Kashyap R Puranik
 **/
#include <stdio.h>
#include "map.h"

// TODO: add documentation for these variables, currFuncSign makes no sense

// variable declarations

int lineNo = 1;
void yyerror(char *s);
struct listNode *symTabEntryList[100];
int symTabEntryListIndex = 0;
int isArray,lowerBound,upperBound;
int isFunction;
int functionSignature[MAX_ARGUMENTS];
int exprListType[MAX_ARGUMENTS];
int exprListTypeIndex = 0;
int currFuncSign;
int temp;

// Function declarations
void declareId(int type);
void undeclaredID(token id);
void checkFuncSign(token func);
char* getOperation(int operation);
struct listNode* newTemp();
%}

%union { int gen; struct listNode *symTabEntry;struct Attributes *attr;}

%token 	<gen>AND
%token 	<gen>ARRAY
%token 	<gen>ASSIGNMENT
%token 	<gen>CASE
%token 	<gen>CHARACTER_STRING
%token 	<gen>COLON
%token 	<gen>COMMA
%token 	<gen>CONST
%token 	<gen>DIV
%token 	<gen>DO
%token 	<gen>DOT
%token 	<gen>DOTDOT
%token 	<gen>DOWNTO
%token 	<gen>ELSE
%token 	<gen>END
%token 	<gen>EQUAL
%token 	<gen>EXTERNAL
%token 	<gen>FOR
%token 	<gen>FORWARD
%token 	<gen>FUNCTION
%token 	<gen>GE
%token 	<gen>GOTO
%token 	<gen>GT
%token 	<symTabEntry>IDENTIFIER
%token 	<gen>IF
%token 	<gen>IN
%token 	<gen>INTEGER
%token 	<gen>LABEL
%token 	<gen>LBRAC
%token 	<gen>LE
%token 	<gen>LPAREN
%token 	<gen>LT
%token 	<gen>MINUS
%token 	<gen>MOD
%token 	<gen>NIL
%token 	<gen>NOT
%token 	<symTabEntry>NUMBER
%token 	<gen>NOTEQUAL
%token 	<gen>OF
%token 	<gen>OR
%token 	<gen>OTHERWISE
%token 	<gen>PACKED
%token 	<gen>PBEGIN
%token 	<gen>PFILE
%token 	<gen>PLUS
%token 	<gen>PROCEDURE
%token 	<gen>PROGRAM
%token 	<gen>RBRAC
%token 	<gen>REAL
%token 	<symTabEntry>REALNUMBER
%token 	<gen>RECORD
%token 	<gen>REPEAT
%token 	<gen>RPAREN
%token 	<gen>SEMICOLON
%token 	<gen>SET
%token 	<gen>SLASH
%token 	<gen>STAR
%token 	<gen>STARSTAR
%token 	<gen>THEN
%token 	<gen>TO
%token 	<gen>TYPE
%token 	<gen>UNTIL
%token 	<gen>UPARROW
%token 	<gen>VAR
%token 	<gen>WHILE
%token 	<gen>WITH
%token  <gen>BOOL

%type <gen>relop
%type <gen>mulop
%type <gen>addop
%type <symTabEntry> num 
%type <symTabEntry> id 
%type <gen> standard_type 
%type <gen> type 
%type <gen> subprogram_head 
%type <gen> arguments
%type <gen> parameter_list
%type <attr> factor
%type <attr> simple_expression
%type <attr> term
%type <symTabEntry> variable
%type <attr> statement
%type <attr> expression
%type <attr> procedure_statement

%%
/* Grammar rules */

program: PROGRAM id LPAREN identifier_list RPAREN semicolon rest
|PROGRAM id LPAREN identifier_list semicolon {yyerror("Error, missing matching paranthesis");} rest
|PROGRAM id identifier_list semicolon {yyerror("Error, missing matching paranthesis");} rest

rest:
declarations
subprogram_declarations
compound_statement
dot

dot:DOT {printf("Parsing Complete!\n");}
|error semicolon {yyerror("Error: . is missing");} 
|semicolon {yyerror("Expected . got ;");}
;

identifier_list: id {symTabEntryList[symTabEntryListIndex++] = $1;}
| identifier_list comma id {symTabEntryList[symTabEntryListIndex++] = $3;}
| {yyerror("Warning, missing identifiers");}

declarations: declarations VAR{isDeclaration = 1;} identifier_list {isDeclaration = 0;} colon  type semicolon {declareId($7);}
| 
;

type: standard_type {$$ = $1;}
| ARRAY LBRAC num DOTDOT num RBRAC OF standard_type {$$ = $8; isArray = 1;lowerBound = atoi($3->data.key);upperBound = atoi($5->data.key);}
;

standard_type: integer {$$=INTEGER;}
| real {$$ = REAL;}
| id {yyerror("Error, invalid type");}
;

subprogram_declarations: subprogram_declarations subprogram_declaration semicolon
|{currentST = 0;totalST++;}
;

subprogram_declaration: subprogram_head semicolon declarations compound_statement
|subprogram_head {yyerror("Missing semicolon");} declarations compound_statement
;

subprogram_head: 
FUNCTION {temp = currentST; currentST = 0;} id {currentST = temp; temp = 0; currentST++;totalST++;} arguments colon standard_type 
{
    $3->data.type = $7;
    $3->data.isFunc = 1;
    // install function signature
    int i;
    $3->data.funcSignature = (int *) malloc(currFuncSign*sizeof(int));
    for(i=0;i<currFuncSign;i++)
    {
		$3->data.funcSignature[i]=functionSignature[i];
    }
    $3->data.numArgs = currFuncSign;
    currFuncSign=0;
} 
| PROCEDURE {temp = currentST; currentST = 0;} id {currentST = temp; temp = 0; currentST++;totalST++;} arguments
{
	//TODO need to decide, but it should not be -1
    $3->data.type = FUNCTION;	
    $3->data.isFunc = 1;
    // install function signature
    int i;
    $3->data.funcSignature = (int *) malloc(currFuncSign*sizeof(int));
    for(i=0;i<currFuncSign;i++)
    {
		$3->data.funcSignature[i]=functionSignature[i];
    }
    $3->data.numArgs = currFuncSign;
    currFuncSign=0;
} 
;

arguments: 
LPAREN parameter_list RPAREN	
|LPAREN error RPAREN {yyerror("Error, malformed/missing arguments");}
|{$$=-1;}
;

parameter_list:
identifier_list colon type {isFunction=1;declareId($3);}
| parameter_list semicolon identifier_list colon type {isFunction=1;declareId($5);}
;

compound_statement:
PBEGIN
optional_statements
END
;

optional_statements:
statement_list
|
;

statement_list:
statement
|statement_list semicolon statement
|statement_list error statement
;

statement:
variable assignop expression {
	if($1->data.type != $3->type)
	{
		yyerror("Type error");
	}
	$$ = (struct Attributes *)malloc(sizeof(struct Attributes));
	strcpy($$->code,$3->code); // s.code = e.code
	char buf[100];
	sprintf(buf,"%s = %s;\n",$1->data.key,$3->place);
	strcat($$->code,buf);
	printf("%s",$$->code);

}
| procedure_statement{$$ = NULL;} 
| compound_statement {$$ = NULL;}
| IF expression THEN statement ELSE statement{
	$$ = (struct Attributes *)malloc(sizeof(struct Attributes));}
| WHILE expression DO statement {$$ = NULL;}
;

variable: 
id  
{ 
    if ($1->data.type == -1)
	    undeclaredID($1->data);
    $$ = $1;
}
| id LBRAC expression RBRAC 
{ 
    
    /*	TODO: if possible check the bounds
    checkBounds($1->data.lowerBound, $1->data.upperBound,
    	0 get the value of the expression here); */
    if ($1->data.type == -1)
    	undeclaredID($1->data);
    else if(!$1->data.isArray)
    {
	    yyerror("Error trying to index a scalar variable");
    }
    //we copy the ST entry of id to variable
    $$ = $1;
}
| id LBRAC num RBRAC
{
    if($3->data.type != INTEGER)
    {
	    yyerror("Error in array index type");
    }
    else if($3->data.type == INTEGER && $3->data.isNum)
    {
	    if($3->data.constVal>$1->data.upperBound||$3->data.constVal<$1->data.lowerBound)
		    yyerror("Bound error");
    }
   
    //we copy the ST entry of id to variable
    $$ = $1;
}

| id LBRAC expression RPAREN 
{ 
    if ($1->data.type == -1)
    	undeclaredID($1->data);
	yyerror("Error, malformed expression");

    //we copy the ST entry of id to variable
    $$ = $1;
}
;

procedure_statement:
id	
{ 
    //TODO: check the function signature
    checkFuncSign($1->data);
    if ($1->data.isFunc == -1) 
    	undeclaredID($1->data);
	$$ = (struct Attributes *)malloc(sizeof(struct Attributes));
	//generate code here
	$$ = NULL; //TODO generate code and remove this

}
| id LPAREN expression_list RPAREN 
{
    ///exprListTypeIndex = 0;	
    //TODO: check the function signature
    checkFuncSign($1->data);
    exprListTypeIndex=0;
    if ($1->data.isFunc == -1)
    	undeclaredID($1->data);
    checkFuncSign($1->data);
	$$ = (struct Attributes *)malloc(sizeof(struct Attributes));
	//generate code here
	$$ = NULL; //TODO generate code and remove this


}
| id LPAREN expression_list semicolon 
{ 
    exprListTypeIndex = 0;	
    if ($1->data.isFunc == -1)
    	undeclaredID($1->data);
	yyerror("Error, unmatched paranthesis");
	$$ = (struct Attributes *)malloc(sizeof(struct Attributes));
	//generate code here
	$$ = NULL; //TODO generate code and remove this

}
;

expression_list:
expression {exprListType[exprListTypeIndex++]=$1->type;}
| expression_list comma expression {exprListType[exprListTypeIndex++]=$3->type;}
| {yyerror("Warning, empty expression");}
;

expression:
simple_expression{
		//$$ = (struct Attributes *)malloc(sizeof(struct Attributes));
		$$ = $1;
}

| simple_expression relop simple_expression{
	$$ = (struct Attributes* ) malloc(sizeof(struct Attributes));
	$$->type = BOOL;
    char buf[100];
    ListNodePtr temp = newTemp();
    strcpy($$->place, temp->data.key);
	sprintf(buf,"%s = %s %s %s;\n",temp->data.key,$1->place,getOperation($2),$3->place);
	strcat($$->code,buf);
}
;

simple_expression:
term {
	//$$ = (struct Attributes *)malloc(sizeof(struct Attributes));
	$$ = $1;
}
| sign term{$$=$2;}
// FIXME: look ^^ is that correct, independent of the sign?

| simple_expression addop term {
	if($1->type != $3->type) yyerror("Type error");
	$$ =(struct Attributes *) malloc(sizeof(struct Attributes));
	//generate code here
	$$->type = $3->type;
	char buf[100];
    ListNodePtr temp = newTemp();
    strcpy($$->place, temp->data.key);
    // Addop will be replaced here
	sprintf(buf,"%s = %s %s %s;\n",temp->data.key,$1->place,getOperation($2),$3->place);
	strcat($$->code,buf);
}
;

term: 
factor {
	//$$ = (struct Attributes *)malloc(sizeof(struct Attributes *));
	$$ = $1;
}
| term mulop factor {
	if($1->type!=$3->type)
		yyerror("Type error");
	$$ = (struct Attributes *)malloc(sizeof(struct Attributes *));
	//generate code here
	$$->type = $3->type;
	char buf[100];
    ListNodePtr temp = newTemp();
    strcpy($$->place, temp->data.key);
    // Addop will be replaced here
	sprintf(buf,"%s = %s %s %s;\n",temp->data.key,$1->place,getOperation($2),$3->place);
	strcat($$->code,buf);
	printf("%s",$$->code);	
}
;

factor:
id  
{ 
    if ($1->data.type == -1)
    	undeclaredID($1->data);
	
	$$ = (struct Attributes *)malloc(sizeof(struct Attributes));
	//generate code here
	strcpy($$->place,$1->data.key);
    $$->type = $1->data.type;
}
| id LPAREN expression_list RPAREN 
{
    //exprListTypeIndex = 0;	
    //TODO: check the function signature
    checkFuncSign($1->data);
    exprListTypeIndex = 0;
    if ($1->data.type == -1 || $1->data.isFunc == -1) 
    	undeclaredID($1->data);
	$$ = (struct Attributes *)malloc(sizeof(struct Attributes));
	//generate code here
    $$->type = $1->data.type;
    
}

| id LPAREN expression_list semicolon 
{ 

    exprListTypeIndex = 0;	
    if ($1->data.type == -1)
    	undeclaredID($1->data);
    yyerror("Unmatched paranthesis");
    //$$=$1->data.type;
	$$ = (struct Attributes *)malloc(sizeof(struct Attributes));
	//generate code here
    $$->type = $1->data.type;

}
| num {
	
	$$ = (struct Attributes *)malloc(sizeof(struct Attributes));
	//generate code here ??????
	strcpy($$->place,$1->data.key);
	$$->type = $1->data.type;
	
}
| LPAREN expression RPAREN {
		$$ = (struct Attributes *)malloc(sizeof(struct Attributes));
		*$$ = *$2;
}
| NOT factor {
		$$ = (struct Attributes *)malloc(sizeof(struct Attributes));
		*$$ = *$2;
}
;

sign:
PLUS
| MINUS
;

addop: 
  PLUS {$$ = PLUS;}
| MINUS {$$ = MINUS;}
| OR {$$ = OR;}
| id {yyerror("Missing operator");}
;

mulop: 
 STAR {$$ = STAR;}
| SLASH {$$ = SLASH;}
| DIV {$$ = DIV;}
| MOD {$$ = MOD;}
| AND {$$ = AND;}
;

assignop: ASSIGNMENT
;

id: IDENTIFIER { $$ = $1; /*bug: $$->data.type=-1;*/}
;

relop:
EQUAL {$$=EQUAL;}
| NOTEQUAL {$$=NOTEQUAL;}
| LT {$$=LT;}
| GT {$$=GT;}
| LE {$$=LE;}
| GE {$$=GE;}
| IN {$$=IN;}
;

comma: COMMA
;

colon: COLON
;

semicolon: SEMICOLON
;

integer: INTEGER
;

real: REAL
;

num: NUMBER {$$=$1;}
| REALNUMBER {$$=$1;}
;

%%
// Declares an identifier
void declareId(int type)
{
	int i;
	for(i = 0;i<symTabEntryListIndex;i++)
	{
		if ( symTabEntryList[i]->data.type != -1  )
		{	// Redeclaration of a variable
			printf("Redeclaration of %s in line No %d, previous declaration at line No %d\n",
				symTabEntryList[i]->data.key,
				lineNo, symTabEntryList[i]->data.lineNo);
			continue;
		}
		symTabEntryList[i]->data.lineNo = lineNo;
		symTabEntryList[i]->data.tableNo = currentST;
		symTabEntryList[i]->data.type = type;
//		printf(" symTabEntry[%d] = %s type=%d ptr=%x ",i,symTabEntryList[i]->data.key,symTabEntryList[i]->data.type,symTabEntryList[i]);
		if(isArray)
		{
			symTabEntryList[i]->data.lowerBound = lowerBound;
			symTabEntryList[i]->data.upperBound = upperBound;
			symTabEntryList[i]->data.isArray = 1;
		}
		else
		{
			symTabEntryList[i]->data.lowerBound = -1;
			symTabEntryList[i]->data.upperBound = -1;
			symTabEntryList[i]->data.isArray = 0;
		}
		if (isFunction)
		{
		    /* install the function signature in the local array */
		    functionSignature[currFuncSign++] = type;
		    if(currFuncSign == MAX_ARGUMENTS)
			printf("Maximum arguments for any function is %d\n", MAX_ARGUMENTS);
		}

	}
	isArray = 0;
	isFunction=0;
	lowerBound = upperBound = -1;
	symTabEntryListIndex = 0;
}

// Prints an Undeclared Identifier error
void undeclaredID(token id)
{
	if(lookup(id.key,0,0)==NULL)
		printf("Line no %d: Undefined variable %s\n",lineNo, id.key); 
}

// Converts type to an enumeration
int getTypeNo(int type)
{
	switch (type)
	{
		case INTEGER: return 0;
		case REAL: return 1;
		case BOOL: return 2;
	}
}

// Check function Signature
void checkFuncSign(token func)
{
	int i;
	char dataTypes[][5] = {"int", "real", "bool"};
	if(func.isFunc && func.type != -1){
	if(func.numArgs!=exprListTypeIndex)
		printf("Line no %d:%d arguments required, %d got.\n", lineNo ,func.numArgs,exprListTypeIndex); }
	if(func.numArgs>0)
	{
		for ( i = 0 ; i < func.numArgs ; i ++ )
		{
			int type1 = getTypeNo(func.funcSignature[i]),type2 = getTypeNo(exprListType[i]);
			if ( func.funcSignature[i] != exprListType[i])
				printf("line no %d: paramenter %d: expected %s but got %d",
					lineNo,i+1, dataTypes[type1], type2);
		}
		putchar('\n');
	}
}

// The main function
int main()
{
	yyparse();
	return 0;
}

/*
 * Returns the ST entry pointer for new local variable 
 * generated by the compiler
 */
struct listNode* newTemp()
{
	static int ctr = 0;
	char *varName = (char *)malloc(SIZE_OF_TEMP);
	//this creates a new variable __ti and increments i
	sprintf(varName,"__t%d",ctr++);
	ListNodePtr lookupToken = lookup(varName,currentST,0);
	if(lookupToken != NULL)
	{
		printf("ERROR, TERMINATING!!!\n");
		exit(0);
	}
	token entry;
	initToken(&entry);
	strcpy(entry.key,varName);
	ListNodePtr entryPtr=insertIntoMap(varName,entry,currentST);
	return entryPtr;
}

char* getOperation(int operation)
{
	switch (operation)
	{
		case EQUAL: return"==";
		case NOTEQUAL: return"!=";
		case LT: return"<";
		case GT: return">";
		case LE: return"<=";
		case GE: return">=";
		case IN: return"??";
		
		case PLUS:return"+";
		case MINUS:return"-";
		case OR:return"|";
		
		case STAR:return"*";
		case DIV:return"/";
		case SLASH:return"\\";
		case MOD:return"%";
		case AND:return"&";
		default: printf("%d",operation);return ("relop");
	}
}

