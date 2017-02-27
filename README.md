# lagrangepolynomial
This function is used to generate polynomials by the lagrange method.

**How to use:

You need to add #include "mylagrange.h" in your code.

The function is :
lagrange(long double inputdata[][2],int pointsnum);

-inputdata[][2]:The data you want to be the points  for lagrange polynomial.
 Column 1 is X axis
 Column 2 is y axis
 The largest number of data is 100;
-pointsum:The number of points.

If your input data is correct
You will receive the reply like this:
f(x)=-0.000000x^9+0.000000x^8-0.000000x^7+0.000000x^6-0.000017x^5+0.000552x^4-0.012342x^3+0.277067x^2-0.400424x^1+7.000000x^0

**Notice
The more number of data you enter to the lagrange function,the longer you will wait.
Because of the range of "long double",the larger value and the more number of your data is,the accuracy will be reduced.
According to my experience,the performance with 10 points is still good.
