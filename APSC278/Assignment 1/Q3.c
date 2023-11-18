//Q2_Das_Rishit
#include <stdio.h>
#include <stdlib.h>

//Declaring struct
struct stack{
    
	int top;

	char* array;
};


struct stack* makestack(int max){
    //Allocating memory for stack
	struct stack* st = (struct stack*)malloc(sizeof(struct stack));
	st->top = -1;
	//Allocating memory for array
	st->array = (char*)malloc(max*sizeof(char));
	return st;
}


void push(struct stack* st, char value){
    //increments top index
    st->top++;
    //Pass input value to top 
	st->array[st->top] = value;
}


void pop(struct stack* st){
    
	st->array[st->top] = '0';
    // decrement top index
    st->top--;
}


int main()
{
    //Stores string length
    int n;
    printf("Enter the length of the string: ");
    scanf("%d", &n);

   
    char *string;
    //Allocating memory
    string = (char *)malloc(n * sizeof(char));

    printf("Enter the string:\n");
    scanf("%s", string);
    
    //Assigning last element as null character
    string[n] = '\0';

    
    struct stack* st = makestack(n);

    // Decalring and initializing variable 
    int result = 1;

    
    for(int i=0; i<n; i++){
        // If current element is opening bracket push to stack
        if(string[i] == '(' || string[i] == '{' || string[i] == '['){
            push(st, string[i]);
        }
        else{
            if(st->top == -1){
                result = 0;
                break;
            }
            else if(string[i] == ')' && st->array[st->top] != '('){
                result = 0;
                break;
            }
            else if(string[i] == '}' && st->array[st->top] != '{'){
                result = 0;
                break;
            }
            else if(string[i] == ']' && st->array[st->top] != '['){
                result = 0;
                break;
            }
            else{
                pop(st);
            }
        }
    }

    //Checks if elements still present in stack if true set result to unbalanced
    if(st->top != -1){
        result = 0;
    }

    //Prints output
    printf("Result: %d\n", result);
    if(result == 0){
        printf("Unbalanced Expression");
    }
	else if (result == 1){
        printf("Balanced Expression");
    }
	return 0;
}