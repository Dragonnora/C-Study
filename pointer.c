#include <stdio.h>

// prototype
void sum_n_avg(double, double, double, double *, double *); 

int main()
{
    double n1, n2, n3;
    double sum, avg; 
    
    printf("Enter number: "); 
    scanf("%lf", &n1); 
    printf("Enter number: "); 
    scanf("%lf", &n2); 
    printf("Enter number: "); 
    scanf("%lf", &n3);
    
    sum_n_avg(n1, n2, n3, &sum, &avg);
    
    printf("Sum: %lf\n", sum);
    printf("Average: %lf\n", avg); 
    
    return 0;
}

void sum_n_avg(double n1, double n2, double n3, double *sum, double *avg){
    
    *sum = n1 + n2 + n3; 
    *avg = (*sum) / 3; 
