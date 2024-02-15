#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
   node* pTmp = head;
    int lengthCount = 0;

    if (pTmp == NULL){
        return lengthCount;
    }

    if (pTmp->next == NULL){
        lengthCount=1;
        return lengthCount;
    }

    while ((pTmp!= NULL) && (pTmp->next !=NULL)){
        pTmp =  pTmp -> next ;
        lengthCount ++;

    }

    return lengthCount;

}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
    int lengthCount = length(head);
    node* pTmp = head;
    int i = 0; //Index

    // DMA space, don't forget to add 1 for the null terminator
    char* fullString = (char*)malloc((lengthCount+1)*sizeof(char));
    
    //Check to see if memory was allocated 
    if (fullString == NULL){
        return NULL;
    }

    //Check to see if pTmp is Null if yes return Null
    if (pTmp == NULL){
        return NULL;
    }

    while (pTmp != NULL){

        fullString[i] =  pTmp->letter;
        pTmp =  pTmp -> next ;
        i++;

    }

    //Add null character
    //fullString[i] = '\0';
    fullString[lengthCount + 1] = '\0';


    return fullString;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
    //Create new node and dynamically allocate memory
    node* newNode = (node*)malloc(sizeof(node));
    node* pTmp = *pHead;

    //Check if memory was allocated property
    if (newNode == NULL){
        return;
    }

    // Initialize the new node
    newNode->letter = c;
    newNode->next = NULL;

    //Check Edge Conditions
    if (pTmp == NULL){
        //Update head so it eqals new node
       *pHead = newNode;    
        return;
    }

    //Tranverse LL
    while (pTmp->next !=NULL){
        pTmp =  pTmp -> next;  
    }

    pTmp->next = newNode;
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
   while(*pHead != NULL){

        node* temp = *pHead;
        *pHead = (*pHead)->next;
        free(temp);
    }
    *pHead = NULL;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}