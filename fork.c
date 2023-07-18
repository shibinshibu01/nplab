//Implement a C program in which the main program accepts integers to be sorted and sorts elements using bubble sort.Parent process sorts the integers in ascending order and child process sorts the elements in descending order.
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int bubbleSort(int arr[],int num,pid_t pid){
    
    return 0;
}

int main(){

    int num,arr[100];
    pid_t pid;

    printf("Enter the no of elements to sort: ");
    scanf("%d",&num);
    printf("Enter the elements to sort: ");
    for(int i=0;i<num;i++){
        scanf("%d",&arr[i]);
    }
    printf("Unsorted Array: ");
    for(int i=0;i<num;i++){
        printf("%d\t",arr[i]);
    }

    pid = fork();
    
    if(pid==0){
        printf("\nChild Sort- Descending\n");
        bubbleSort(arr,num);
        for(int i=num-1;i>=0;i--){
            printf("%d\t",arr[i]);
        }
    } else if(pid>1){
        printf("\nParent Sort- Ascending");
        bubbleSort(arr,num);
        for(int i=0;i<num;i++){
            printf("%d\t",arr[i]);
        }
        wait(NULL);
    } else{
        printf("\nFork() failed!");
    }
    return 0;
}