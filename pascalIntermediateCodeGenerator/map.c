#include "map.h"

/* The hashing function */
int hashjw( char* s)
{
    int i;
    unsigned long int h = 0, g;         // unsigned for 32 bit int will do
    for( i = 0 ; s[i] != '\0' ; i ++ )
    {
        h = (h<<4) + s[i];
        if ( g = h & 0xF000000 ) {
            h = h ^ ( g >> 24 );        // h ^= (g>>24);
            h = h ^ g;                  // h ^= g;
        }
    }
    return ( h % PRIME );
}

/* Insert a new value into the list in sorted order */
ListNodePtr insertNode( ListNodePtr *sPtr, token value )
{
    ListNodePtr newPtr, previousPtr, currentPtr;
    newPtr = malloc( sizeof( ListNode ) );
    if ( newPtr != NULL ) {     /* is space available */
        newPtr->data = value;
        newPtr->nextPtr = NULL;
        previousPtr = NULL;
        currentPtr = *sPtr;

        while ( currentPtr != NULL) {
            previousPtr = currentPtr;          /* walk to ...   */
            currentPtr = currentPtr->nextPtr; /* ... next node */
        }
        if ( previousPtr == NULL ) {
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        }
        else {
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }
    else
        printf( "%s not inserted. No memory available.\n", value.key );

    return newPtr;
}
 /* Delete a list element */
token deleteNode( ListNodePtr *sPtr, token value )
{
    ListNodePtr previousPtr, currentPtr, tempPtr;

    if (strcmp(value.key,(*sPtr)->data.key)) {
        tempPtr = *sPtr;
        *sPtr = ( *sPtr )->nextPtr; /* de-thread the node */
        free( tempPtr );             /* free the de-threaded node */
        return value;
    }
    else {
        previousPtr = *sPtr;
        currentPtr = ( *sPtr )->nextPtr;

        while ( currentPtr != NULL && strcmp(currentPtr->data.key,value.key)!=0 ) {
            previousPtr = currentPtr;          /* walk to ...   */
            currentPtr = currentPtr->nextPtr;  /* ... next node */
        }

        if ( currentPtr != NULL ) {
            tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free( tempPtr );
            return value;
        }
    }

    token temp;
    strcpy(temp.key,"\0");
    return temp;
 }

/* Return 1 if the list is empty, 0 otherwise */
int isEmpty( ListNodePtr sPtr )
{
    return sPtr == NULL;
}

/* Print the list */
void printList( ListNodePtr currentPtr )
{
    if ( currentPtr != NULL )
    {
        while ( currentPtr != NULL ) {
            printf( "%-15s\t%d\n", currentPtr->data.key, currentPtr->data.type);
            currentPtr = currentPtr->nextPtr;
        }
    }
}

ListNodePtr insertIntoMap(char *key,token value, int table)
{
    int index=hashjw(key);
    ListNodePtr *sptr=&symbolTable[index][table];
    ListNodePtr entryPtr=insertNode(sptr,value);
}

/* Checks if the current key is already present in the hash-table */
ListNodePtr lookup(char *key, int tableNo,int mode)
{
    int index=hashjw(key);
    ListNodePtr x=symbolTable[index][tableNo];
    while(x!=NULL)
    {
        if(strcmp(x->data.key,key)==0)
            return x;
        x=x->nextPtr;
    }
    if(tableNo != 0)
    {
        ListNodePtr retFromMainST = lookup(key,0,0);
        if(retFromMainST != NULL)
            return retFromMainST;
    }
    return NULL;
}

/* Initialise a token*/
void initToken(token *tokenInst)
{
    tokenInst->type = -1;
    tokenInst->lowerBound = tokenInst->upperBound = -1;
    tokenInst->isArray = tokenInst->isFunc = -1;
    tokenInst->numArgs = -1;
    tokenInst->lineNo = -1;
}
