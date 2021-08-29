#include "quadroUnitTest.hpp"
#include "quadratic.hpp"

int RunUnitTest()
{
    int fail = 0;

    if( OneUnitTest( 0,  0,  0, INF,     0,  0) ) fail++;//Test1
    if( OneUnitTest( 0,  0, -4, NOROOTS, 0,  0) ) fail++;//Test2
    if( OneUnitTest( 0,  2, -4, 1,       2,  0) ) fail++;//Test3
    if( OneUnitTest( 2,  2, -4, 2,       1, -2) ) fail++;//Test4
    if( OneUnitTest( 1, -2,  0, 2,       0,  2) ) fail++;//Test5
    if( OneUnitTest( 1, -2,100, NOROOTS, 1, -2) ) fail++;//Test6
    if( OneUnitTest( 1, -2,  1, 1,       1, -2) ) fail++;//Test7

    //return 0;
    return fail;
}
 
int OneUnitTest( double a, double b, double c, int real_nRoots, double real_x1, double real_x2 )
{
    static int num = 1;
    double x1 = NAN;
    double x2 = NAN;
    int nRoots = SolveSquare(a, b, c, &x1, &x2);
    if( (nRoots == real_nRoots) && (((nRoots == 1) && (x1 == real_x1)) || (nRoots == INF) 
        || (nRoots == 0) || ((nRoots == 2) && ((x1 == real_x1) && (x2 == real_x2)) 
        || ((x2 == real_x1) && (x1 == real_x2)))) )
        {
            num++;
            return 0;
        }
    printf("Error in test %d nRoots=%d real_nRoots=%d, a=%lf b=%lf, c=%lf\n", num, nRoots, real_nRoots, a, b, c);
    num ++;
    return 1;
}