
#include <stdio.h>

int division(int, int); 

int main()
{

    int x = 18, y = 9; 
    
    int answer = division(x, y); 
    
    printf("%d", answer); 

    return 0;
}

int division(int x, int y){
    
    if (y>x)
        return 1; 
    else if (y==0)
        return 1;
    else if (y==1)
        return (x);
    else
        return division(x-y, y)+1; 
    /* +1 increments the amount that you can subtract y from x. 
     In our example, you can subtract 9 from 18 two times. 
     Therefore, 18/9 = 2 */ 
}
