//Implement a C program in which the main program accepts integers to be sorted and sorts elements using bubble sort.Parent process sorts the integers in ascending order and child process sorts the elements in descending order.
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int *bubbleSort(int *arr){
    int i=0;
    return *arr;
}

int main(){

    int num,*arr,*sorted;
    pid_t pid;

    printf("Enter the no of elements to sort: ");
    scanf("%d",&num);
    printf("Enter the elements to sort: ");
    for(int i=0;i<num;i++){
        scanf("%d",*arr);
        arr++;
    }
    printf("Unsorted Array: ");
    for(int i=0;i<num;i++){
        printf("%d\t",*arr);
        arr++;
    }

    pid = fork();
    
    if(pid==0){
        printf("Child Sort- Descending");
        sorted=bubbleSort(arr);
    }
    return 0;
}