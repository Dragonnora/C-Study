/*
 Performs integer multiplication using + operator.
 Pre: m and n are defined and n > 0
 Post: returns m * n
 */
 
#include <stdio.h>
int multiply (int m, int n);
int
main (void)
{
    /* ans = m + multiply(m, n - 1);: In the recursive step, it calculates m + multiply(m, n - 1), 
      which is equivalent to m * n because it's adding m to the result of multiplying m by (n - 1) */ 
      
  int s;
  s = multiply (9, 3);
  printf ("%d", s);
  return 0;
}

int
multiply (int m, int n)
{
  int ans;
  if (n == 1)
    {
      ans = m;			/* simple case */
    }
  else
    {
      ans = m + multiply (m, n - 1);	/* recursive step */
    }
  printf ("%d\n", ans);
  return (ans);
}
