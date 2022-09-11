#include "quadroUnitTest.hpp"
#include "quadratic.hpp"

struct DataForUnitTest
{
    double a;
    double b;
    double c;
    int    nRoots; 
    double x1;
    double x2;
};

int RunUnitTest(void)
{
    int fail = 0;

    struct DataForUnitTest arrDataUnitTest[] = {
        {0,  0,   0, INF,     0,  0},
        {0,  0,  -4, NOROOTS, 0,  0}, 
        {0,  2,  -4, 1,       2,  0},
        {2,  2,  -4, 2,       1, -2},
        {1, -2,   0, 2,       0,  2},
        {1, -2, 100, NOROOTS, 1, -2},
        {1, -2,   1, 1,       1, -2}};


    for(int i = 0; i < 7; i++) {

        fail += OneUnitTest(arrDataUnitTest[i], i);
    }

    return fail;
}
 
int OneUnitTest(struct DataForUnitTest oneTest, int i) {

    double x1 = NAN;
    double x2 = NAN;
    
    double a = oneTest.a;
    double b = oneTest.b;
    double c = oneTest.c;
    int    real_nRoots = oneTest.nRoots;
    double real_x1 = oneTest.x1;
    double real_x2 = oneTest.x2; 

    int nRoots = SolveSquare(a, b, c, &x1, &x2);

//переписать if
    if  (( nRoots == real_nRoots)             && 
        (((nRoots == 1) && (x1 == real_x1))   || 
        (  nRoots == INF)                     || 
        (  nRoots == 0)                       || 
        (( nRoots == 2) && ((x1 == real_x1) && (x2 == real_x2)) || ((x2 == real_x1) && (x1 == real_x2))))) {

            return 0;
        }

    printf("Error in test %d nRoots=%d real_nRoots=%d, a=%lf b=%lf, c=%lf\n", 
            i, nRoots, real_nRoots, a, b, c);

    return 1;
}