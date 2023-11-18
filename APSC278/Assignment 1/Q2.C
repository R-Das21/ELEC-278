//Q3_Das_Rishit
#include <stdio.h>
int main()
{   
    //Queue of integers
    int queue[10]={10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    
    //Amount of elements to be reversed
    int k=5; 
    
    
    int size = sizeof(queue)/sizeof(queue[0]); 
    
    //Position of last element to be reversed
    int end_index=k-1;
    
    for(int i=0;i<(k-1)/2;i++)
    {
        
        if(i!=end_index)
        {
            //Temp variable to hold element
            int temp = queue[i];
            //Swaps first element with last element within user defined range
            queue[i] = queue[end_index];  
            queue[end_index] = temp;
            //Decrements last element index
            end_index--;
        }
    }
    printf("[");
    printf("Q = ");
    //Prints queue with first k elements reversed
    for(int i=0;i<size;i++)
    {
        if(i==size-1){
         printf("%d",queue[i]);   
        }
        else{
            printf("%d,",queue[i]);
        
    }
    }
    printf("]");
    return 0;
}