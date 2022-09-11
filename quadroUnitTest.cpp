#include "quadroUnitTest.hpp"
#include "quadratic.hpp"

struct DataForUnitTest   ///Это можно вынести в header?
{
    double a;
    double b;
    double c;
    int nRoots; 
    double x1;
    double x2;
};

int RunUnitTest(void)
{
    int fail = 0;

    struct DataForUnitTest arrDataUnitTest[]= {0,  0,  0, INF,     0,  0,
                                               0,  0, -4, NOROOTS, 0,  0, 
                                               0,  2, -4, 1,       2,  0,
                                               2,  2, -4, 2,       1, -2,
                                               1, -2,  0, 2,       0,  2,
                                               1, -2,100, NOROOTS, 1, -2,
                                               1, -2,  1, 1,       1, -2};
    

    for(int i = 0; i < 7; i++) {

        fail += OneUnitTest(arrDataUnitTest[i]);
    }
    //return 0;
    return fail;
}
 
int OneUnitTest(struct DataForUnitTest inputStruct) ///обернуть в структуру double a, double b, double c, int real_nRoots, double real_x1, double real_x2 
{
    static int num = 0;
    double x1 = NAN;
    double x2 = NAN;
    
    double a = inputStruct.a;
    double b = inputStruct.b;
    double c = inputStruct.c;
    int real_nRoots = inputStruct.nRoots;
    double real_x1 = inputStruct.x1;
    double real_x2 = inputStruct.x2; 


    int nRoots = SolveSquare(a, b, c, &x1, &x2);

    if( (nRoots == real_nRoots) && (((nRoots == 1) && (x1 == real_x1)) || (nRoots == INF) 
        || (nRoots == 0) || ((nRoots == 2) && ((x1 == real_x1) && (x2 == real_x2)) 
        || ((x2 == real_x1) && (x1 == real_x2))))) {
            num++;

            return 0;
        }

    printf("Error in test %d nRoots=%d real_nRoots=%d, a=%lf b=%lf, c=%lf\n", num, nRoots, real_nRoots, a, b, c);
    num ++;

    return 1;
}