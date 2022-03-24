// Write a C Program to create a child process. 
// The parent process will display the addition and 
// the child process will display the subtaction of two numbers.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){


int a,b,prs,result;
printf("Enter the Value of a: ");
scanf("%d",&a);
printf("Enter the value of b: ");
scanf("%d", &b);

prs = fork();

if (prs == -1)
    printf("Process Failed");
else if (prs == 0){
    printf("\nChild Process: Subtracting two numbers: ");
    result = a - b;
    printf("\nSubtraction of %d and %d is %d",a,b,result);
}
else if (prs > 0){
    printf("\nParent Process: Adding two numbers: ");
    result = a + b;
    printf("\nAddition of %d and %d is %d",a,b,result);
}

}