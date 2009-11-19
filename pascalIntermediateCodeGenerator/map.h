 #ifndef MAP_H
#define MAP_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// This value is required for the hashing function
#define PRIME 211

// Maximum number of arguments a function can take
#define MAX_ARGUMENTS 100

// Define the maximum number of symbol tables
#define MAX_SYMBOL_TABLES 100

// Define the size of temp required in newTemp() function
#define SIZE_OF_TEMP 30

// A global variable to indicate that we are in a declaration, required in declareID function
int isDeclaration;
// Token structure declaration
struct Token
{
    char key[100];              // The name of the token
    int type;                   // The type of the token
    int isArray;                // 1 if it is an array
    int isFunc ;                // 1 if it is a function
    int isNum;                  // 1 if it is a number else 0
    int constVal;               // 1 if it is a constVal
    int lineNo;                 // lineNo in which the token is declared
    int tableNo;		// tableNo in which the token is declared
    int *funcSignature;         // contains the function signature (if isFunc)
    int numArgs;                 // contains number of arguments (if isFunc)
    int lowerBound;             // contains the lower bound (if isArray )
    int upperBound;             // contains the upper bound (if isArray )
};
typedef struct Token token;

// Linked list structure
struct listNode
{
    token data;
    struct listNode *nextPtr;
};
typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

/// Function declarations

/*
 *  This function randomly maps a string to an integer
 * @params: s is the string, the key
 * @return: returns the integer to which s is mapped
 */
int hashjw( char *s);

/*
 * Initialise a token
 * @param: token pointer which should be initialised
 */
void initToken(token *tokenInst);
/*
 * Insert a token into the list of tokens in sorted order
 * @param: The pointer to the list
 *         The token to be inserted
 * @Return: returns the list
 */
ListNodePtr insertNode( ListNodePtr *, token );
/*
 * Deletes a token from the list
 * @param: The pointer to the list
 *         The token to be inserted
 * @Return: returns the deleted token
 */
token deleteNode( ListNodePtr *, token );

/*
 * Tests if a list is empty
 * @params: The list to be examined
 * @Return: 1 if the list is empty, 0 else
 */
int isEmpty( ListNodePtr );

/*
 * Prints a list
 * @params: The list to be printed
 */
void printList( ListNodePtr );

/*
 * looks up the hash-table for the current string
 * @params: key: is the string to be looked up
 *          tableNo: The table in which lookup has to be performed
 */

ListNodePtr lookup(char *key, int tableNo,int mode);
/*
 * Inserts a token into the symbolTable (array of hash-tables)
 * @params: key - The name of the token for hashing
 *          value - The token to be inserted
 *          tableNo - the table in which it has to be inserted
 */
ListNodePtr insertIntoMap(char *key,token value, int tableNo);

/// Data declarations

// The current symbol table
int currentST;

// The total number of symbol tables
int totalST;

/*
 * The hash-table structure
 * An array of lists
 * Size of the array is a prime number defined above
 */
ListNodePtr symbolTable[PRIME][MAX_SYMBOL_TABLES];

struct Attributes
{
	char code[1000];
	char place[50];
	int type;
};

#endif //MAP_H
